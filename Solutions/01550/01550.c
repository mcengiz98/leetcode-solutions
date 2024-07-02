bool isEven(int num){
    return num%2;
}

bool threeConsecutiveOdds(int* arr, int arrSize) {
    if(arrSize < 3) return false;

    for(size_t i = 1; i < arrSize-1; ++i){
        if(isEven(arr[i-1]) && isEven(arr[i]) && isEven(arr[i+1]))
            return true;
    }

    return false;
}