#include <iostream>
using namespace std;

int a1[12],
    a2[12],
    a3[12],
    a4[12];
char reply;
int used1,
    used2,
    used3,
    used4,
    minInt,
    intNum,
    oneInt;
int* hopPtr;
int* hopPtr1;
int* hopPtr2;
int* hopPtr3;
int* hopPtr4;
int* endPtr;
int* endPtr1;
int* endPtr2;
int* probePtr;
char begA1Str[] = "beginning a1: ";
char cpaA1Str[] = "chkPointA a1: ";
char proA1Str[] = "processed a1: ";
char comA2Str[] = "          a2: ";
char comA3Str[] = "          a3: ";
char comA4Str[] = "          a4: ";
char einStr[]   = "Enter integer #";
char moStr[]    = "Max of ";
char ieStr[]    = " ints entered...";
char eaiStr[]   = "End adding ints? (y or Y = yes, others = no) ";
char dacStr[]   = "Do another case? (n or N = no, others = yes) ";
char dlStr[]    = "================================";
char byeStr[]   = "bye...";

int main()
{
                   //do
begDW1://          {
                      intNum = 0;
                      used1 = 0;
                      used2 = 0;
                      hopPtr1 = a1;
                      hopPtr2 = a2;
                      cout << eaiStr;
                      cin >> reply;
                      //while (reply != 'y' && reply != 'Y')
                      goto WTest1;
begW1://              {
                         ++intNum;
                         cout << einStr;
                         cout << intNum;
                         cout << ':' << ' ';
                         cin >> oneInt;
                         //if ( (intNum & 1) != 0 )
                         if ( (intNum & 1) == 0 ) goto else1;
begI1://                 {
                            *hopPtr1 = oneInt;
                            ++hopPtr1;
                            ++used1;
                         goto endI1;
//                       }
else1://                 else
//                       {
                            *hopPtr2 = oneInt;
                            ++hopPtr2;
                            ++used2;
endI1://                 }
                         //if (intNum == 12)
                         if (intNum != 12) goto else2;
begI2://                 {
                            cout << moStr;
                            cout << 12;
                            cout << ieStr;
                            cout << endl;
                            reply = 'y';
                         goto endI2;
//                       }
else2://                 else
//                       {
                            cout << eaiStr;
                            cin >> reply;
endI2://                 }
endW1://              }
WTest1:               //if (reply != 'y' && reply != 'Y') goto begW1;
                      if (reply == 'y') goto xitW1;
                      if (reply != 'Y') goto begW1;
xitW1:
                      cout << endl;

                      cout << begA1Str;
                      hopPtr = a1;
                      endPtr = a1 + used1;
                      //while (hopPtr < endPtr)
                      goto WTest2;
begW2://              {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW2://              }
WTest2:               if (hopPtr < endPtr) goto begW2;

                      cout << endl;

                      cout << comA2Str;
                      hopPtr = a2;
                      endPtr = a2 + used2;
                      //while (hopPtr < endPtr)
                      goto WTest3;
begW3://              {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW3://              }
WTest3:               if (hopPtr < endPtr) goto begW3;

                      cout << endl;

                      //if (used1 > 0 || used2 > 0)
                      if (used1 > 0) goto begI3;
                      if (used2 <= 0) goto else3;
begI3://              {
                         hopPtr1 = a1;
                         hopPtr2 = a2;
                         hopPtr3 = a3;
                         hopPtr4 = a4;
                         endPtr1 = a1 + used1;
                         endPtr2 = a2 + used2;
                         used3 = 0;
                         used4 = 0;
                         //if (used1 > 0)
                         if (used1 <= 0) goto else4;
begI4://                 {
                            minInt = *hopPtr1;
                         goto endI4;
//                       }
else4://                 else
//                       {
                            minInt = *hopPtr2;
endI4://                 }
                         //while (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                         goto WTest4;
begW4://                 {
                            //while (hopPtr1 < endPtr1)
                            goto WTest5;
begW5://                    {
                               oneInt = *hopPtr1;
                               //if (oneInt < minInt)
                               if (oneInt >= minInt) goto endI5;
begI5://                       {
                                  minInt = oneInt;
endI5://                       }
                               //if ( (oneInt & 1) == 0 ) break;
                               if ( (oneInt & 1) == 0 ) goto brkI6;
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr1;
                               ++hopPtr3;
endW5://                    }
WTest5:                     if (hopPtr1 < endPtr1) goto begW5;
brkI6:

                            //while (hopPtr2 < endPtr2)
                            goto WTest6;
begW6://                    {
                               oneInt = *hopPtr2;
                               //if (oneInt < minInt)
                               if (oneInt >= minInt) goto endI7;
begI7://                       {
                                  minInt = oneInt;
endI7://                       }
                               //if ( (oneInt & 1) != 0 ) break;
                               if ( (oneInt & 1) != 0 ) goto brkI8;
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr2;
                               ++hopPtr4;
endW6://                    }
WTest6:                     if (hopPtr2 < endPtr2) goto begW6;
brkI8:

                            //if (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                            if (hopPtr1 >= endPtr1) goto endI9;
                            if (hopPtr2 >= endPtr2) goto endI9;
begI9://                    {
                               *hopPtr3 = *hopPtr2;
                               *hopPtr4 = *hopPtr1;
                               ++used3;
                               ++used4;
                               ++hopPtr1;
                               ++hopPtr2;
                               ++hopPtr3;
                               ++hopPtr4;
endI9://                    }
endW4://                 }
WTest4:                  //if (hopPtr1 < endPtr1 && hopPtr2 < endPtr2) goto begW4;
                         if (hopPtr1 >= endPtr1) goto xitW4;
                         if (hopPtr2 < endPtr2) goto begW4;
xitW4:

                         //while (hopPtr1 < endPtr1)
                         goto WTest7;
begW7://                 {
                            oneInt = *hopPtr1;
                            //if (oneInt < minInt)
                            if (oneInt >= minInt) goto endI10;
begI10://                   {
                               minInt = oneInt;
endI10://                   }
                            //if ( (oneInt & 1) != 0 )
                            if ( (oneInt & 1) == 0 ) goto else11;
begI11://                   {
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr3;
                            goto endI11;
//                          }
else11://                   else
//                          {
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr4;
endI11://                   }
                            ++hopPtr1;
endW7://                 }
WTest7:                  if (hopPtr1 < endPtr1) goto begW7;

                         //while (hopPtr2 < endPtr2)
                         goto WTest8;
begW8://                 {
                            oneInt = *hopPtr2;
                            //if (oneInt < minInt)
                            if (oneInt >= minInt) goto endI12;
begI12://                   {
                               minInt = oneInt;
endI12://                   }
                            //if ( (oneInt & 1) != 0 )
                            if ( (oneInt & 1) == 0 ) goto elseI13;
begI13://                   {
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr3;
                            goto endI13;
//                          }
elseI13://                  else
//                          {
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr4;
endI13://                   }
                            ++hopPtr2;
endW8://                 }
WTest8:                  if (hopPtr2 < endPtr2) goto begW8;

                      goto endI3;
//                    }
else3://              else
//                    {
                         used3 = 0;
                         used4 = 0;
endI3://              }

                      cout << comA3Str;
                      hopPtr = a3;
                      endPtr = a3 + used3;
                      //while (hopPtr < endPtr)
                      goto WTest9;
begW9://              {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW9://              }
WTest9:               if (hopPtr < endPtr) goto begW9;

                      cout << endl;

                      cout << comA4Str;
                      hopPtr = a4;
                      endPtr = a4 + used4;
                      //while (hopPtr < endPtr)
                      goto WTest10;
begW10://             {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW10://             }
WTest10:              if (hopPtr < endPtr) goto begW10;

                      cout << endl;

                      //if (used1 > 0 || used2 > 0)
                      if (used1 > 0) goto begI14;
                      if (used2 <= 0) goto endI14;
begI14://             {
                         used1 = 0;
                         used2 = 0;
                         hopPtr = a3;
                         endPtr = a3 + used3;
                         //while (hopPtr < endPtr)
                         goto WTest11;
begW11://                {
                            oneInt = *hopPtr;
                            //for (probePtr = a1 + used1; probePtr > a1; --probePtr)
                            probePtr = a1 + used1;
                            goto FTest1;
begF1://                    {
                               //if ( *(probePtr - 1) <= oneInt ) break;
                               if ( *(probePtr - 1) <= oneInt ) goto brkI15;
                               *probePtr = *(probePtr - 1);
                            --probePtr;
endF1://                    }
FTest1:                     if (probePtr > a1) goto begF1;
brkI15:

                            *probePtr = *hopPtr;
                            ++used1;
                            ++hopPtr;
endW11://                }
WTest11:                 if (hopPtr < endPtr) goto begW11;

                         hopPtr = a4;
                         endPtr = a4 + used4;
                         //while (hopPtr < endPtr)
                         goto WTest12;
begW12://                {
                            oneInt = *hopPtr;
                            //for (probePtr = a2 + used2; probePtr > a2; --probePtr)
                            probePtr = a2 + used2;
                            goto FTest2;
begF2://                    {
                               //if ( *(probePtr - 1) <= oneInt ) break;
                               if ( *(probePtr - 1) <= oneInt ) goto brkI16;
                               *probePtr = *(probePtr - 1);
                            --probePtr;
endF2://                    }
FTest2:                     if (probePtr > a2) goto begF2;
brkI16:

                            *probePtr = *hopPtr;
                            ++used2;
                            ++hopPtr;
endW12://                }
WTest12:                 if (hopPtr < endPtr) goto begW12;

                         cout << cpaA1Str;
                         hopPtr = a1;
                         endPtr = a1 + used1;
                         //while (hopPtr < endPtr)
                         goto WTest13;
begW13://                {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
endW13://                }
WTest13:                 if (hopPtr < endPtr) goto begW13;

                         cout << endl;

                         cout << comA2Str;
                         hopPtr = a2;
                         endPtr = a2 + used2;
                         //while (hopPtr < endPtr)
                         goto WTest14;
begW14://                {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
endW14://                }
WTest14:                 if (hopPtr < endPtr) goto begW14;

                         cout << endl;

                         cout << comA3Str;
                         hopPtr = a3;
                         endPtr = a3 + used3;
                         //while (hopPtr < endPtr)
                         goto WTest15;
begW15://                {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
endW15://                }
WTest15:                 if (hopPtr < endPtr) goto begW15;

                         cout << endl;

                         cout << comA4Str;
                         hopPtr = a4;
                         endPtr = a4 + used4;
                         //while (hopPtr < endPtr)
                         goto WTest16;
begW16://                {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
endW16://                }
WTest16:                 if (hopPtr < endPtr) goto begW16;

                         cout << endl;

                         used3 = 0;
                         used4 = 0;
                         //if ( (minInt & 1) != 0)
                         if ( (minInt & 1) == 0) goto else17;
begI17://                {
                            hopPtr = a3;
                            used3 = used1 + used2;
                         goto endI17;
//                       }
else17://                else
//`                      {
                            hopPtr = a4;
                            used4 = used1 + used2;
endI17://                }
                         hopPtr1 = a1;
                         hopPtr2 = a2;
                         endPtr1 = a1 + used1;
                         endPtr2 = a2 + used2;
                         //while (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                         goto WTest17;
begW17://                {
                            //if (*hopPtr1 < *hopPtr2)
                            if (*hopPtr1 >= *hopPtr2) goto elseI18;
begI18://                   {
                               *hopPtr = *hopPtr1;
                               ++hopPtr1;
                            goto endI18;
//                          }
elseI18://                  else
//                          {
                               *hopPtr = *hopPtr2;
                               ++hopPtr2;
endI18://                   }
                            ++hopPtr;
endW17://                }
WTest17:                 //if (hopPtr1 < endPtr1 && hopPtr2 < endPtr2) goto begW17;
                         if (hopPtr1 >= endPtr1) goto xitW17;
                         if (hopPtr2 < endPtr2) goto begW17;
xitW17:

                         //while (hopPtr1 < endPtr1)
                         goto WTest18;
begW18://                {
                            *hopPtr = *hopPtr1;
                            ++hopPtr1;
                            ++hopPtr;
endW18://                }
WTest18:                 if (hopPtr1 < endPtr1) goto begW18;

                         //while (hopPtr2 < endPtr2)
                         goto WTest19;
begW19://                {
                            *hopPtr = *hopPtr2;
                            ++hopPtr2;
                            ++hopPtr;
endW19://                }
WTest19:                 if (hopPtr2 < endPtr2) goto begW19;

endI14://             }

                      cout << proA1Str;
                      hopPtr = a1;
                      endPtr = a1 + used1;
                      //while (hopPtr < endPtr)
                      goto WTest20;
begW20://             {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW20://             }
WTest20:              if (hopPtr < endPtr) goto begW20;

                      cout << endl;

                      cout << comA2Str;
                      hopPtr = a2;
                      endPtr = a2 + used2;
                      //while (hopPtr < endPtr)
                      goto WTest21;
begW21://             {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW21://             }
WTest21:              if (hopPtr < endPtr) goto begW21;

                      cout << endl;

                      cout << comA3Str;
                      hopPtr = a3;
                      endPtr = a3 + used3;
                      //while (hopPtr < endPtr)
                      goto WTest22;
begW22://             {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW22://             }
WTest22:              if (hopPtr < endPtr) goto begW22;

                      cout << endl;

                      cout << comA4Str;
                      hopPtr = a4;
                      endPtr = a4 + used4;
                      //while (hopPtr < endPtr)
                      goto WTest23;
begW23://             {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
endW23://             }
WTest23:              if (hopPtr < endPtr) goto begW23;

                      cout << endl;

                      cout << endl;
                      cout << dacStr;
                      cin >> reply;
                      cout << endl;
endDW1://          }
                   //while (reply != 'n' && reply != 'N');
DWTest1:           //if (reply != 'n' && reply != 'N') goto begDW1;
                      if (reply == 'n') goto xitDW1;
                      if (reply != 'N') goto begDW1;
xitDW1:

                   cout << dlStr;
                   cout << '\n';
                   cout << byeStr;
                   cout << '\n';
                   cout << dlStr;
                   cout << '\n';

                   return 0;
}
