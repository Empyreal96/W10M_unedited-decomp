// sub_52B508 
 
void __fastcall sub_52B508(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, int *a9, int a10, int a11, int a12, __int16 *a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
  int v20; // r4
  int v21; // r5
  int v22; // r6
  int v23; // r7
  int *v24; // r2

  a9 = &PpmCheckTime;
  a10 = 0;
  a11 = 8;
  a12 = 0;
  a7 = *(unsigned __int8 *)(v23 + 1052);
  a13 = &a7;
  a14 = 0;
  a15 = 2;
  a16 = 0;
  a17 = v23 + 1053;
  a18 = 0;
  a19 = 1;
  a20 = 0;
  if ( v22 )
    v24 = PPM_ETW_PARK_CORE;
  else
    v24 = PPM_ETW_UNPARK_CORE;
  EtwWrite(v21, v20, (int)v24, 0);
  JUMPOUT(0x46D3CC);
}
