#include <vector>
#include "esp_timer.h"


class Timer
{
    private:
    esp_timer_create_args_t periodic_timer_args;
    esp_timer_handle_t periodic_timer;
    std::vector<void (*)()> Functions;
    std::vector<void (LED::*)()> FunctionsLED; // vector of member function pointers
    int Period_us;
    int NbFonction;

    
void Class_periodic_timer_callback(void *);
static void timerCallback(void* arg);
    public:
    Timer(int period_us);
    void Configure();
    void Configure_Start();
    void Start();
    void Stop();
    void AddNewFonct(void (*func)());
    void CallFunctions();
    


};