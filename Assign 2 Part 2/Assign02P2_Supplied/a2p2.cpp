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
    i,
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
                   do
                   {								
                      intNum = 0;
                      used1 = 0;
                      used2 = 0;
                      hopPtr1 = a1;
                      hopPtr2 = a2;
                      cout << eaiStr;
                      cin >> reply;
                      while (reply != 'y' && reply != 'Y')
                      {
                         ++intNum;
                         cout << einStr;
                         cout << intNum;
                         cout << ':' << ' ';
                         cin >> oneInt;
                         if ( (intNum & 1) != 0 )
                         {
                            *hopPtr1 = oneInt;
                            ++hopPtr1;
                            ++used1;
                         }
                         else
                         {
                            *hopPtr2 = oneInt;
                            ++hopPtr2;
                            ++used2;
                         }
                         if (intNum == 12)
                         {
                            cout << moStr;
                            cout << 12;
                            cout << ieStr;
                            cout << endl;
                            reply = 'y';
                         }
                         else
                         {
                            cout << eaiStr;
                            cin >> reply;
                         }
                      }
                      cout << endl;

                      cout << begA1Str;
                      hopPtr = a1;
                      endPtr = a1 + used1;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << comA2Str;
                      hopPtr = a2;
                      endPtr = a2 + used2;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      if (used1 > 0 || used2 > 0)
                      {
                         hopPtr1 = a1;
                         hopPtr2 = a2;
                         hopPtr3 = a3;
                         hopPtr4 = a4;
                         endPtr1 = a1 + used1;
                         endPtr2 = a2 + used2;
                         used3 = 0;
                         used4 = 0;
                         if (used1 > 0)
                         {
                            minInt = *hopPtr1;
                         }
                         else
                         {
                            minInt = *hopPtr2;
                         }
                         while (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                         {
                            while (hopPtr1 < endPtr1)
                            {
                               oneInt = *hopPtr1;
                               if (oneInt < minInt)
                               {
                                  minInt = oneInt;
                               }
                               if ( (oneInt & 1) == 0 ) break;
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr1;
                               ++hopPtr3;
                            }
                            while (hopPtr2 < endPtr2)
                            {
                               oneInt = *hopPtr2;
                               if (oneInt < minInt)
                               {
                                  minInt = oneInt;
                               }
                               if ( (oneInt & 1) != 0 ) break;
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr2;
                               ++hopPtr4;
                            }
                            if (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                            {
                               *hopPtr3 = *hopPtr2;
                               *hopPtr4 = *hopPtr1;
                               ++used3;
                               ++used4;
                               ++hopPtr1;
                               ++hopPtr2;
                               ++hopPtr3;
                               ++hopPtr4;
                            }
                         }
                         while (hopPtr1 < endPtr1)
                         {
                            oneInt = *hopPtr1;
                            if (oneInt < minInt)
                            {
                               minInt = oneInt;
                            }
                            if ( (oneInt & 1) != 0 )
                            {
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr3;
                            }
                            else
                            {
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr4;
                            }
                            ++hopPtr1;
                         }
                         while (hopPtr2 < endPtr2)
                         {
                            oneInt = *hopPtr2;
                            if (oneInt < minInt)
                            {
                               minInt = oneInt;
                            }
                            if ( (oneInt & 1) != 0 )
                            {
                               *hopPtr3 = oneInt;
                               ++used3;
                               ++hopPtr3;
                            }
                            else
                            {
                               *hopPtr4 = oneInt;
                               ++used4;
                               ++hopPtr4;
                            }
                            ++hopPtr2;
                         }
                      }
                      else
                      {
                         used3 = 0;
                         used4 = 0;
                      }

                      cout << comA3Str;
                      hopPtr = a3;
                      endPtr = a3 + used3;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << comA4Str;
                      hopPtr = a4;
                      endPtr = a4 + used4;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      if (used1 > 0 || used2 > 0)
                      {
                         used1 = 0;
                         used2 = 0;
                         hopPtr = a3;
                         endPtr = a3 + used3;
                         while (hopPtr < endPtr)
                         {
                            oneInt = *hopPtr;
                            for (probePtr = a1 + used1; probePtr > a1; --probePtr)
                            {
                               if ( *(probePtr - 1) <= oneInt ) break;
                               *probePtr = *(probePtr - 1);
                            }
                            *probePtr = *hopPtr;
                            ++used1;
                            ++hopPtr;
                         }
                         hopPtr = a4;
                         endPtr = a4 + used4;
                         while (hopPtr < endPtr)
                         {
                            oneInt = *hopPtr;
                            for (probePtr = a2 + used2; probePtr > a2; --probePtr)
                            {
                               if ( *(probePtr - 1) <= oneInt ) break;
                               *probePtr = *(probePtr - 1);
                            }
                            *probePtr = *hopPtr;
                            ++used2;
                            ++hopPtr;
                         }

                         cout << cpaA1Str;
                         hopPtr = a1;
                         endPtr = a1 + used1;
                         while (hopPtr < endPtr)
                         {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
                         }
                         cout << endl;

                         cout << comA2Str;
                         hopPtr = a2;
                         endPtr = a2 + used2;
                         while (hopPtr < endPtr)
                         {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
                         }
                         cout << endl;

                         cout << comA3Str;
                         hopPtr = a3;
                         endPtr = a3 + used3;
                         while (hopPtr < endPtr)
                         {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
                         }
                         cout << endl;

                         cout << comA4Str;
                         hopPtr = a4;
                         endPtr = a4 + used4;
                         while (hopPtr < endPtr)
                         {
                            cout << *hopPtr << ' ' << ' ';
                            ++hopPtr;
                         }
                         cout << endl;

                         used3 = 0;
                         used4 = 0;
                         if ( (minInt & 1) != 0)
                         {
                            hopPtr = a3;
                            used3 = used1 + used2;
                         }
                         else
                         {
                            hopPtr = a4;
                            used4 = used1 + used2;
                         }
                         hopPtr1 = a1;
                         hopPtr2 = a2;
                         endPtr1 = a1 + used1;
                         endPtr2 = a2 + used2;
                         while (hopPtr1 < endPtr1 && hopPtr2 < endPtr2)
                         {
                            if (*hopPtr1 < *hopPtr2)
                            {
                               *hopPtr = *hopPtr1;
                               ++hopPtr1;
                            }
                            else
                            {
                               *hopPtr = *hopPtr2;
                               ++hopPtr2;
                            }
                            ++hopPtr;
                         }
                         while (hopPtr1 < endPtr1)
                         {
                            *hopPtr = *hopPtr1;
                            ++hopPtr1;
                            ++hopPtr;
                         }
                         while (hopPtr2 < endPtr2)
                         {
                            *hopPtr = *hopPtr2;
                            ++hopPtr2;
                            ++hopPtr;
                         }
                      }

                      cout << proA1Str;
                      hopPtr = a1;
                      endPtr = a1 + used1;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << comA2Str;
                      hopPtr = a2;
                      endPtr = a2 + used2;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << comA3Str;
                      hopPtr = a3;
                      endPtr = a3 + used3;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << comA4Str;
                      hopPtr = a4;
                      endPtr = a4 + used4;
                      while (hopPtr < endPtr)
                      {
                         cout << *hopPtr << ' ' << ' ';
                         ++hopPtr;
                      }
                      cout << endl;

                      cout << endl;
                      cout << dacStr;
                      cin >> reply;
                      cout << endl;
                   }
                   while (reply != 'n' && reply != 'N');

                   cout << dlStr;
                   cout << '\n';
                   cout << byeStr;
                   cout << '\n';
                   cout << dlStr;
                   cout << '\n';

                   return 0;
}
