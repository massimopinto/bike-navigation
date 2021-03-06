/*
 * Copyright (c) 2015 HERE Global B.V. and its affiliate(s).
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/* Matrix dimensions */
const int MATRIX_HEIGHT = 7;
const int MATRIX_WIDTH = 7;

/* The structure stores data related to each icon to be shown on the LED matrix
   Instances of this structure are populated automatically with code-generation python script */
struct Icon
{
    Icon(int fNum, const char * fPtr, bool doubleSpeedFlag = false)
    : framesNum( fNum )
    , frames(fPtr)
    , doubleSpeed(doubleSpeedFlag)
    {}

    int framesNum;
    const char * frames;
    bool doubleSpeed;
    char getRow(int frameNum, int rowNum) const
    {
      return *(frames + frameNum * MATRIX_HEIGHT + rowNum);
    }
};

/* Constants with icon codes offsets */
const int MANEUVER_CODES_START = 0;
const int MANEUVER_DISTANCE_CODES_START = 20;
const int HEADING_CODES_START = 40;
const int HEADING_CODES_END = 47;
const int GUIDANCE_CODES_START = 60;
const int BLE_CODES_START = 70;
const int SPECIAL_CODES_START = 80;

/* Enumeration for all possible input codes */
enum InputCodes
{
  UNDEFINED = MANEUVER_CODES_START,
  GO_STRAIGHT,
  UTURN_RIGHT,
  UTURN_LEFT,
  KEEP_RIGHT,
  LIGHT_RIGHT,
  QUITE_RIGHT,
  HEAVY_RIGHT,
  KEEP_MIDDLE,
  KEEP_LEFT,
  LIGHT_LEFT,
  QUITE_LEFT,
  HEAVY_LEFT,
  START,
  FINISH,
  LIGHT_RIGHT_SOON = MANEUVER_DISTANCE_CODES_START,
  QUITE_RIGHT_SOON,
  HEAVY_RIGHT_SOON,
  LIGHT_LEFT_SOON,
  QUITE_LEFT_SOON,
  HEAVY_LEFT_SOON,
  LIGHT_RIGHT_NOW,
  QUITE_RIGHT_NOW,
  HEAVY_RIGHT_NOW,
  LIGHT_LEFT_NOW,
  QUITE_LEFT_NOW,
  HEAVY_LEFT_NOW,
  KEEP_RIGHT_SOON,
  KEEP_RIGHT_NOW,
  KEEP_LEFT_SOON,
  KEEP_LEFT_NOW,
  HEADING0 = HEADING_CODES_START,
  HEADING45,
  HEADING90,
  HEADING135,
  HEADING180,
  HEADING225,
  HEADING270,
  HEADING315,
  GPS_LOST = GUIDANCE_CODES_START,
  REROUTE,
  ON = SPECIAL_CODES_START
};

/* Checks, if incoming code is a heading command code */
bool isHeadingCommand(int code)
{
  return code >= HEADING_CODES_START && code <= HEADING_CODES_END;
}

/* Icons data. Generated by python script. See Readme */
  // 0 - undefined
const char undefinedFrames[][MATRIX_HEIGHT] = {
  {0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08}
};
const Icon undefined(1, undefinedFrames[0]);

 // 1 - go straight
