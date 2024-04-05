
#ifndef DESI_IMPORTANT_HACK_H
#define DESI_IMPORTANT_HACK_H

#include "socket.h"

Request request;
Response response;
float x,y,yPosName;
char extra[30];
int botCount,playerCount;
Color clr,clrFilled,clrHead,clrFilledBox,clrHealth,clrID,clrSkeleton,clrSkeleton1,bxclr;
Options options{1,0,3, false,1, false,201
};

int randomer;
Color FRAG() {
    randomer += 1;
    if (randomer == 0) {
        return Color(255, 165, 0);
    } else if (randomer == 1) {
        return Color(255, 165, 0);
    } else if (randomer == 2) {
        return Color(255, 165, 0);
    } else if (randomer == 3) {
        return Color(255, 165, 0);
    } else if (randomer == 4) {
        return Color(255, 165, 0);
    } else if (randomer == 5) {
        return Color(255, 165, 0);
    } else if (randomer == 6) {
        return Color(255, 165, 0);
    } else if (randomer == 7) {
        return Color(255, 165, 0);
    } else if (randomer == 8) {
        return Color(255, 165, 0);
    } else if (randomer ==9) {
        return Color(255, 165, 0);
    } else if (randomer == 10) {
        return Color(255, 165, 0);
    } else if (randomer == 11) {
        return Color(255, 165, 0);
    } else if (randomer == 12) {
        return Color(255, 165, 0);
    }else if (randomer == 13) {
        return Color(255, 165, 0);
    }else if (randomer == 14) {
        return Color(255, 165, 0);
    }else if (randomer == 15) {
        return Color(255, 165, 0);
    }else if (randomer == 16) {
        return Color(255, 0, 0);
    }else if (randomer == 17) {
        return Color(255, 0, 0);
    }else if (randomer == 18) {
        return Color(255, 0, 0);
    }else if (randomer == 19) {
        return Color(255, 0, 0);
    }else if (randomer == 20) {
        return Color(255, 0, 0);
    }else if (randomer == 21) {
        return Color(255, 0, 0);
    }else if (randomer == 22) {
        return Color(255, 0, 0);
    }else if (randomer == 23) {
        return Color(255, 0, 0);
    }else if (randomer == 24) {
        return Color(255, 0, 0);
    }else if (randomer == 25) {
        return Color(255, 0, 0);
    }else if (randomer == 26) {
        return Color(255, 0, 0);
	}else if (randomer == 27) {
        return Color(255, 0, 0);
    }else if (randomer == 28) {
        return Color(255, 0, 0);
    }else if (randomer == 29) {
        return Color(255, 0, 0);
    }else if (randomer == 30) {
        return Color(255, 0, 0);
    }
    else {
        randomer = 0;
        return Color(255, 0, 0);
    }
}

Color colorByDistance(int distance, float alpha) {
    Color _colorByDistance;
    if (distance < 600)
        _colorByDistance = Color(255, 0, 150, alpha);
    if (distance < 300)
        _colorByDistance = Color(255, 255, 0, alpha);
    if (distance < 150)
        _colorByDistance = Color(255, 133, 51, alpha);
    if (distance < 50)
        _colorByDistance = Color(255, 0, 0, alpha);
    return _colorByDistance;
}

Color colorByDistanceLINE(int distance, bool bot) {
    Color _colorByDistanceLINE;
    if (!bot) {
        if (distance < 450)
            _colorByDistanceLINE = Color(0, 255, 0, 255);
        if (distance < 200)
            _colorByDistanceLINE = Color(255, 255, 0, 255);
        if (distance < 120)
            _colorByDistanceLINE = Color(255, 133, 51, 255);
        if (distance < 50)
            _colorByDistanceLINE = Color(255, 0, 0, 255);
        return _colorByDistanceLINE;
    } else {
        _colorByDistanceLINE = Color(255, 255, 255, 255);
        return _colorByDistanceLINE;
    }
}

