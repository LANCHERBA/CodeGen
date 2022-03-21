int maxLen(int arr[], int n){
    unordered_map<int, int> hM;
    int sum = 0;
    int max_len = 0;
    int ending_index = - 1;
    for(int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            max_len = i + 1;
            ending_index = i;
        }
        if(hM.find(sum + n) != hM.end()){
            if(max_len < i - hM[sum + n]){
            max_len = i - hM[sum + n];
            ending_index = i;
            }
        }
        else hM[sum + n] = i;
    }
    for(int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;
    printf("%d to %d\n",
        ending_index - max_len + 1,
        ending_index);
    return max_len;
}

