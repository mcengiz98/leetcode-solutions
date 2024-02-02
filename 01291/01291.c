/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int generate_num(int key, int len)
{
    int ret = 0;
    for (size_t i = 0; i < len; ++i)
    {
        ret *= 10;
        ret += key;

        if (key == 10)
            return 0;
        key++;
    }
    return ret;
}

int *sequentialDigits(int low, int high, int *returnSize)
{
    char low_s[11];
    sprintf(low_s, "%d", low);
    size_t low_len = strlen(low_s);
    char high_s[11];
    sprintf(high_s, "%d", high);
    size_t high_len = strlen(high_s);

    int *ret = (int *)malloc(sizeof(int) * 40);
    *returnSize = 0;

    int key = low;

    for (size_t i = 1; i < low_len; ++i)
        key /= 10;

    for (size_t i = low_len; i <= high_len;)
    {
        if (key == 9)
        {
            key = 1;
            ++i;
            continue;
        }
        int val = generate_num(key, i);
        if (!val)
        {
            key = 1;
            ++i;

            continue;
        }
        if (val >= low && val <= high)
        {
            ret[(*returnSize)++] = val;
        }
        key++;
    }
    return ret;
}