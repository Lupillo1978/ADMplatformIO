#ifndef FEEDERSTATE_H
#define FEEDERSTATE_H

enum class FeederState
{
    IDLE,

    START_SPRAYER,

    START_DOSIFIER,

    STOP_DOSIFIER,

    STOP_SPRAYER
};

#endif