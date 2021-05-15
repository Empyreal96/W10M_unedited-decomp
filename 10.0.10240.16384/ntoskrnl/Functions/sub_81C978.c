// sub_81C978 
 
void __fastcall sub_81C978(int a1, int a2, int a3, int a4, int a5, int a6, BOOL a7, int a8, char *a9, int a10, int a11, int a12, char *a13, int a14, int a15, int a16, BOOL *a17, int a18, int a19, int a20, char *a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, char a31, char a32, int a33, char a34)
{
  int v34; // r4
  int v35; // r5
  int v36; // r6

  a7 = v34 == 0;
  a9 = &a31;
  a10 = 0;
  a11 = 4;
  a12 = 0;
  a13 = &a32;
  a14 = 0;
  a15 = 4;
  a16 = 0;
  a17 = &a7;
  a18 = 0;
  a19 = 4;
  a20 = 0;
  a21 = &a34;
  a22 = 0;
  a23 = 4;
  a24 = 0;
  EtwWrite(v36, v35, (int)BATTERY_EVT_BATTERY_PERCENT_REMAINING, 0);
  JUMPOUT(0x7BCEAA);
}
