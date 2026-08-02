#include "Storage/StorageManager.h"

bool StorageManager::begin()
{
    return preferences.begin("feeding", false);
}

bool StorageManager::saveProgram(const FeedProgram& program)
{
    size_t bytesWritten =
        preferences.putBytes(
            "program",
            &program,
            sizeof(FeedProgram)
        );

    return bytesWritten == sizeof(FeedProgram);
}

bool StorageManager::loadProgram(FeedProgram& program)
{
    size_t bytesRead =
        preferences.getBytes(
            "program",
            &program,
            sizeof(FeedProgram)
        );

    return bytesRead == sizeof(FeedProgram);
}

bool StorageManager::eraseProgram()
{
    return preferences.remove("program");
}

bool StorageManager::programExists()
{
    return preferences.isKey("program");
}