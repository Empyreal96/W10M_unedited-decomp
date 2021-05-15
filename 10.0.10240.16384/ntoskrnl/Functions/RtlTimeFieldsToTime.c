// RtlTimeFieldsToTime 
 
int __fastcall RtlTimeFieldsToTime(__int16 *a1, _QWORD *a2)
{
  int v2; // r2
  unsigned int v3; // r5
  int v4; // r3
  unsigned int v5; // r9
  unsigned int v6; // r10
  unsigned int v7; // r1
  unsigned int v8; // r0
  __int16 v9; // r4
  unsigned int v10; // r6
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int result; // r0
  unsigned int v15; // [sp+4h] [bp-2Ch]
  int v16; // [sp+8h] [bp-28h]

  v2 = a1[2];
  v3 = *a1;
  v4 = a1[1];
  v5 = a1[3];
  v6 = a1[4];
  v7 = a1[5];
  v8 = a1[6];
  v9 = v2 - 1;
  v10 = v4 - 1;
  v15 = v8;
  v16 = v2 - 1;
  if ( v4 < 1 || v2 < 1 || v3 - 1601 > 0x722A || v10 > 0xB )
    return 0;
  if ( v3 % 0x190 && (!(v3 % 0x64) || (v3 & 3) != 0) )
  {
    v11 = *((__int16 *)NormalYearDaysPrecedingMonth + v10 + 1);
    v12 = *((__int16 *)NormalYearDaysPrecedingMonth + v10);
  }
  else
  {
    v11 = *((__int16 *)LeapYearDaysPrecedingMonth + v10 + 1);
    v12 = *((__int16 *)LeapYearDaysPrecedingMonth + v10);
  }
  if ( v9 >= v11 - v12 || v5 > 0x17 || v6 > 0x3B || v7 > 0x3B || v8 > 0x3E7 )
    return 0;
  if ( (v3 - 1600) % 0x190 && (!((v3 - 1600) % 0x64) || (v3 & 3) != 0) )
    v13 = *((__int16 *)NormalYearDaysPrecedingMonth + v10);
  else
    v13 = *((__int16 *)LeapYearDaysPrecedingMonth + v10);
  result = 1;
  *a2 = 10000
      * (86400000i64
       * (int)(v13 + (v3 - 1601) / 0x190 - (v3 - 1601) / 0x64 + 365 * (v3 - 1601) + ((v3 - 1601) >> 2) + v16)
       + v15
       + 1000 * (v7 + 60 * (v6 + 60 * v5)));
  return result;
}