const char goStraightFrames[][MATRIX_HEIGHT] = {
  {0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon goStraight(1, goStraightFrames[0]);

// 2 - uturn right
const char uturnRightFrames[][MATRIX_HEIGHT] = {
  {0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20},
  {0x00, 0x1c, 0x20, 0x20, 0x20, 0x20, 0x20},
  {0x00, 0x1c, 0x22, 0x22, 0x22, 0x22, 0x22},
  {0x00, 0x1c, 0x02, 0x02, 0x02, 0x02, 0x02},
  {0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
const Icon uturnRight(6, uturnRightFrames[0]);

 // 4 - keep right
const char keepRightFrames[][MATRIX_HEIGHT] = {
  {0x02, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x20}
};
const Icon keepRight(1, keepRightFrames[0]);

 // 5 - light right
const char lightRightFrames[][MATRIX_HEIGHT] = {
  {0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00}
};
const Icon lightRight(1, lightRightFrames[0]);

 // 6 - quite right
const char quiteRightFrames[][MATRIX_HEIGHT] = {
  {0x0f, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon quiteRight(1, quiteRightFrames[0]);

 // 7 - heavy right
const char heavyRightFrames[][MATRIX_HEIGHT] = {
  {0x08, 0x0c, 0x0a, 0x09, 0x00, 0x00, 0x00}
};
const Icon heavyRight(1, heavyRightFrames[0]);

 // 8 - keep middle
const char keepMiddleFrames[][MATRIX_HEIGHT] = {
  {0x49, 0x2a, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon keepMiddle(1, keepMiddleFrames[0]);

  // 13 - start
const char startFrames[][MATRIX_HEIGHT] = {
  {0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x00, 0x00},
  {0x00, 0x3e, 0x22, 0x2a, 0x22, 0x3e, 0x00},
  {0x7f, 0x41, 0x41, 0x49, 0x41, 0x41, 0x7f}
};
const Icon start(4, startFrames[0]);

 // 14 - end
const char finishFrames[][MATRIX_HEIGHT] = {
  {0x55, 0x2a, 0x55, 0x2a, 0x55, 0x2a, 0x55}
};
const Icon finish(1, finishFrames[0]);

 // 20 - light right soon
const char lightRightSoonFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00}
};
const Icon lightRightSoon(4, lightRightSoonFrames[0]);

 // 21 - quite right soon
const char quiteRightSoonFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x0f, 0x08, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x0f, 0x00, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x07, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0b, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0d, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0e, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0f, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon quiteRightSoon(7, quiteRightSoonFrames[0]);

 // 22 - heavy right soon
const char heavyRightSoonFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x00},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01}
};
const Icon heavyRightSoon(5, heavyRightSoonFrames[0]);

 // 26 - light right now
const char lightRightNowFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00},
    {0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00}
};
const Icon lightRightNow(4, lightRightNowFrames[0], true);

 // 27 - quite right now
const char quiteRightNowFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x0f, 0x08, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x0f, 0x00, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x07, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0b, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0d, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0e, 0x08, 0x08, 0x00, 0x00, 0x00},
    {0x00, 0x0f, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon quiteRightNow(7, quiteRightNowFrames[0], true);

 // 28 - heavy right now
const char heavyRightNowFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x01},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x00},
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01}
};
const Icon heavyRightNow(5, heavyRightNowFrames[0], true);


 // 32 - keep right soon
const char keepRightSoonFrames[][MATRIX_HEIGHT] = {
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x00},
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x00, 0x20},
    {0x02, 0x02, 0x02, 0x1c, 0x00, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x0c, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x14, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x18, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x00, 0x1c, 0x20, 0x20, 0x20},
    {0x02, 0x00, 0x02, 0x1c, 0x20, 0x20, 0x20},
    {0x00, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x20}
};
const Icon keepRightSoon(10, keepRightSoonFrames[0]);

 // 33 - keep right now
const char keepRightNowFrames[][MATRIX_HEIGHT] = {
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x00},
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x00, 0x20},
    {0x02, 0x02, 0x02, 0x1c, 0x00, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x0c, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x14, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x18, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x00, 0x1c, 0x20, 0x20, 0x20},
    {0x02, 0x00, 0x02, 0x1c, 0x20, 0x20, 0x20},
    {0x00, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x20},
    {0x02, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x20}
};
const Icon keepRightNow(10, keepRightNowFrames[0], true);

//40 - heading 0
const char heading0Frames[][MATRIX_HEIGHT] = {
    {0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00}
};
const Icon heading0(1, heading0Frames[0]);

//41 - heading 45
const char heading45Frames[][MATRIX_HEIGHT] = {
    {0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00}
};
const Icon heading45(1, heading45Frames[0]);

//42 - heading 90
const char heading90Frames[][MATRIX_HEIGHT] = {
    {0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00}
};
const Icon heading90(1, heading90Frames[0]);

//43 - heading 135
const char heading135Frames[][MATRIX_HEIGHT] = {
    {0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01}
};
const Icon heading135(1, heading135Frames[0]);

//44 - heading 180
const char heading180Frames[][MATRIX_HEIGHT] = {
    {0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08}
};
const Icon heading180(1, heading180Frames[0]);

  //60 - gps lost
const char gpsLostFrames[][MATRIX_HEIGHT] = {
    {0x00, 0x1c, 0x20, 0x2e, 0x22, 0x1c, 0x00}
};
const Icon gpsLost(1, gpsLostFrames[0]);

