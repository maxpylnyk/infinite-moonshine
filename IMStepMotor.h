#ifndef IM_STEP_MOTOR_H
#define IM_STEP_MOTOR_H

#include "stdint.h"
#include "Arduino.h"

class IMStepMotor {
  private:
    static const uint8_t pinsCount = 4;
    static const uint8_t adjStep = 1;
    static const uint8_t seqSize = 8;
    static const uint8_t roundsPerMinute = 11; //[6, 18]
    static const int16_t stepsPerRound = 4096;
    static const int32_t minPosition = 0;
    static const int32_t maxPosition = 2147483647;
    static const unsigned long minuteUS = 60000000;
    static const unsigned long pauseUS = -1.6 * roundsPerMinute + minuteUS / ((unsigned long) stepsPerRound * roundsPerMinute);
    uint8_t seqCounter;
    uint8_t pins[pinsCount];
    uint8_t pattern[pinsCount];
    int32_t currentPosition;
    int32_t targetPosition;
    unsigned long lastStepTime;

    bool setTargetPosition(int32_t position);
    bool setCurrentPosition(int32_t position);
    int32_t mlToSteps(int32_t mlH);
    int32_t stepsToMl(int32_t steps);
    void move();

  public:
    IMStepMotor(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);

    static unsigned long getPauseUS();
    bool increase();
    bool decrease();
    bool onPosition();
    bool zeroPosition();
    int32_t getCurrentPosition();
    int32_t getTargetPosition();
    bool setFlow(int32_t mlH);
    int32_t getFlow();
    void loop();

};

#endif