#define OP_MOVE_PARENT "../"
#define OP_REMAIN "./"

int minOperations(char** logs, int logsSize) {
    int ret = 0;

    for (size_t i = 0; i < logsSize; ++i) {
        if (!strcmp(OP_MOVE_PARENT, logs[i]))
            ret -= ret > 0 ? 1 : 0;
        else if (!strcmp(OP_REMAIN, logs[i]))
            continue;
        else
            ret++;
    }

    return ret;
}