double averageWaitingTime(int** customers, int customersSize,
                          int* customersColSize) {
    long long time = 0;
    long long avg = 0;
    double ret = 0.0;
    for (size_t i = 0; i < customersSize; ++i) {
        time = customers[i][0] > time ? customers[i][0] : time;
        time += customers[i][1];
        avg += time - customers[i][0];
    }

    ret = avg / (customersSize * 1.0);

    return ret;
}