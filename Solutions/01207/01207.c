bool uniqueOccurrences(int *arr, int arrSize)
{
    int arr_count[2001] = {0};
    for (size_t i = 0; i < arrSize; ++i)
        arr_count[arr[i] + 1000]++;
    int count_occ[1001] = {0};

    for (size_t i = 0; i < 2001; ++i)
        count_occ[arr_count[i]]++;

    for (size_t i = 1; i < 1001; ++i)
        if (count_occ[i] > 1)
            return false;

    return true;
}
