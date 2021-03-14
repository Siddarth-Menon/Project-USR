# Project-USR

## Softwares / Applications used:

1. Arduino IDE
2. Thingspeak web app
3. Realterm (For testing)

## Hardware used:

1. Arduino Mega 2560
2. NodeMCU ESP8266
3. MQ-135 sensor (GAS sensor)
4. NPN inductive proximity sensor
5. LM35 (Temperature sensor)
6. HC-SR04 sensor (Ultrasonic Sensor) 
7. 4 Channel relay module
8. Four 12 volt DC motors
9. 1 metal chassy and 4 wheels

## Working:

- It is basically an IoT based Autonomous Vehicle which works using I2C protocol and can be used during wartime to get real time data about dangerous mines, poisonous gases and temperature levels of the enemy territory via WiFi.
- Here the Arduino Mega 2560 is configured as the Slave I2C device. The sensors are connected to it and the arduino sends the sensor data to the NodeMCU ESP8266 via I2C.
- The NodeMCU ESP8266 is configured as the Master I2C device. It fetches the data sent by the Arduino Mega 2560 via I2C and sends them to the ThingSpeak API via the internet.(NodeMCU is connected to a WiFi network always).
-  MQ-135 is used for monitoring the quality of the air (Poisonous or clean), NPN inductive proximity sensor is basically a proximity metal detector and is used to detect mines (if the value is above 1000, there are no mines close to the vehicle but if the value is below 400, then a mine is detected), the LM35 sensor is used to measure the temperature levels. 
-  The HC-SR04 Ultrasonic sensor which is used for measuring the distance between it and an object is used to make the vehicle autonomous i.e the vehicle stops moving forward when there is an obstacle or enemy in front of it, we have set the threshold value to 5 cms but it can be modified. (LIDAR sensor can also be used but to keep the cost low we have used HC-SR04)
-  The relay module is used for providing external power supply to the 12 volt dc motors and to control the motors using the arduino.
-  The thinspeak web app plots all the sensor data in the form of graphs in 4 seperate fields (one for each sensor), so that the user can visulaize everything. (NOTE: The refresh rate for thingspeak API is 15 seconds).

NOTE: An external RF camera can be attached to the vehicle to get real time video footage, but we have not used it here to keep the cost low.
