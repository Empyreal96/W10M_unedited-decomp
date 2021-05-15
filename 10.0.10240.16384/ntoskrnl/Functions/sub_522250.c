// sub_522250 
 
void __fastcall sub_522250(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, __int16 *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char *a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, char a28)
{
  int v28; // r4
  int v29; // r5
  int v30; // r6

  a7 = *(unsigned __int8 *)(v30 + 1052);
  a9 = &a7;
  a10 = 0;
  a11 = 2;
  a12 = 0;
  a13 = v30 + 1053;
  a14 = 0;
  a15 = 1;
  a16 = 0;
  a17 = &a28;
  a18 = 0;
  a19 = 4;
  a20 = 0;
  EtwWrite(v29, v28, (int)PPM_ETW_DELIVERED_PERF_CHANGE, 0);
  JUMPOUT(0x456416);
}
