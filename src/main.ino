/*
Author: Mohd Aman Ansari
embed
https://embed.org.in
*/
#include <Arduino_FreeRTOS.h>
#define RED    6    //PIN of LED Red
#define YELLOW 7    //PIN of LED Green
#define BLUE   8    //PIN of LED White


typedef int TaskProfiler;   //Profiler for debugging purpose to see whether each "task or thread" working properly in a serial monitor

TaskProfiler RedLEDProfiler;
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

// the setup function runs once when you press reset or power the board
void setup()

{
     // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    // Now set up two tasks to run independently.
    xTaskCreate(redLedControllerTask, "RED LED Task", 128, NULL, 1, NULL);
    xTaskCreate(yellowLedControllerTask, "YELLOW LED Task", 128, NULL, 1, NULL);
    xTaskCreate(blueLedControllerTask, "BLUE LED Task", 128, NULL, 1, NULL);
}

// Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.


void loop()

{
 // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/


void redLedControllerTask(void *pvParameters)   // This is a task.
{
    // initialize digital LED "RED" on pin 6 as an output.
    pinMode(RED, OUTPUT);
    while (1)
    {
        RedLEDProfiler++;
        Serial.print("RedLEDProfiler : ");
        Serial.println(RedLEDProfiler);

        //digitalWrite(RED, digitalRead(RED)^1);   // turn the LED on (HIGH is the voltage level)
        delay(100);    // wait for 1ms
    }
    

}

void yellowLedControllerTask(void *pvParameters)   // This is a task.
{
    // initialize digital LED "YELLOW" on pin 7 as an output.
    pinMode(YELLOW, OUTPUT);
    while (1)
    {
        YellowLEDProfiler++;
        Serial.print("YellowLEDProfiler : ");
        Serial.println(YellowLEDProfiler);

        //digitalWrite(YELLOW, digitalRead(YELLOW)^1);    // turn the LED on (HIGH is the voltage level)
        delay(100);      // wait for 1ms
    }
    

}
void blueLedControllerTask(void *pvParameters)    // This is a task.
{   
    // initialize digital LED "BLUE" on pin 8 as an output.
    pinMode(BLUE, OUTPUT);
    while (1)
    {
        BlueLEDProfiler++;
        Serial.print("BlueLEDProfiler : ");
        Serial.println(BlueLEDProfiler);

        //digitalWrite(BLUE, digitalRead(BLUE)^1);     // turn the LED on (HIGH is the voltage level)
        delay(100);    // wait for 1ms
    }
    

}


