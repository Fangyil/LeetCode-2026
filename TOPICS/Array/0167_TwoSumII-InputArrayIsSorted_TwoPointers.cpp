//Runtime: 0ms, Beats: 100.00%

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i, j;
    int *result = (int*)malloc(sizeof(int) * 2);

    for ( i = numbersSize - 1; i > -1; i--){
        if ( numbers[i] < target || numbers[i] == 0){
            for ( j=0; j < i; j++){
                if ( numbers[j] == target - numbers[i]){
                    *returnSize = 2;
                    result[0] = j+1;
                    result[1] = i+1;
                    return result;
                }
            }
        }
    }

    for ( i=0; i < numbersSize; i++){
        for ( j = i+1; j < numbersSize; j++){
            if ( numbers[i] + numbers[j] == target){
                *returnSize = 2;
                result[0] = i+1;
                result[1] = j+1;
                return result;
            }
        }
    }
    
    return result;
}
