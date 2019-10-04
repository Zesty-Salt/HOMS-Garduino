#include "Configuration.h"
#include <TimerFreeTone.h>
#include <LiquidCrystal.h>
#include <IRremote.h>

// Library Configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
IRrecv irrecv(IR_Pin);
decode_results results;

// Variables
// IR
enum Key_Codes
{
  Power,
  Volume_Up,
  Func_Stop,
  Rewind,
  Pause_Play,
  Fast_Forward,
  Down,
  Volume_Down,
  Up,
  Num0,
  EQ,
  ST_REPT,
  Num1,
  Num2,
  Num3,
  Num4,
  Num5,
  Num6,
  Num7,
  Num8,
  Num9,
  Null
};
Key_Codes Current_Key = Null;
// Other Variables
int Cycle = 0;
int Slide = 0;
int Selection = 0;

//? Setup Function
/*
 * The setup function is a simple arduino function that
 * is responsible for setting everything up before the 
 * script runs 
 */
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Booting...");

  lcd.createChar(0, Cursor);

  if (Enable_Beep)
    Starter_Tone();

  irrecv.enableIRIn();

  if (Debug)
    Serial.begin(9600);
}

//? Loop Function
/*
 * The loop function is a another simple arduino function
 * that is responsible for housing the main part of the
 * script. The loop function runs infinitely until the
 * arduino device is turned off
 */
void loop()
{
  //? Look for remote input...
  /*
   * This bit of code is responsible for detection input
   * from the remote and decodes it to be used in interactable
   * menus
   */
  if (irrecv.decode(&results))
  {
    Get_Key(results.value);
    irrecv.resume();
  }

  // Wait 1/10 a second for stability
  delay(100);

  //? The Menus
  /*
   * This is one of the biggest If statements in this code!
   * This is responsible for storing the menus used in this
   * script
   */
  if (Current_Key == Pause_Play)
  {
    String Menu[] = {"Data", "Settings", "Overide"};
    Generate_Menu("Main Menu", Menu, 3);
    if (Current_Key == Power)
    {
      Current_Key = Null;
      return;
    }
    if (Selection == 0)
    {
      String Menu[] = {"Moisture", "Brightness", "Light Cycle"};
      Generate_Menu("Data Menu", Menu, 3);
    }
  }


  //? The Cycles
  /*
   * This is responsible for keeping timing of the idle screen.
   * It also shows the tips and tricks while idle!
   */
  Cycle++;
  if (Cycle > 25)
  {
    Cycle = 0;
    if (Slide < 1)
      Slide++;
    else
      Slide = 0;
  }

  //? Idle Screens
  /*
   * These are the messages that appear when the arduino is
   * idling
   */
  lcd.clear();
  if (Slide == 0)
  {
    lcd.print("Welcome to the");
    lcd.setCursor(0, 1);
    lcd.print("HOMS Garduino!");
  }
  if (Slide == 1)
  {
    lcd.print("Press To Begin");
    lcd.setCursor(0, 1);
    lcd.print("Pause/Play");
  }
}

//? IR Decode Array
/*
 * This array of if statements are responsible for
 * decoding the raw signal from the IR remote
 */
int Get_Key(int code)
{ 
  // I really don't want to lable every line here...
  // but this is just comparing existing codes to
  // the code we just got
  if (code == (int)16753245)
    Current_Key = Power;
  if (code == (int)16736925)
    Current_Key = Volume_Up;
  if (code == (int)16769565)
    Current_Key = Func_Stop;
  if (code == (int)16720605)
    Current_Key = Rewind;
  if (code == (int)16712445)
    Current_Key = Pause_Play;
  if (code == (int)16761405)
    Current_Key = Fast_Forward;
  if (code == (int)16769055)
    Current_Key = Down;
  if (code == (int)16754775)
    Current_Key = Volume_Down;
  if (code == (int)16748655)
    Current_Key = Up;

  //if (code ==)
  //    Current_Key = ;
  Click_Tone();
  irrecv.resume();
  return;
}

//? Buzzer Tones
/*
 * These are functions to make the arduino beep, honk,
 * and deter curious students!
 */
void Starter_Tone()
{
  // Make a beep at 700hz for 1/8 of a second
  TimerFreeTone(Buzzer_Pin, 700, 125);
  // wait 3/40 of a second...
  delay(75);
  // Make a beep at 850hz for 1/8 of a second
  TimerFreeTone(Buzzer_Pin, 850, 125);
  // Return to the main script
  return;
}

void Confirmation_Tone()
{
  // Make a beep at 700hz for 1/8 of a second
  TimerFreeTone(Buzzer_Pin, 700, 125);
  // wait 3/40 of a second...
  delay(75);
  // Make a beep at 700hz for 1/8 of a second
  TimerFreeTone(Buzzer_Pin, 700, 125);
  // wait 3/40 of a second...
  delay(75);
  // Make a beep at 700hz for 1/8 of a second
  TimerFreeTone(Buzzer_Pin, 700, 125);
  // Return to the main script
  return;
}

void Click_Tone()
{
  // Make a sort-of-a-click-noise at 1500hz for 3/200 of a second
  TimerFreeTone(Buzzer_Pin, 1500, 15);
  // Return to the main script
  return;
}

//? The Menu Generator
/*
 * This is one of the hardest things I had to do! After around 50 iterations
 * and 4 times starting from scratch, I finally made it work properly!
 */
void Generate_Menu(String Menu_Name, String Menu[], int Menu_Size)
{
  // Declare some variables...
  bool inMenu;
  int Scroll;
  bool Break;

  // Assign those variables some values...
  Scroll = 0;
  inMenu = true;
  Selection = 0;

  // Make a loop for the menu
  while (inMenu)
  {
    // Make sure we don't exit the menu before we get in it!
    Break = false;
    
    // Find out the position of the menu we are on...
    if (Selection == 1 || Selection == 2)
      Scroll = 1;
    else if (Selection == 3 || Selection == 4)
      Scroll = 3;
    else if (Selection == 5 || Selection == 6)
      Scroll = 5;
    else
      Scroll = 0;

    // Clear the LCD display
    lcd.clear();
    
    // If debug mode is enabled, output the cursor position
    if (Debug)
    {
      lcd.setCursor(14, 0);
      lcd.print(Selection);
      lcd.setCursor(0, 0);
    }

    // If we just entered the menu, print the menu title...
    if (Scroll == 0)
    {
      lcd.print(Menu_Name);
      lcd.setCursor(0, 1);
      lcd.print(Menu[0]);

      lcd.setCursor(15, 1);
      lcd.write((byte)0);
    }
    // If not, make the menu without the title
    else
    {
      lcd.print(Menu[Scroll]);
      lcd.setCursor(0, 1);
      lcd.print(Menu[Scroll + 1]);

      // Determine the position of the cursor
      if (Selection == 1 || Selection == 3 || Selection == 5)
      {
        lcd.setCursor(15, 0);
        lcd.write((byte)0);
      }
      else if (Selection == 2 || Selection == 4 || Selection == 5)
      {
        lcd.setCursor(15, 1);
        lcd.write((byte)0);
      }
    }
    while (!Break)
    {
      // Look for remote input...
      if (irrecv.decode(&results))
      {
        // Get the key that was pressed
        Get_Key(results.value);
        irrecv.resume();

        if (Current_Key == Pause_Play)
        {
          Current_Key = Null;
          return;
        }

        if (Current_Key == Down && Selection < Menu_Size - 1)
          Selection++;
        if (Current_Key == Up && Selection > 0)
          Selection--;

        if (Current_Key == Power)
          return;

        Break = true;
      }
      delay(15);
    }
  }
}
