// RtlTimeToElapsedTimeFields 
 
int __fastcall RtlTimeToElapsedTimeFields(_DWORD *a1, _WORD *a2, unsigned int a3, int a4)
{
  unsigned int v5; // r6
  __int16 v6; // r5
  int result; // r0
  unsigned int v8; // r4
  unsigned int v9; // [sp+0h] [bp-18h] BYREF
  int v10[5]; // [sp+4h] [bp-14h] BYREF

  v9 = a3;
  v10[0] = a4;
  sub_448178(a1, v10, &v9);
  v5 = v9 / 0x3E8;
  v6 = v9 % 0x3E8;
  result = -2004318071;
  v8 = v9 / 0x3E8 / 0x3C;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = v10[0];
  a2[3] = v8 / 0x3C;
  a2[4] = v8 % 0x3C;
  a2[5] = v5 - 60 * v8;
  a2[6] = v6;
  return result;
}
