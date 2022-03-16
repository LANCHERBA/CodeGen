public static int maxLen(int arr[], int n){
    HashMap<Integer, Integer> hM = new HashMap<Integer, Integer>();
    int sum = 0;
    int maxLen = 0;
    int endingIndex = - 1;
    for(int i = 0; i < n; i++){
        arr[i] = (arr[i] == 0) ? - 1 : 1;
    }
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            maxLen = i + 1;
            endingIndex = i;
        }
        if(hM.containsKey(sum + n)){
            if(maxLen < i - hM.get(sum + n)){
                maxLen = i - hM.get(sum + n);
                endingIndex = i;
            }
        }else{
            hM.put(sum + n, i);
        }
    }
    for(int i = 0; i < n; i ++){
        arr[i] = (arr[i] == -1) ? 0 : 1;
    }
    System.out.println(endingIndex - maxLen + 1 + " to " + endingIndex);
    return maxLen;
}

public static Set<Integer> uniqueElements(Collection<Integer> l){
    return new HashSet<Integer>(l);
}

public static List<Integer> squareList(List<Integer> l){
    List<Integer> result = new ArrayList<>();
    for(Integer elmt : l) result.add(elmt*elmt);
    return result;
}