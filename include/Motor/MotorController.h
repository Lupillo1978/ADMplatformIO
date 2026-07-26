#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController
{
public:

    bool initialize();

    void update();

    void startDosificador();

    void stopDosificador();

    void startAspersor();

    void stopAspersor();

    void stopAll();

    bool isDosificadorRunning() const;

    bool isAspersorRunning() const;

private:

    bool dosificadorRunning = false;

    bool aspersorRunning = false;

};

#endif