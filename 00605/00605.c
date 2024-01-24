bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    for (size_t i = 0; i < flowerbedSize; ++i)
    {
        if (n && !flowerbed[i] && (!i || !flowerbed[i - 1]) &&
            (i == (flowerbedSize - 1) || !flowerbed[i + 1]))
        {
            flowerbed[i] = 1;
            n--;
        }
    }

    return n ? false : true;
}