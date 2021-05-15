// sub_53FC0C 
 
void __fastcall sub_53FC0C(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, unsigned int a8, unsigned int a9, unsigned int a10, int a11, int a12, int *a13, int a14, int a15, int a16, int *a17, int a18, int a19, int a20, int *a21, int a22, int a23, int a24, int *a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, __int16 *a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40)
{
  int v40; // r6
  int v41; // r7
  int v42; // r8
  int v43; // r3
  unsigned int v44; // r4
  unsigned int v45; // r5
  unsigned int v46; // r3
  int v47; // r3

  a13 = &PpmCheckTime;
  a14 = 0;
  a15 = 8;
  a16 = 0;
  v43 = *(_DWORD *)(v40 + 3204);
  if ( v43 )
    v44 = *(_DWORD *)(v43 + 44);
  else
    v44 = 100;
  a10 = v44;
  v45 = _rt_udiv64(10000i64, PpmCheckPeriod);
  if ( !v44 )
    __brkdiv0();
  v46 = (*(_DWORD *)(v40 + 3240) / v44 * v45 + 50) / 0x64;
  a8 = v46;
  if ( v46 <= v45 )
  {
    a9 = 0;
    v47 = v45 - v46;
  }
  else
  {
    a8 = v45;
    a9 = v46 - v45;
    v47 = 0;
  }
  a11 = v47;
  a17 = &a11;
  a18 = 0;
  a19 = 4;
  a20 = 0;
  a21 = (int *)&a8;
  a22 = 0;
  a23 = 4;
  a24 = 0;
  a25 = (int *)&a9;
  a26 = 0;
  a27 = 4;
  a28 = 0;
  a29 = (int *)&a10;
  a30 = 0;
  a31 = 4;
  a32 = 0;
  a7 = *(unsigned __int8 *)(v40 + 1052);
  a33 = &a7;
  a34 = 0;
  a35 = 2;
  a36 = 0;
  a37 = v40 + 1053;
  a38 = 0;
  a39 = 1;
  a40 = 0;
  EtwWrite(v42, v41, (int)PPM_ETW_EXPECTED_UTILITY, 0);
  JUMPOUT(0x4AB118);
}