//61 - reroute
const char rerouteFrames[][MATRIX_HEIGHT] = {
    {0x08, 0x38, 0x20, 0x20, 0x20, 0x38, 0x08}
};
const Icon reroute(1, rerouteFrames[0]);

  // on
const char onFrames[][MATRIX_HEIGHT] = {
  {0x00, 0x25, 0x55, 0x56, 0x55, 0x25, 0x00}
};
const Icon on(1, onFrames[0]);

/* Converts incoming command code to the pointer to the object containing
   all the needed information about the icon to show it. */
const Icon * convertCommandToIcon(int code, bool& mirrored)
{
  const Icon * ret = NULL;
  mirrored = false;
  switch(code)
  {
    case UNDEFINED:
      ret = &undefined;
      break;
    case GO_STRAIGHT:
      ret = &goStraight;
      break;
    case UTURN_RIGHT:
      ret = &uturnRight;
      break;
    case UTURN_LEFT:
      mirrored = true;
      ret = &uturnRight;
      break;
    case KEEP_RIGHT:
      ret = &keepRight;
      break;
    case LIGHT_RIGHT:
      ret = &lightRight;
      break;
    case QUITE_RIGHT:
      ret = &quiteRight;
      break;
    case HEAVY_RIGHT:
      ret = &heavyRight;
      break;
    case KEEP_MIDDLE:
      ret = &keepMiddle;
      break;
    case KEEP_LEFT:
      mirrored = true;
      ret = &keepRight;
      break;
    case LIGHT_LEFT:
      mirrored = true;
      ret = &lightRight;
      break;
    case QUITE_LEFT:
      mirrored = true;
      ret = &quiteRight;
      break;
    case HEAVY_LEFT:
      mirrored = true;
      ret = &heavyRight;
      break;
    case START:
      ret = &start;
      break;
    case FINISH:
      ret = &finish;
      break;
    case LIGHT_RIGHT_SOON:
      ret = &lightRightSoon;
      break;
    case QUITE_RIGHT_SOON:
      ret = &quiteRightSoon;
      break;
    case HEAVY_RIGHT_SOON:
      ret = &heavyRightSoon;
      break;
    case LIGHT_LEFT_SOON:
      mirrored = true;
      ret = &lightRightSoon;
      break;
    case QUITE_LEFT_SOON:
      mirrored = true;
      ret = &quiteRightSoon;
      break;
    case HEAVY_LEFT_SOON:
      mirrored = true;
      ret = &heavyRightSoon;
      break;
    case LIGHT_RIGHT_NOW:
      ret = &lightRightNow;
      break;
    case QUITE_RIGHT_NOW:
      ret = &quiteRightNow;
      break;
    case HEAVY_RIGHT_NOW:
      ret = &heavyRightNow;
      break;
    case LIGHT_LEFT_NOW:
      mirrored = true;
      ret = &lightRightNow;
      break;
    case QUITE_LEFT_NOW:
      mirrored = true;
      ret = &quiteRightNow;
      break;
    case HEAVY_LEFT_NOW:
      mirrored = true;
      ret = &heavyRightNow;
      break;
    case KEEP_RIGHT_SOON:
      ret = &keepRightSoon;
      break;
    case KEEP_RIGHT_NOW:
      ret = &keepRightNow;
      break;
    case KEEP_LEFT_SOON:
      mirrored = true;
      ret = &keepRightSoon;
      break;
    case KEEP_LEFT_NOW:
      mirrored = true;
      ret = &keepRightNow;
      break;
    case HEADING0:
      ret = &heading0;
      break;
    case HEADING45:
      ret = &heading45;
      break;
    case HEADING90:
      ret = &heading90;
      break;
    case HEADING135:
      ret = &heading135;
      break;
    case HEADING180:
      ret = &heading180;
      break;
    case HEADING225:
      mirrored = true;
      ret = &heading135;
      break;
    case HEADING270:
      mirrored = true;
      ret = &heading90;
      break;
    case HEADING315:
      mirrored = true;
      ret = &heading45;
      break;
    case GPS_LOST:
      ret = &gpsLost;
      break;
    case REROUTE:
      ret = &reroute;
      break;
    case ON:
      ret = &on;
      break;
  }
  return ret;
}