void DrawESP(ESP esp, int screenWidth, int screenHeight) {

    esp.DrawText(Color(255, 255, 255), "AMNESIA", Vec2(screenWidth / 2, screenHeight / 21.55f), 40);


    esp.DrawText(Color(255,255,255),  "@AmnesiaCheats", Vec2(screenWidth / 6.4, screenHeight / 1.1), 37);

    if (true) {
        if (botCount + playerCount > 0)
        {
            sprintf(extra, "%d", botCount + playerCount);
        }
        else if (response.InLobby)
        {
            sprintf(extra, "LOBBY");
        }
        else
        {
            sprintf(extra, "CLEAR");
        }


        if (botCount + playerCount > 0)
        {
            esp.DrawFilledRect(Color(255, 0, 0, 40),
                               Vec2(screenWidth / 2 - screenHeight / 12,
                                    screenHeight / 19),
                               Vec2(screenWidth / 2 + screenHeight / 12,
                                    screenHeight / 10));
            esp.DrawRect(Color(255, 0, 0, 255), 3,
                         Vec2(screenWidth / 2 - screenHeight / 12,
                              screenHeight / 19),
                         Vec2(screenWidth / 2 + screenHeight / 12,
                              screenHeight / 10));
            esp.DrawText(Color(255, 255, 255), extra,
                         Vec2(screenWidth / 2,
                              screenHeight / 11.5), screenHeight / 32);

        }
        else
        {
            esp.DrawFilledRect(Color(0, 255, 0, 50),    // green
                               Vec2(screenWidth / 2 - screenHeight / 12,
                                    screenHeight / 19),
                               Vec2(screenWidth / 2 + screenHeight / 12,
                                    screenHeight / 10));
            esp.DrawRect(Color(0, 255, 0, 255), 3,
                         Vec2(screenWidth / 2 - screenHeight / 12,
                              screenHeight / 19),
                         Vec2(screenWidth / 2 + screenHeight / 12,
                              screenHeight / 10));


            esp.DrawText(Color(255, 255, 255), extra,
                         Vec2(screenWidth / 2,
                              screenHeight / 11.5), screenHeight / 32);


        }
    }


    // if(isESP) {
   botCount=0;playerCount=0;
   request.ScreenHeight=screenHeight;

    request.options=options;
   request.ScreenWidth=screenWidth;
   request.Mode=InitMode;

   send((void*)&request,sizeof(request));
   receive((void*)&response);
        char hello[50]="failed";
        if(response.Success) {
                              if (options.openState == 0)//for Aimbot
                    esp.DrawCircle(Color(255,0,0), Vec2(screenWidth / 2, screenHeight / 2),
                                   options.aimingRange, 1.5);

            float textsize=screenHeight/50;
            for (int i = 0; i < response.PlayerCount; i++) {
                x = response.Players[i].HeadLocation.x;
                y = response.Players[i].HeadLocation.y;
                if (response.Players[i].isBot) {
                    botCount++;
                    clr = Color(30,232,222,255);
                    clrFilled = Color(30,232,222,50);
                    clrHead = Color(30,232,222,180);
                } else {
                    playerCount++;
                    clr = Color(255,0,0,255);
                    clrFilled = Color(255,0,0,50);
                    clrHead = Color(255,0,0,180);
                }
                            float mScale = screenHeight / (float) 1080;
                float magic_number = (response.Players[i].Distance * response.fov);
                float mx = (screenWidth / 4) / magic_number;
                float my = (screenWidth / 1.38) / magic_number;
				float mz = (screenWidth / 1.20) / magic_number;
                float top = response.Players[i].Bone.neck.y - my + (screenWidth / 1.7) / magic_number;
				//float bottom = response.Players[i].Bone.neck.y + my + screenHeight / 4 / magic_number;
				yPosName = top - screenHeight / 30;
				float bottom = response.Players[i].Bone.lAn.y + my - (screenWidth / 1.7) / magic_number;

            if (y > screenHeight / 2 - mz && y < screenHeight / 2 + mx && x > screenWidth / 2 - mx && x < screenWidth / 2 + mx) {
                clrSkeleton = Color(0, 255, 0);
                clrSkeleton1 = Color(0, 255, 0);
                clrFilledBox = Color(0, 255, 0, 50);
                } else {
                if (!response.Players[i].isBot) {
                    clrSkeleton = Color(255, 0, 0);
                    clrSkeleton1 = Color(255, 255, 255);
                    clrFilledBox = Color(255, 0, 0, 50);
                } else {
                    clrSkeleton = Color(255, 255, 255);
					clrSkeleton1 = Color(255, 255, 255);
                    clrFilledBox = Color(255, 255, 255, 50);
                }
            }

                switch (response.Players[i].TeamID) {
				case 1: clrID = Color(220, 20, 60, 160);
					break;
				case 2: clrID = Color(178, 34, 34, 160);
					break;
				case 3: clrID = Color(255, 20, 147, 160);
					break;
				case 4: clrID = Color(199, 21, 133, 160);
					break;
				case 5: clrID = Color(255, 69, 0, 160);
					break;
				case 6: clrID = Color(255, 140, 0, 160);
					break;
				case 7: clrID = Color(255, 215, 0, 160);
					break;
				case 8: clrID = Color(255, 0, 255, 160);
					break;
				case 9: clrID = Color(138, 43, 226, 160);
					break;
				case 10: clrID = Color(128, 0, 128, 160);
					break;
				case 11: clrID = Color(75, 0, 130, 160);
					break;
				case 12: clrID = Color(0, 128, 0, 160);
					break;
				case 13: clrID = Color(0, 100, 0, 160);
					break;
				case 14: clrID = Color(32, 178, 170, 160);
					break;
				case 15: clrID = Color(0, 139, 139, 160);
					break;
				case 16: clrID = Color(0, 206, 209, 160);
					break;
				case 17: clrID = Color(70, 130, 180, 160);
					break;
				case 18: clrID = Color(0, 191, 255, 160);
					break;
				case 19: clrID = Color(30, 144, 255, 160);
					break;
				case 20: clrID = Color(0, 0, 139, 160);
					break;
				case 21: clrID = Color(184, 134, 11, 160);
					break;
				case 22: clrID = Color(210, 105, 30, 160);
					break;
				case 23: clrID = Color(165, 42, 42, 160);
					break;
				case 24: clrID = Color(105, 105, 105, 160);
					break;
				case 25: clrID = Color(47, 79, 79, 160);
					break;
				case 26: clrID = Color(220, 20, 60, 160);
					break;
				case 27: clrID = Color(178, 34, 34, 160);
					break;
				case 28: clrID = Color(255, 20, 147, 160);
					break;
				case 29: clrID = Color(199, 21, 133, 160);
					break;
				case 30: clrID = Color(255, 69, 0, 160);
					break;
				case 31: clrID = Color(255, 140, 0, 160);
					break;
				case 32: clrID = Color(255, 215, 0, 160);
					break;
				case 33: clrID = Color(255, 0, 255, 160);
					break;
				case 34: clrID = Color(138, 43, 226, 160);
					break;
				case 35: clrID = Color(128, 0, 128, 160);
					break;
				case 36: clrID = Color(75, 0, 130, 160);
					break;
				case 37: clrID = Color(0, 128, 0, 160);
					break;
				case 38: clrID = Color(0, 100, 0, 160);
					break;
				case 39: clrID = Color(32, 178, 170, 160);
					break;
				case 40: clrID = Color(0, 139, 139, 160);
					break;
				case 41: clrID = Color(0, 206, 209, 160);
					break;
				case 42: clrID = Color(70, 130, 180, 160);
					break;
				case 43: clrID = Color(0, 191, 255, 160);
					break;
				case 44: clrID = Color(30, 144, 255, 160);
					break;
				case 45: clrID = Color(0, 0, 139, 160);
					break;
				case 46: clrID = Color(184, 134, 11, 160);
					break;
				case 47: clrID = Color(210, 105, 30, 160);
					break;
				case 48: clrID = Color(165, 42, 42, 160);
					break;
				case 49: clrID = Color(105, 105, 105, 160);
					break;
				case 50: clrID = Color(47, 79, 79, 160);
					break;
				case 51: clrID = Color(220, 20, 60, 160);
					break;
				case 52: clrID = Color(178, 34, 34, 160);
					break;
				case 53: clrID = Color(255, 20, 147, 160);
					break;
				case 54: clrID = Color(199, 21, 133, 160);
					break;
				case 55: clrID = Color(255, 69, 0, 160);
					break;
				case 56: clrID = Color(255, 140, 0, 160);
					break;
				case 57: clrID = Color(255, 215, 0, 160);
					break;
				case 58: clrID = Color(255, 0, 255, 160);
					break;
				case 59: clrID = Color(138, 43, 226, 160);
					break;
				case 60: clrID = Color(128, 0, 128, 160);
					break;
				case 61: clrID = Color(75, 0, 130, 160);
					break;
				case 62: clrID = Color(0, 128, 0, 160);
					break;
				case 63: clrID = Color(0, 100, 0, 160);
					break;
				case 64: clrID = Color(32, 178, 170, 160);
					break;
				case 65: clrID = Color(0, 139, 139, 160);
					break;
				case 66: clrID = Color(0, 206, 209, 160);
					break;
				case 67: clrID = Color(70, 130, 180, 160);
					break;
				case 68: clrID = Color(0, 191, 255, 160);
					break;
				case 69: clrID = Color(30, 144, 255, 160);
					break;
				case 70: clrID = Color(0, 0, 139, 160);
					break;
				case 71: clrID = Color(184, 134, 11, 160);
					break;
				case 72: clrID = Color(210, 105, 30, 160);
					break;
				case 73: clrID = Color(165, 42, 42, 160);
					break;
				case 74: clrID = Color(105, 105, 105, 160);
					break;
				case 75: clrID = Color(47, 79, 79, 160);
					break;
				case 76: clrID = Color(220, 20, 60, 160);
					break;
				case 77: clrID = Color(178, 34, 34, 160);
					break;
				case 78: clrID = Color(255, 20, 147, 160);
					break;
				case 79: clrID = Color(199, 21, 133, 160);
					break;
				case 80: clrID = Color(255, 69, 0, 160);
					break;
				case 81: clrID = Color(255, 140, 0, 160);
					break;
				case 82: clrID = Color(255, 215, 0, 160);
					break;
				case 83: clrID = Color(255, 0, 255, 160);
					break;
				case 84: clrID = Color(138, 43, 226, 160);
					break;
				case 85: clrID = Color(128, 0, 128, 160);
					break;
				case 86: clrID = Color(75, 0, 130, 160);
					break;
				case 87: clrID = Color(0, 128, 0, 160);
					break;
				case 88: clrID = Color(0, 100, 0, 160);
					break;
				case 89: clrID = Color(32, 178, 170, 160);
					break;
				case 90: clrID = Color(0, 139, 139, 160);
					break;
				case 91: clrID = Color(0, 206, 209, 160);
					break;
				case 92: clrID = Color(70, 130, 180, 160);
					break;
				case 93: clrID = Color(0, 191, 255, 160);
					break;
				case 94: clrID = Color(30, 144, 255, 160);
					break;
				case 95: clrID = Color(0, 0, 139, 160);
					break;
				case 96: clrID = Color(184, 134, 11, 160);
					break;
				case 97: clrID = Color(210, 105, 30, 160);
					break;
				case 98: clrID = Color(165, 42, 42, 160);
					break;
				case 99: clrID = Color(105, 105, 105, 160);
					break;
				case 100: clrID = Color(47, 79, 79, 160);
					break;
				case 101: clrID = Color(220, 20, 60, 160);
					break;
				case 102: clrID = Color(178, 34, 34, 160);
					break;
				case 103: clrID = Color(255, 20, 147, 160);
					break;
				case 104: clrID = Color(199, 21, 133, 160);
					break;
				case 105: clrID = Color(255, 69, 0, 160);
					break;
				case 106: clrID = Color(255, 140, 0, 160);
					break;
				case 107: clrID = Color(255, 215, 0, 160);
					break;
				case 108: clrID = Color(255, 0, 255, 160);
					break;
				case 109: clrID = Color(138, 43, 226, 160);
					break;
				case 110: clrID = Color(128, 0, 128, 160);
					break;
				case 111: clrID = Color(75, 0, 130, 160);
					break;
				case 112: clrID = Color(0, 128, 0, 160);
					break;
				case 113: clrID = Color(0, 100, 0, 160);
					break;
				case 114: clrID = Color(32, 178, 170, 160);
					break;
				case 115: clrID = Color(0, 139, 139, 160);
					break;
				case 116: clrID = Color(0, 206, 209, 160);
					break;
				case 117: clrID = Color(70, 130, 180, 160);
					break;
				case 118: clrID = Color(0, 191, 255, 160);
					break;
				case 119: clrID = Color(30, 144, 255, 160);
					break;
				case 120: clrID = Color(0, 0, 139, 160);
					break;
				case 121: clrID = Color(184, 134, 11, 160);
					break;
				case 122: clrID = Color(210, 105, 30, 160);
					break;
				case 123: clrID = Color(165, 42, 42, 160);
					break;
				case 124: clrID = Color(105, 105, 105, 160);
					break;
				case 125: clrID = Color(47, 79, 79, 160);
					break;
				case 126: clrID = Color(220, 20, 60, 160);
					break;
				case 127: clrID = Color(178, 34, 34, 160);
					break;
				case 128: clrID = Color(255, 20, 147, 160);
					break;
				case 129: clrID = Color(199, 21, 133, 160);
					break;
				case 130: clrID = Color(255, 69, 0, 160);
					break;
				case 131: clrID = Color(255, 140, 0, 160);
					break;
				case 132: clrID = Color(255, 215, 0, 160);
					break;
				case 133: clrID = Color(255, 0, 255, 160);
					break;
				case 134: clrID = Color(138, 43, 226, 160);
					break;
				case 135: clrID = Color(128, 0, 128, 160);
					break;
				case 136: clrID = Color(75, 0, 130, 160);
					break;
				case 137: clrID = Color(0, 128, 0, 160);
					break;
				case 138: clrID = Color(0, 100, 0, 160);
					break;
				case 139: clrID = Color(32, 178, 170, 160);
					break;
				case 140: clrID = Color(0, 139, 139, 160);
					break;
				case 141: clrID = Color(0, 206, 209, 160);
					break;
				case 142: clrID = Color(70, 130, 180, 160);
					break;
				case 143: clrID = Color(0, 191, 255, 160);
					break;
				case 144: clrID = Color(30, 144, 255, 160);
					break;
				case 145: clrID = Color(0, 0, 139, 160);
					break;
				case 146: clrID = Color(184, 134, 11, 160);
					break;
				case 147: clrID = Color(210, 105, 30, 160);
					break;
				case 148: clrID = Color(165, 42, 42, 160);
					break;
				case 149: clrID = Color(105, 105, 105, 160);
					break;
				case 150: clrID = Color(47, 79, 79, 160);
					break;
				case 151: clrID = Color(220, 20, 60, 160);
					break;
				case 152: clrID = Color(178, 34, 34, 160);
					break;
				case 153: clrID = Color(255, 20, 147, 160);
					break;
				case 154: clrID = Color(199, 21, 133, 160);
					break;
				case 155: clrID = Color(255, 69, 0, 160);
					break;
				case 156: clrID = Color(255, 140, 0, 160);
					break;
				case 157: clrID = Color(255, 215, 0, 160);
					break;
				case 158: clrID = Color(255, 0, 255, 160);
					break;
				case 159: clrID = Color(138, 43, 226, 160);
					break;
				case 160: clrID = Color(128, 0, 128, 160);
					break;
				case 161: clrID = Color(75, 0, 130, 160);
					break;
				case 162: clrID = Color(0, 128, 0, 160);
					break;
				case 163: clrID = Color(0, 100, 0, 160);
					break;
				case 164: clrID = Color(32, 178, 170, 160);
					break;
				case 165: clrID = Color(0, 139, 139, 160);
					break;
				case 166: clrID = Color(0, 206, 209, 160);
					break;
				case 167: clrID = Color(70, 130, 180, 160);
					break;
				case 168: clrID = Color(0, 191, 255, 160);
					break;
				case 169: clrID = Color(30, 144, 255, 160);
					break;
				case 170: clrID = Color(0, 0, 139, 160);
					break;
				case 171: clrID = Color(184, 134, 11, 160);
					break;
				case 172: clrID = Color(210, 105, 30, 160);
					break;
				case 173: clrID = Color(165, 42, 42, 160);
					break;
				case 174: clrID = Color(105, 105, 105, 160);
					break;
				case 175: clrID = Color(47, 79, 79, 160);
					break;
				case 176: clrID = Color(220, 20, 60, 160);
					break;
				case 177: clrID = Color(178, 34, 34, 160);
					break;
				case 178: clrID = Color(255, 20, 147, 160);
					break;
				case 179: clrID = Color(199, 21, 133, 160);
					break;
				case 180: clrID = Color(255, 69, 0, 160);
					break;
				case 181: clrID = Color(255, 140, 0, 160);
					break;
				case 182: clrID = Color(255, 215, 0, 160);
					break;
				case 183: clrID = Color(255, 0, 255, 160);
					break;
				case 184: clrID = Color(138, 43, 226, 160);
					break;
				case 185: clrID = Color(128, 0, 128, 160);
					break;
				case 186: clrID = Color(75, 0, 130, 160);
					break;
				case 187: clrID = Color(0, 128, 0, 160);
					break;
				case 188: clrID = Color(0, 100, 0, 160);
					break;
				case 189: clrID = Color(32, 178, 170, 160);
					break;
				case 190: clrID = Color(0, 139, 139, 160);
					break;
				case 191: clrID = Color(0, 206, 209, 160);
					break;
				case 192: clrID = Color(70, 130, 180, 160);
					break;
				case 193: clrID = Color(0, 191, 255, 160);
					break;
				case 194: clrID = Color(30, 144, 255, 160);
					break;
				case 195: clrID = Color(0, 0, 139, 160);
					break;
				case 196: clrID = Color(184, 134, 11, 160);
					break;
				case 197: clrID = Color(210, 105, 30, 160);
					break;
				case 198: clrID = Color(165, 42, 42, 160);
					break;
				case 199: clrID = Color(105, 105, 105, 160);
					break;
				case 200: clrID = Color(47, 79, 79, 160);
					break;
				case 201: clrID = Color(220, 20, 60, 160);
					break;
				case 202: clrID = Color(178, 34, 34, 160);
					break;
				case 203: clrID = Color(255, 20, 147, 160);
					break;
				case 204: clrID = Color(199, 21, 133, 160);
					break;
				case 205: clrID = Color(255, 69, 0, 160);
					break;
				case 206: clrID = Color(255, 140, 0, 160);
					break;
				case 207: clrID = Color(255, 215, 0, 160);
					break;
				case 208: clrID = Color(255, 0, 255, 160);
					break;
				case 209: clrID = Color(138, 43, 226, 160);
					break;
				case 210: clrID = Color(128, 0, 128, 160);
					break;
				case 211: clrID = Color(75, 0, 130, 160);
					break;
				case 212: clrID = Color(0, 128, 0, 160);
					break;
				case 213: clrID = Color(0, 100, 0, 160);
					break;
				case 214: clrID = Color(32, 178, 170, 160);
					break;
				case 215: clrID = Color(0, 139, 139, 160);
					break;
				case 216: clrID = Color(0, 206, 209, 160);
					break;
				case 217: clrID = Color(70, 130, 180, 160);
					break;
				case 218: clrID = Color(0, 191, 255, 160);
					break;
				case 219: clrID = Color(30, 144, 255, 160);
					break;
				case 220: clrID = Color(0, 0, 139, 160);
					break;
				case 221: clrID = Color(184, 134, 11, 160);
					break;
				case 222: clrID = Color(210, 105, 30, 160);
					break;
				case 223: clrID = Color(165, 42, 42, 160);
					break;
				case 224: clrID = Color(105, 105, 105, 160);
					break;
				case 225: clrID = Color(47, 79, 79, 160);
					break;
				case 226: clrID = Color(220, 20, 60, 160);
					break;
				case 227: clrID = Color(178, 34, 34, 160);
					break;
				case 228: clrID = Color(255, 20, 147, 160);
					break;
				case 229: clrID = Color(199, 21, 133, 160);
					break;
				case 230: clrID = Color(255, 69, 0, 160);
					break;
				case 231: clrID = Color(255, 140, 0, 160);
					break;
				case 232: clrID = Color(255, 215, 0, 160);
					break;
				case 233: clrID = Color(255, 0, 255, 160);
					break;
				case 234: clrID = Color(138, 43, 226, 160);
					break;
				case 235: clrID = Color(128, 0, 128, 160);
					break;
				case 236: clrID = Color(75, 0, 130, 160);
					break;
				case 237: clrID = Color(0, 128, 0, 160);
					break;
				case 238: clrID = Color(0, 100, 0, 160);
					break;
				case 239: clrID = Color(32, 178, 170, 160);
					break;
				case 240: clrID = Color(0, 139, 139, 160);
					break;
				case 241: clrID = Color(0, 206, 209, 160);
					break;
				case 242: clrID = Color(70, 130, 180, 160);
					break;
				case 243: clrID = Color(0, 191, 255, 160);
					break;
				case 244: clrID = Color(30, 144, 255, 160);
					break;
				case 245: clrID = Color(0, 0, 139, 160);
					break;
				case 246: clrID = Color(184, 134, 11, 160);
					break;
				case 247: clrID = Color(210, 105, 30, 160);
					break;
				case 248: clrID = Color(165, 42, 42, 160);
					break;
				case 249: clrID = Color(105, 105, 105, 160);
					break;
				case 250: clrID = Color(47, 79, 79, 160);
					break;
				case 251: clrID = Color(220, 20, 60, 160);
					break;
				case 252: clrID = Color(178, 34, 34, 160);
					break;
				case 253: clrID = Color(255, 20, 147, 160);
					break;
				case 254: clrID = Color(199, 21, 133, 160);
					break;
				case 255: clrID = Color(255, 69, 0, 160);
					break;
				case 256: clrID = Color(255, 140, 0, 160);
					break;
				case 257: clrID = Color(255, 215, 0, 160);
					break;
				case 258: clrID = Color(255, 0, 255, 160);
					break;
				case 259: clrID = Color(138, 43, 226, 160);
					break;
				case 260: clrID = Color(128, 0, 128, 160);
					break;
				case 261: clrID = Color(75, 0, 130, 160);
					break;
				case 262: clrID = Color(0, 128, 0, 160);
					break;
				case 263: clrID = Color(0, 100, 0, 160);
					break;
				case 264: clrID = Color(32, 178, 170, 160);
					break;
				case 265: clrID = Color(0, 139, 139, 160);
					break;
				case 266: clrID = Color(0, 206, 209, 160);
					break;
				case 267: clrID = Color(70, 130, 180, 160);
					break;
				case 268: clrID = Color(0, 191, 255, 160);
					break;
				case 269: clrID = Color(30, 144, 255, 160);
					break;
				case 270: clrID = Color(0, 0, 139, 160);
					break;
				case 271: clrID = Color(184, 134, 11, 160);
					break;
				case 272: clrID = Color(210, 105, 30, 160);
					break;
				case 273: clrID = Color(165, 42, 42, 160);
					break;
				case 274: clrID = Color(105, 105, 105, 160);
					break;
				case 275: clrID = Color(47, 79, 79, 160);
					break;
				case 276: clrID = Color(220, 20, 60, 160);
					break;
				case 277: clrID = Color(178, 34, 34, 160);
					break;
				case 278: clrID = Color(255, 20, 147, 160);
					break;
				case 279: clrID = Color(199, 21, 133, 160);
					break;
				case 280: clrID = Color(255, 69, 0, 160);
					break;
				case 281: clrID = Color(255, 140, 0, 160);
					break;
				case 282: clrID = Color(255, 215, 0, 160);
					break;
				case 283: clrID = Color(255, 0, 255, 160);
					break;
				case 284: clrID = Color(138, 43, 226, 160);
					break;
				case 285: clrID = Color(128, 0, 128, 160);
					break;
				case 286: clrID = Color(75, 0, 130, 160);
					break;
				case 287: clrID = Color(0, 128, 0, 160);
					break;
				case 288: clrID = Color(0, 100, 0, 160);
					break;
				case 289: clrID = Color(32, 178, 170, 160);
					break;
				case 290: clrID = Color(0, 139, 139, 160);
					break;
				case 291: clrID = Color(0, 206, 209, 160);
					break;
				case 292: clrID = Color(70, 130, 180, 160);
					break;
				case 293: clrID = Color(0, 191, 255, 160);
					break;
				case 294: clrID = Color(30, 144, 255, 160);
					break;
				case 295: clrID = Color(0, 0, 139, 160);
					break;
				case 296: clrID = Color(184, 134, 11, 160);
					break;
				case 297: clrID = Color(210, 105, 30, 160);
					break;
				case 298: clrID = Color(165, 42, 42, 160);
					break;
				case 299: clrID = Color(105, 105, 105, 160);
					break;
				case 300: clrID = Color(47, 79, 79, 160);
					break;
				case 301: clrID = Color(220, 20, 60, 160);
					break;
				case 302: clrID = Color(178, 34, 34, 160);
					break;
				case 303: clrID = Color(255, 20, 147, 160);
					break;
				case 304: clrID = Color(199, 21, 133, 160);
					break;
				case 305: clrID = Color(255, 69, 0, 160);
					break;
				case 306: clrID = Color(255, 140, 0, 160);
					break;
				case 307: clrID = Color(255, 215, 0, 160);
					break;
				case 308: clrID = Color(255, 0, 255, 160);
					break;
				case 309: clrID = Color(138, 43, 226, 160);
					break;
				case 310: clrID = Color(128, 0, 128, 160);
					break;
				case 311: clrID = Color(75, 0, 130, 160);
					break;
				case 312: clrID = Color(0, 128, 0, 160);
					break;
				case 313: clrID = Color(0, 100, 0, 160);
					break;
				case 314: clrID = Color(32, 178, 170, 160);
					break;
				case 315: clrID = Color(0, 139, 139, 160);
					break;
				case 316: clrID = Color(0, 206, 209, 160);
					break;
				case 317: clrID = Color(70, 130, 180, 160);
					break;
				case 318: clrID = Color(0, 191, 255, 160);
					break;
				case 319: clrID = Color(30, 144, 255, 160);
					break;
				case 320: clrID = Color(0, 0, 139, 160);
					break;
				case 321: clrID = Color(184, 134, 11, 160);
					break;
				case 322: clrID = Color(210, 105, 30, 160);
					break;
				case 323: clrID = Color(165, 42, 42, 160);
					break;
				case 324: clrID = Color(105, 105, 105, 160);
					break;
				case 325: clrID = Color(47, 79, 79, 160);
					break;
				case 326: clrID = Color(220, 20, 60, 160);
					break;
				case 327: clrID = Color(178, 34, 34, 160);
					break;
				case 328: clrID = Color(255, 20, 147, 160);
					break;
				case 329: clrID = Color(199, 21, 133, 160);
					break;
				case 330: clrID = Color(255, 69, 0, 160);
					break;
				case 331: clrID = Color(255, 140, 0, 160);
					break;
				case 332: clrID = Color(255, 215, 0, 160);
					break;
				case 333: clrID = Color(255, 0, 255, 160);
					break;
				case 334: clrID = Color(138, 43, 226, 160);
					break;
				case 335: clrID = Color(128, 0, 128, 160);
					break;
				case 336: clrID = Color(75, 0, 130, 160);
					break;
				case 337: clrID = Color(0, 128, 0, 160);
					break;
				case 338: clrID = Color(0, 100, 0, 160);
					break;
				case 339: clrID = Color(32, 178, 170, 160);
					break;
				case 340: clrID = Color(0, 139, 139, 160);
					break;
				case 341: clrID = Color(0, 206, 209, 160);
					break;
				case 342: clrID = Color(70, 130, 180, 160);
					break;
				case 343: clrID = Color(0, 191, 255, 160);
					break;
				case 344: clrID = Color(30, 144, 255, 160);
					break;
				case 345: clrID = Color(0, 0, 139, 160);
					break;
				case 346: clrID = Color(184, 134, 11, 160);
					break;
				case 347: clrID = Color(210, 105, 30, 160);
					break;
				case 348: clrID = Color(165, 42, 42, 160);
					break;
				case 349: clrID = Color(105, 105, 105, 160);
					break;
				case 350: clrID = Color(47, 79, 79, 160);
					break;
				case 351: clrID = Color(220, 20, 60, 160);
					break;
				case 352: clrID = Color(178, 34, 34, 160);
					break;
				case 353: clrID = Color(255, 20, 147, 160);
					break;
				case 354: clrID = Color(199, 21, 133, 160);
					break;
				case 355: clrID = Color(255, 69, 0, 160);
					break;
				case 356: clrID = Color(255, 140, 0, 160);
					break;
				case 357: clrID = Color(255, 215, 0, 160);
					break;
				case 358: clrID = Color(255, 0, 255, 160);
					break;
				case 359: clrID = Color(138, 43, 226, 160);
					break;
				case 360: clrID = Color(128, 0, 128, 160);
					break;
				case 361: clrID = Color(75, 0, 130, 160);
					break;
				case 362: clrID = Color(0, 128, 0, 160);
					break;
				case 363: clrID = Color(0, 100, 0, 160);
					break;
				case 364: clrID = Color(32, 178, 170, 160);
					break;
				case 365: clrID = Color(0, 139, 139, 160);
					break;
				case 366: clrID = Color(0, 206, 209, 160);
					break;
				case 367: clrID = Color(70, 130, 180, 160);
					break;
				case 368: clrID = Color(0, 191, 255, 160);
					break;
				case 369: clrID = Color(30, 144, 255, 160);
					break;
				case 370: clrID = Color(0, 0, 139, 160);
					break;
				case 371: clrID = Color(184, 134, 11, 160);
					break;
				case 372: clrID = Color(210, 105, 30, 160);
					break;
				case 373: clrID = Color(165, 42, 42, 160);
					break;
				case 374: clrID = Color(105, 105, 105, 160);
					break;
				case 375: clrID = Color(47, 79, 79, 160);
					break;
				case 376: clrID = Color(220, 20, 60, 160);
					break;
				case 377: clrID = Color(178, 34, 34, 160);
					break;
				case 378: clrID = Color(255, 20, 147, 160);
					break;
				case 379: clrID = Color(199, 21, 133, 160);
					break;
				case 380: clrID = Color(255, 69, 0, 160);
					break;
				case 381: clrID = Color(255, 140, 0, 160);
					break;
				case 382: clrID = Color(255, 215, 0, 160);
					break;
				case 383: clrID = Color(255, 0, 255, 160);
					break;
				case 384: clrID = Color(138, 43, 226, 160);
					break;
				case 385: clrID = Color(128, 0, 128, 160);
					break;
				case 386: clrID = Color(75, 0, 130, 160);
					break;
				case 387: clrID = Color(0, 128, 0, 160);
					break;
				case 388: clrID = Color(0, 100, 0, 160);
					break;
				case 389: clrID = Color(32, 178, 170, 160);
					break;
				case 390: clrID = Color(0, 139, 139, 160);
					break;
				case 391: clrID = Color(0, 206, 209, 160);
					break;
				case 392: clrID = Color(70, 130, 180, 160);
					break;
				case 393: clrID = Color(0, 191, 255, 160);
					break;
				case 394: clrID = Color(30, 144, 255, 160);
					break;
				case 395: clrID = Color(0, 0, 139, 160);
					break;
				case 396: clrID = Color(184, 134, 11, 160);
					break;
				case 397: clrID = Color(210, 105, 30, 160);
					break;
				case 398: clrID = Color(165, 42, 42, 160);
					break;
				case 399: clrID = Color(105, 105, 105, 160);
					break;
				case 400: clrID = Color(47, 79, 79, 160);
					break;
				}




                if (response.Players[i].HeadLocation.z != 1) {
                    if (x > -50 && x < screenWidth + 50) {//onScreen
                        if (isSkelton && response.Players[i].Bone.isBone) {  //Skelton
                            esp.DrawLine(clr, 2, Vec2(x, y),
                                         Vec2(response.Players[i].Bone.neck.x,
                                              response.Players[i].Bone.neck.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.neck.x,
                                                      response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.cheast.x,
                                              response.Players[i].Bone.cheast.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.cheast.x,
                                                      response.Players[i].Bone.cheast.y),
                                         Vec2(response.Players[i].Bone.pelvis.x,
                                              response.Players[i].Bone.pelvis.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.neck.x,
                                                      response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.lSh.x,
                                              response.Players[i].Bone.lSh.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.neck.x,
                                                      response.Players[i].Bone.neck.y),
                                         Vec2(response.Players[i].Bone.rSh.x,
                                              response.Players[i].Bone.rSh.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.lSh.x,
                                                      response.Players[i].Bone.lSh.y),
                                         Vec2(response.Players[i].Bone.lElb.x,
                                              response.Players[i].Bone.lElb.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.rSh.x,
                                                      response.Players[i].Bone.rSh.y),
                                         Vec2(response.Players[i].Bone.rElb.x,
                                              response.Players[i].Bone.rElb.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.lElb.x,
                                                      response.Players[i].Bone.lElb.y),
                                         Vec2(response.Players[i].Bone.lWr.x,
                                              response.Players[i].Bone.lWr.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.rElb.x,
                                                      response.Players[i].Bone.rElb.y),
                                         Vec2(response.Players[i].Bone.rWr.x,
                                              response.Players[i].Bone.rWr.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.pelvis.x,
                                                      response.Players[i].Bone.pelvis.y),
                                         Vec2(response.Players[i].Bone.lTh.x,
                                              response.Players[i].Bone.lTh.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.pelvis.x,
                                                      response.Players[i].Bone.pelvis.y),
                                         Vec2(response.Players[i].Bone.rTh.x,
                                              response.Players[i].Bone.rTh.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.lTh.x,
                                                      response.Players[i].Bone.lTh.y),
                                         Vec2(response.Players[i].Bone.lKn.x,
                                              response.Players[i].Bone.lKn.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.rTh.x,
                                                      response.Players[i].Bone.rTh.y),
                                         Vec2(response.Players[i].Bone.rKn.x,
                                              response.Players[i].Bone.rKn.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.lKn.x,
                                                      response.Players[i].Bone.lKn.y),
                                         Vec2(response.Players[i].Bone.lAn.x,
                                              response.Players[i].Bone.lAn.y));
                            esp.DrawLine(clr, 2, Vec2(response.Players[i].Bone.rKn.x,
                                                      response.Players[i].Bone.rKn.y),
                                         Vec2(response.Players[i].Bone.rAn.x,
                                              response.Players[i].Bone.rAn.y));
                        }

                        if (isPlayerBox) {
                            esp.DrawDistance(clrSkeleton, "┌",
                                         Vec2(x - mx, top), textsize+7);
						esp.DrawDistance(clrSkeleton, "┐",
                                         Vec2(x + mx, top), textsize+7);
						esp.DrawDistance(clrSkeleton, "└",
                                         Vec2(x - mx, bottom), textsize+7);
						esp.DrawDistance(clrSkeleton, "┘",
                                         Vec2(x + mx, bottom), textsize+7);
                        }

                        if (isPlayerHealth) {
                            if (response.Players[i].Health < 35)
                                clrHealth = Color(204, 51, 51, 200);
							 else if (response.Players[i].Health < 75)
                                clrHealth = Color(255, 153, 153, 200);
                             else
                                clrHealth = Color(255, 255, 255, 200);
							    esp.DrawFilledRect1(clrHealth,
                                Vec2(x - screenWidth / 21, top - screenHeight / 33.5),
								Vec2(x - screenWidth / 21 + (2 * screenWidth / 21) * response.Players[i].Health /100, top - screenHeight / 42));
                        }
                        //Head
                        if (isPlayerHead)
                            esp.DrawCircle(clrSkeleton,
							        Vec2(response.Players[i].Bone.neck.x,
                                         response.Players[i].Bone.neck.y - 3), screenHeight / 5.5 / magic_number, 1.5);
                        //Name and distance
                        if (isPlayerName) {
                               esp.DrawFilledName(clrID,
                                             Vec2(x - screenWidth / 21, top - screenHeight / 18),
											 Vec2(x + screenWidth / 21, top - screenHeight / 33.5));
							// Name
							esp.DrawName1(Color().White(), response.Players[i].PlayerNameByte, response.Players[i].TeamID,
                                         Vec2(x, top - screenHeight / 28), textsize);
							esp.DrawFilledName(Color(0, 0, 0, 60),
                                             Vec2(x - screenWidth / 21, top - screenHeight / 18),
											 Vec2(x - screenWidth / 33, top - screenHeight / 33.5));
							}

							if (isTeamID) {
                            esp.DrawTeamID(Color(255,255,255), response.Players[i].TeamID,
                                         Vec2(x - screenWidth / 25.7, top - screenHeight / 28), textsize);
							esp.DrawTextBot(clrID, "▼",
                                         Vec2(x, top - screenHeight / 86), textsize);
							}
                        if (isPlayerDist) {
                            sprintf(extra, "%0.0fM", response.Players[i].Distance);
                            esp.DrawDistance(Color(255, 255, 255), extra,
                                         Vec2(x, bottom + screenHeight / 60), textsize);
                        }
                        //weapon
                        if (isEnemyWeapon && response.Players[i].Weapon.isWeapon)
                            esp.DrawWeapon(Color(255, 255, 255), response.Players[i].Weapon.id,
                            response.Players[i].Weapon.ammo,
                            Vec2(x, bottom + screenHeight / 27), screenHeight / 50);
                            esp.DrawWeaponIcon(response.Players[i].Weapon.id, Vec2(x - screenWidth / 42, top - screenHeight / 20));
                    }
                }
                //360 Alert
                    if (response.Players[i].HeadLocation.z == 1.0f) {
                        if(!isr360Alert)
                            continue;
                        if (y > screenHeight - screenHeight / 12)
                            y = screenHeight - screenHeight / 12;
                        else if (y < screenHeight / 12)
                            y = screenHeight / 12;
                        if (x < screenWidth / 2) {
                            esp.DrawFilledCircle(Color(255, 0, 0, 80), Vec2(screenWidth, y),
                                                 screenHeight / 18);
                            sprintf(extra, "%0.0f m", response.Players[i].Distance);

                            esp.DrawText(Color(180, 250, 181, 200), extra,
                                         Vec2(screenWidth - screenWidth / 80, y), textsize);

                        } else {
                            esp.DrawFilledCircle(Color(255, 0, 0, 80), Vec2(0, y),
                                                 screenHeight / 18);
                            sprintf(extra, "%0.0f m", response.Players[i].Distance);
                            esp.DrawText(Color(180, 250, 181, 200), extra,
                                         Vec2(screenWidth / 80, y), textsize);
                        }
                    }
                    else if (x < -screenWidth / 10 || x > screenWidth + screenWidth / 10) {
                        if(!isr360Alert)
                            continue;
                        if (y > screenHeight - screenHeight / 12)
                            y = screenHeight - screenHeight / 12;
                        else if (y < screenHeight / 12)
                            y = screenHeight / 12;
                        if (x > screenWidth / 2) {
                            esp.DrawFilledCircle(Color(255, 0, 0, 80), Vec2(screenWidth, y),screenHeight / 18);
                            sprintf(extra, "%0.0f m", response.Players[i].Distance);
                            esp.DrawText(Color(180, 250, 181, 200), extra,
                                         Vec2(screenWidth - screenWidth / 80, y), textsize);
                        } else {
                            esp.DrawFilledCircle(Color(255, 0, 0, 80), Vec2(0, y),screenHeight / 18);
                            sprintf(extra, "%0.0f m", response.Players[i].Distance);
                            esp.DrawText(Color(180, 250, 181, 200), extra,
                                         Vec2(screenWidth / 80, y), textsize);
                        }
                    }
                    else if(isPlayerLine) {
                    esp.DrawLine(clrSkeleton, 1,
				    Vec2(screenWidth / 2, screenHeight / 8),
			        Vec2(x, top - screenHeight / 34));
                    }
            }
            for (int i = 0; i < response.GrenadeCount; i++){
                if(!isGrenadeWarning)
                    continue;
                esp.DrawText(Color(255, 89, 200),OBFUSCATE("Warning: Grenade"),Vec2(screenWidth/2,screenHeight/8),textsize);
                if(response.Grenade[i].Location.z!=1.0f){
                         if(response.Grenade[i].type==1 )
                        esp.DrawText(Color(255,0,0),OBFUSCATE("Grenade"),Vec2(response.Grenade[i].Location.x,response.Grenade[i].Location.y),textsize);
                    else
                        esp.DrawText(Color(255, 158, 89),OBFUSCATE("Molotov"),Vec2(response.Grenade[i].Location.x,response.Grenade[i].Location.y),textsize);
                }
            }
            for(int i = 0; i < response.VehicleCount; i++){
                if(response.Vehicles[i].Location.z!=1.0f) {
                    esp.DrawVehicles(response.Vehicles[i].VehicleName,response.Vehicles[i].Distance,Vec2(response.Vehicles[i].Location.x,response.Vehicles[i].Location.y),15);

                }
            }
           for(int i = 0; i < response.ItemsCount; i++){
               if(response.Items[i].Location.z!=1.0f) {
                   esp.DrawItems(response.Items[i].ItemName,response.Items[i].Distance,Vec2(response.Items[i].Location.x,response.Items[i].Location.y),textsize);
               }
           }
        }

}


#endif //DESI_IMPORTANT_HACK_H
