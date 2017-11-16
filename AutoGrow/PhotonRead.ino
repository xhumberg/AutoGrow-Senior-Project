#include "pinDefinitions.h"



void setupPhotonRead() {
}

void loopPhotonRead() {
  delay(1000);
  //Serial1.println("BOOPY BOOP BOOP");
  
  // 1 = light on 0 = light off
  if (HOUR >= 8 && HOUR < 20)
  {
    digitalWrite(GROW_LIGHT, HIGH);
    //  Serial.println("LIGHT ON"); //print the value to serial port
  }
  else
  {
    digitalWrite(GROW_LIGHT, LOW);
    //Serial.println("LIGHT OFF"); //print the value to serial port
  }

  while (Serial1.available())
  {
    if (readBufOffset < READ_BUF_SIZE)
    {
      char c = Serial1.read();
      if (c != '\n')
      {
        readBuf[readBufOffset++] = c;
      }

      //Reach the end of line
      else
      {
        readBuf[readBufOffset] = 0;
        String buf2string(readBuf);
        Serial.println(buf2string);
        String HOURT(readBuf[0]);
        String HOURO(readBuf[1]);
        String SHOUR = HOURT + HOURO;
        HOUR = SHOUR.toInt();

        String MINT(readBuf[2]);
        String MINO(readBuf[3]);
        String SMIN = MINT + MINO;
        MIN = SMIN.toInt();
        //Serial.print("HOUR: ");
        //Serial.print(HOUR);
        //Serial.print("\nMIN: ");
        //Serial.print(MIN);
        //Serial.print("\n");

        readBufOffset = 0;
      }
    }
    else
    {
      readBufOffset = 0;
    }
  }
}

