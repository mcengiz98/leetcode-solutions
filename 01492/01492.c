int kthFactor(int n, int k)
{
    if (k == 0)
        return -1;
    if (k == 1 && n > 0)
        return 1;
    if (k == 1 && n <= 0)
        return -1;

    int cnt = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        cnt += (n % i == 0);
        if (cnt == k)
        {
            return i;
        }
    }

    return -1;
}