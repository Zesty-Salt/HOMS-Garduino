/* ~ ~ ~ ~ ~ Important variables! ~ ~ ~ ~ ~

  Modify these variables,
  using inacturite sources
  can damage the plants or the
  project!

  Modify these at your owen risk!
*/

// Timers
const long interval_check = 3600000; // Interval of checking moisture levels
const long interval_tabChg = 5000;

// Thresholds
int lower_moisture = 200; // wet
int perfect_moisture = 360;
int upper_moisture = 450; // dry

// Burst delay
int length_of_burst = 2500;       // 2.5 seconds
int delay_between_bursts = 10000; // 10 seconds

int delay_between_trials = 500; // 0.5 seconds

// Sensor Pin outputs
#define moisture_bed1 A1
#define moisture_bed2 A2
#define moisture_bed3 A3
#define moisture_bed4 A4

#define temperature_bed1 A5
#define temperature_bed2 A6
#define temperature_bed3 A7
#define temperature_bed4 A8

#define light_bed1 A9
#define light_bed2 A10
#define light_bed3 A11
#define light_bed4 A12

// Utilities
#define relay_bed1 34
#define relay_bed2 35
#define relay_bed3 36
#define relay_bed4 37

#define buzzer A0

/* ~ ~ ~ End of important variables ~ ~ ~  */

String key_code;

int delay_refresh = 1500;

// LCD custom characters
/*
byte name[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
*/

byte Temperature[8] = {
    0b01110,
    0b01010,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b01110,
    0b00000};
byte Moisture[8] = {
    0b00100,
    0b00100,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b01110,
    0b00000};
byte Brightness[8] = {
    0b10101,
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    0b10101,
    0b00000};
byte Down[8] = {
    0b01110,
    0b01010,
    0b01010,
    0b01010,
    0b10001,
    0b01010,
    0b00100,
    0b00000};
byte Up[8] = {
    0b00100,
    0b01010,
    0b10001,
    0b01010,
    0b01010,
    0b01010,
    0b01110,
    0b00000};
