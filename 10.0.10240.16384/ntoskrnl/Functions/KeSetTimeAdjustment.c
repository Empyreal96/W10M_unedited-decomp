// KeSetTimeAdjustment 
 
int __fastcall KeSetTimeAdjustment(__int64 a1)
{
  int v1; // r4
  __int64 v3; // r0
  int v4; // r1
  char v5[8]; // [sp+0h] [bp-30h] BYREF
  _DWORD v6[4]; // [sp+8h] [bp-28h] BYREF
  char v7; // [sp+18h] [bp-18h]

  v1 = a1;
  if ( (_DWORD)a1 == KeTimeAdjustment )
    return 0;
  if ( !(_DWORD)a1 )
    return -1073741676;
  HIDWORD(a1) = 0;
  v3 = (unsigned int)_rt_udiv64(a1, MEMORY[0xFFFF9300] * (unsigned int)KeMaximumIncrement);
  if ( (unsigned __int64)(v3 - 2) <= 0xFFFFFFFD )
  {
    v6[2] = RtlGenerateQpcToIncrementConstants(v3, v5, v3 - 2, (unsigned __int64)(v3 - 2) >> 32);
    v6[3] = v4;
    v7 = v5[0];
    v6[0] = KeTimeAdjustment;
    v6[1] = v1;
    KeTimeAdjustment = v1;
    KiUpdateSystemTime(0, 0, (int)v6, 0);
    return 0;
  }
  return -1073741675;
}
