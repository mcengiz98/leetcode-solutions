char* customSortString(char* order, char* s) {
    int* hash = (int*)calloc(27, sizeof(int));
    int len = strlen(s);

    for (size_t i = 0; i < len; ++i)
        hash[s[i] - 'a']++;

    int pos = 0;
    for (size_t i = 0; i < strlen(order); i++) {
        while (hash[order[i] - 'a']-- > 0) {
            s[pos] = order[i];
            pos++;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        while (hash[c - 'a']-- > 0)
            s[pos++] = c;
    }

    free(hash);
    return s;
}