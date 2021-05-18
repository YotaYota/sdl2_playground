#ifndef TIMER_H
#define TIMER_H


class Timer
{
    private:
        float deltaTime;
        float lastTime;

    public:
        Timer();
        void tick();
        double getDeltaTime() const;
};

#endif

