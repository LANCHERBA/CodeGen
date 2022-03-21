#!/bin/bash
#SBATCH --nodes=1
#SBATCH --gres=gpu:2
#SBATCH --ntasks-per-node=32
#SBATCH --mem=127000M
#SBATCH --time=3:00
#SBATCH --account=def-vganesh
nvidia-smi

module load python/3.6 scipy-stack

SOURCEDIR=/home/h6ju/projects/def-vganesh/h6ju/Transcoder/CodeGen

source $SOURCEDIR/newCodeGen/bin/activate

python -m codegen_sources.model.translate --src_lang java --tgt_lang cpp --model_path $SOURCEDIR/TransCoder_model_1.pth --beam_size 1 < $SOURCEDIR/data/Translation\ testing\ 2022-3-16/max+createDirectory/origin-max+createDirectory-java.java

