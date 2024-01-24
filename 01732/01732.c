int largestAltitude(int *gain, int gainSize)
{
    int max = 0;
    int curr = 0;

    for (size_t i = 0; i < gainSize; ++i)
    {
        curr += gain[i];
        max = (curr > max) ? curr : max;
    }
    return max;
}