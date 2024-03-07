int minimumPushes(char* word) {
    int len = strlen(word);
    int ret = 0;
    int cnt = 1;

    while (len > 0) {
        ret += (len / 8 ? 8 : len % 8) * cnt;
        len -= 8;
        cnt++;
    }

    return ret; 
}