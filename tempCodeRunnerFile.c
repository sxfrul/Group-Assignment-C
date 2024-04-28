for (i = 0; i<100; i++) {
            if (subDuration[i] == 0) {
                break;
            }
            printf("[%d] %s \t(%d days) \t- RM %d\n", i+1, subName[i], subDuration[i], subPrice[i]);
        }