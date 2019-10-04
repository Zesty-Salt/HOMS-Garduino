/* #region [ rgba(255, 255, 0, 0.05) ]
 *  Configuration stuff...
 *      Still under construction!

 *      Pinout labeled "NotDetermined" because lack of access to resources...

 *      PLEASE PROCEDE WITH CAUTION!!
 *          Altering this file could dramatically change the functionality
 *          of the HOMS Garduino!
 *          Those with lack of experience and/or want to be safe, please
 *          Refrain from modifying the Advanced Settings!
 * #endregion 
 */

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Pinout of bed
//const int Moisture_Sensor_Bed1 = NotDetermined;
//const int Moisture_Sensor_Bed2 = NotDetermined;
//const int Moisture_Sensor_Bed3 = NotDetermined;
//const int Moisture_Sensor_Bed4 = NotDetermined;
//const int Light_Sensor = NotDetermined;

// Pinout of watering system
//const int Relay_Bed1 = NotDetermined;
//const int Relay_Bed2 = NotDetermined;
//const int Relay_Bed3 = NotDetermined;
//const int Relay_Bed4 = NotDetermined;

// >> Pinout of anything else... <<
const int IR_Pin = 7;
const int Buzzer_Pin = 6;

// // // Standard Settings // // //

// >> Interface <<
const bool Blink_Cursor = true;
/* Blink Cursor Description:
 *     When enabled, the cursor will blink during certain dialog.
 */
const bool Enable_Beep = true;
/* Enable Beep Description:
 *     When enabled, the piezo buzzer will beep during certain dialog.
 */
const bool Enable_Sleep = true;
/* Sleep Mode Description:
 *     During Sleep Mode, the display is turned off and interface devices
 *     such as the piezo buzzer will be disabled. Additionally, you can set a
 *     schedule for this to happen or run it off timer. HOMS Garduino is
 *     awoken from sleep mode by pressing any key on the IR remote.
   
 * KEEP NOTE!!
 *     During Sleep Mode, processes like watering and sensor data recording will
 *     not be stopped! to disable these functions, you must navigate through the menu
 *     or  disable the system by disconnectiong power.
 */
const bool Sleep_On_Schedule = false;
/* Sleep Mode On Schedule Decription:
 *     When enabled, the user will be prompted to enter time apon powering on.
 *     Can also use brightness from sun to determine time. If in sleep mode and 
 *     awakened during schedule, Sleep Mode will resume when timer reaches 
 *     "Duration_Before_Sleep."
 */
const int Duration_Before_Sleep = 5; // 5 Minutes before sleep mode
/* Duration Before Sleep Description:
 *     When enabled, when idling, the timer will count until it reaches target and
 *     enter Sleep Mode.
 */

// >> Testing <<
bool Debug = true;
/* Debug Description:
 *     When enabled, the user is prompted to plug USB into supported devices apon
 *     powering on.
 */

// // // Advanced Settings // // //

// Icons
byte Cursor[8] = {
    0b00000,
    0b00000,
    0b01000,
    0b10000,
    0b11111,
    0b10000,
    0b01000,
    0b00000};