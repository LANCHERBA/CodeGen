#!/bin/bash
#SBATCH --nodes=1
#SBATCH --gres=gpu:2
#SBATCH --ntasks-per-node=32
#SBATCH --mem=127000M
#SBATCH --time=0-10:00
#SBATCH --account=def-vganesh
nvidia-smi

module load python/3.6 scipy-stack

SOURCEDIR=/home/h6ju/projects/def-vganesh/h6ju/Transcoder/CodeGen

MODEL=/home/h6ju/projects/def-vganesh/h6ju/Transcoder/CodeGen/TransCoder_model_1.pth

source $SOURCEDIR/newCodeGen/bin/activate

python codegen_sources/model/train.py \
--exp_name transcoder_eval \
--dump_path '/home/h6ju/projects/def-vganesh/h6ju/Transcoder/CodeGen/new_dump' \
--data_path '/home/h6ju/projects/def-vganesh/h6ju/Transcoder/CodeGen/data/transcoder_evaluation_gfg' \
--bt_steps 'python_sa-java_sa-python_sa,java_sa-python_sa-java_sa,python_sa-cpp_sa-python_sa,java_sa-cpp_sa-java_sa,cpp_sa-python_sa-cpp_sa,cpp_sa-java_sa-cpp_sa'    \
--encoder_only False \
--n_layers 0  \
--n_layers_encoder 6  \
--n_layers_decoder 6 \
--emb_dim 1024  \
--n_heads 8  \
--lgs 'cpp_sa-java_sa-python_sa'  \
--max_vocab 64000 \
--gelu_activation false \
--roberta_mode false  \
--amp 2  \
--fp16 true  \
--tokens_per_batch 3000  \
--max_batch_size 128 \
--eval_bleu true \
--eval_computation true \
--has_sentence_ids "valid|para,test|para" \
--generate_hypothesis true \
--save_periodic 1 \
--reload_model "$MODEL,$MODEL" \
--reload_encoder_for_decoder false \
--eval_only true \
--n_sentences_eval 1500

