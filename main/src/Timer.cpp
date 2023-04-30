#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "LED.h"
#include "Timer.h"
#include <vector>
#include "esp_timer.h"

//private
void Timer::Class_periodic_timer_callback(void* arg)
{
    Timer* timer = static_cast<Timer*>(arg);
    timer->CallFunctions(); // call all the functions in the vector
}

Timer::Timer(int period_us)
{
    esp_timer_create_args_t Periodic_timer_args = {
            .callback = &timerCallback,
            .arg = this,
            .dispatch_method = ESP_TIMER_TASK,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodic"
    };
    periodic_timer_args = Periodic_timer_args;
    Period_us = period_us;
}

void Timer::Configure()
{
    esp_timer_create(&periodic_timer_args, &periodic_timer);
}

void Timer::Configure_Start()
{
    Configure();
    Start();
}

void Timer::Start()
{
    esp_timer_start_periodic(periodic_timer, Period_us);
}

void Timer::Stop()
{
    esp_timer_stop(periodic_timer);
}


void Timer::AddNewFonct(void (*func)())
{
    Functions.push_back(func);
}

void Timer::CallFunctions()
{
    for (auto& func : Functions) {
        func(); // call each function in the vector
    }
}

// static callback function that redirects to the member function
void Timer::timerCallback(void* arg)
{
    Timer* timer = static_cast<Timer*>(arg);
    timer->Class_periodic_timer_callback(arg);
}
