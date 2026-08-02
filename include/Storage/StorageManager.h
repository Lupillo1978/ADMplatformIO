#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <Arduino.h>
#include <Preferences.h>
#include "../Models/FeedProgram.h"

class StorageManager
{
public:

    bool begin();

    bool saveProgram(const FeedProgram& program);

    bool loadProgram(FeedProgram& program);

    bool eraseProgram();

    bool programExists();

private:

    Preferences preferences;
};

#endif