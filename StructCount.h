#pragma once

struct Counter {
    bool solved;
    int count;

    void init()
    {
        solved = false;
        count = 0;
    }
};