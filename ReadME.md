
# Debugging Code Using Profiler in Arduino FreeRTOS

RTOS is designed to provide a predictable execution mode. When the processing must meet the time limit of the system, RTOS is used. Therefore, compared with GPOS (General Purpose Operating System), RTOS is usually light in weight and small in size, and generally only provides functions required to run specific types of applications on specific hardware. FreeRTOS is a class of RTOS that is designed to be small enough to run on a microcontroller – although its use is not limited to microcontroller applications. FreeRTOS includes a kernel and a growing set of software libraries suitable for use across industry sectors and applications. Debugging the code using Profiler to see whether each "task or thread" working properly in a serial monitor.





## Components Used

### Hardware

1. Arduino NANO
2. LEDs
3. Wires & Breadboard
4. Power Supply 

### Software

1. VS Code (Arduino IDE Extension)



## Schematic 

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Debugging%20code%20using%20Profiler%20in%20Arduino%20FreeRTOS%2Fsch1.PNG?alt=media&token=f56f4efd-b9f0-4879-918f-3c768b74dbbb"></img>

## Result

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Debugging%20code%20using%20Profiler%20in%20Arduino%20FreeRTOS%2Fim1.jpg?alt=media&token=9ecc2864-f9ae-4ede-a75d-7f3d4b6fd0b4"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Debugging%20code%20using%20Profiler%20in%20Arduino%20FreeRTOS%2Fimg2.jpg?alt=media&token=da0f9eba-e129-456b-ab43-bbf7066ad068"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Debugging%20code%20using%20Profiler%20in%20Arduino%20FreeRTOS%2Fimg3.PNG?alt=media&token=3ed39690-483e-48d1-97f6-870ef94b7de6"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Debugging%20code%20using%20Profiler%20in%20Arduino%20FreeRTOS%2Fimg4.PNG?alt=media&token=d66dff1a-9ade-4daa-a76e-62ac72de349d"></img>

## Code 

```javascript
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


