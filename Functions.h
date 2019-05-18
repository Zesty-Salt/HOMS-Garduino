#include <IRremote.h>
#include <LiquidCrystal.h>
#include "Variables.h"

IRrecv irrecv(23);
IRsend irsend;
decode_results results;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int return_button(long unsigned int code)
{
  bool on_display = false;
  bool data_hex = false;

  if (on_display)
  {
    lcd.clear();
    lcd.print("Remote Button:");
    lcd.setCursor(0, 1);
  }

  if (code == 16753245)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Power");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Pwr";
    return;
  }
  else if (code == 16736925)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Volume Up");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Vup";
    return;
  }
  else if (code == 16769565)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Func / Stop");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "F/S";
    return;
  }
  else if (code == 16720605)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Rewind");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Rew";
    return;
  }
  else if (code == 16712445)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Pause / Resume");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "P/R";
    return;
  }
  else if (code == 16761405)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Skip");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Skp";
    return;
  }
  else if (code == 16769055)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Down");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Dwn";
    return;
  }
  else if (code == 16754775)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Volume Down");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Vdn";
    return;
  }
  else if (code == 16748655)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Up");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Up";
    return;
  }
  else if (code == 16738455)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 0");
      if (data_hex)
        lcd.print(code);
      delay(250);
      key_code = "Nm0";
      return;
    }
  }
  else if (code == 16750695)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Equalizer");
      if (data_hex)
        lcd.print(code);
      delay(250);
      key_code = "Equ";
      return;
    }
  }
  else if (code == 16756815)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Station / Repeat");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "S/R";
    return;
  }
  else if (code == 16724175)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 1");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm1";
    return;
  }
  else if (code == 16718055)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 2");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm2";
    return;
  }
  else if (code == 16743045)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 3");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm3";
    return;
  }
  else if (code == 16716015)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 4");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm4";
    return;
  }
  else if (code == 16726215)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 5");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm5";
    return;
  }
  else if (code == 16734885)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 6");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm6";
    return;
  }
  else if (code == 16728765)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 7");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm7";
    return;
  }
  else if (code == 16730805)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 8");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm8";
    return;
  }
  else if (code == 16732845)
  {
    if (on_display)
    {
      if (!data_hex)
        lcd.print("Number 9");
      if (data_hex)
        lcd.print(code);
      delay(250);
    }
    key_code = "Nm9";
    return;
  }
  else
  {
    if (on_display)
    {
      lcd.print("ERROR: ");
      lcd.print(code);
    }
    key_code = "Err";
    return;
  }
}

int water_bed(int bed_number)
{
  key_code = "";
  bool burst_mode;

  lcd.clear();
  //         ================
  lcd.print("Enable burst");
  lcd.setCursor(0, 1);
  lcd.print("mode? 1 or 0");

  while (1)
  {
    if (irrecv.decode(&results))
    {
      return_button(results.value);
      irrecv.resume();
      delay(250);
    }

    if (key_code == "Pwr")
      return;

    if (key_code == "Nm0")
    {
      burst_mode = false;
      break;
    }
    if (key_code == "Nm1")
    {
      burst_mode = true;
      break;
    }
  }

  lcd.clear();
  lcd.print("Watering bed #");
  lcd.print(bed_number);

  if (burst_mode)
  {

    bool done = false;
    while (1)
    {
      int trial1;
      int trial2;
      int trial3;
      int trial4;
      int trial5;

      switch (bed_number)
      {
      case 1:

        trial1 = analogRead(moisture_bed2);
        lcd.clear();
        lcd.print("Reading 1:");
        lcd.setCursor(0, 1);
        lcd.print(trial1);
        delay(delay_between_trials);

        trial2 = analogRead(moisture_bed2);
        lcd.clear();
        lcd.print("Reading 2:");
        lcd.setCursor(0, 1);
        lcd.print(trial2);
        delay(delay_between_trials);

        trial3 = analogRead(moisture_bed2);
        lcd.clear();
        lcd.print("Reading 3:");
        lcd.setCursor(0, 1);
        lcd.print(trial3);
        delay(delay_between_trials);

        trial4 = analogRead(moisture_bed2);
        lcd.clear();
        lcd.print("Reading 4:");
        lcd.setCursor(0, 1);
        lcd.print(trial4);
        delay(delay_between_trials);

        trial5 = analogRead(moisture_bed1);
        lcd.clear();
        lcd.print("Reading 5:");
        lcd.setCursor(0, 1);
        lcd.print(trial5);
        delay(delay_between_trials);
        done = true;
        break;
      case 3:
        break;
      case 4:
        break;
      }

      if (done)
      {
        done = false;

        int average = trial1 + trial2 + trial3 + trial4 + trial5;
        average = average / 5;

        if (average > perfect_moisture)
        {
          lcd.clear();
          lcd.print("Still Dry!!");
          lcd.setCursor(0, 1);
          lcd.print(average);
          delay(2500);

          lcd.setCursor(0, 1);
          lcd.print("Watering");
          int delay_ = delay_between_bursts / 3;

          digitalWrite(relay_bed1, LOW);

          lcd.print(".");
          delay(delay_);

          lcd.print(".");
          delay(delay_);

          lcd.print(".");
          delay(delay_);

          lcd.print(" Done!");
          digitalWrite(relay_bed1, HIGH);
          delay(2500);

          lcd.clear();
          lcd.print("Checking Bed");
          lcd.setCursor(0, 1);
          lcd.print("...");

          delay(2500);
        }
        else if (average > lower_moisture && average < upper_moisture)
        {
          lcd.clear();
          lcd.print("Just Right!");
          lcd.setCursor(0, 1);
          lcd.print(average);
          delay(2500);
          key_code = "Pwr";
          return;
        }
        else if (average > perfect_moisture)
        {
          lcd.clear();
          lcd.print("Too Wet!");
          lcd.setCursor(0, 1);
          lcd.print(average);
          delay(2500);
          key_code = "Pwr";
          return;
        }
        else
        {
          lcd.clear();
          lcd.print("Reading Avg:");
          lcd.setCursor(0, 1);
          lcd.print(average);

          delay(2500);

          //         ================
          lcd.clear();
          lcd.print("OH NOOO! ERROR:");
          lcd.setCursor(0, 1);
          lcd.print("Unknown...");

          delay(2500);
        }
      }
    }
  }
}
