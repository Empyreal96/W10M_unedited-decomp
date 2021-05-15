// RtlTimeToTimeFields 
 
unsigned int __fastcall RtlTimeToTimeFields(int a1, _WORD *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int result; // r0
  int v11; // r6
  __int16 v12; // lr
  __int16 v13; // r4
  unsigned int v14; // kr00_4
  _WORD *v15; // [sp+0h] [bp-20h] BYREF
  int v16[7]; // [sp+4h] [bp-1Ch] BYREF

  v15 = a2;
  v16[0] = a3;
  v16[1] = a4;
  sub_448178(a1, &v15, v16);
  v5 = (int)v15;
  v6 = (int)v15;
  a2[7] = ((unsigned int)v15 + 1) % 7;
  v7 = ElapsedDaysToYears(v6);
  v8 = v5 + -365 * v7 - v7 / 0x190 - (v7 >> 2) + v7 / 0x64;
  v9 = v7 + 1;
  if ( !((v7 + 1) % 0x190) || v9 % 0x64 && (v9 & 3) == 0 )
    return sub_51C8CC();
  v11 = *((unsigned __int8 *)NormalYearDayToMonth + v8);
  v12 = v8 - *((_WORD *)NormalYearDaysPrecedingMonth + v11);
  v13 = v16[0] % 0x3E8u;
  v14 = v16[0] / 0x3E8u;
  *a2 = v7 + 1601;
  result = v14 / 0x3C;
  a2[1] = v11 + 1;
  a2[2] = v12 + 1;
  a2[3] = v14 / 0x3C / 0x3C;
  a2[4] = v14 / 0x3C % 0x3C;
  a2[5] = v14 % 0x3C;
  a2[6] = v13;
  return result;
}
