// PopRecordPowerButton 
 
int PopRecordPowerButton()
{
  int result; // r0
  int v1; // [sp+8h] [bp-18h] BYREF
  int v2[4]; // [sp+10h] [bp-10h] BYREF

  result = RtlLockBootStatusData(&v1);
  if ( result >= 0 )
  {
    KeQuerySystemTime(v2);
    PopBsdPowerTransition = v2[0];
    dword_63741C = v2[1];
    RtlGetSetBootStatusData(v1, 0, 7, &PopBsdPowerTransition, 32, 0);
    result = RtlUnlockBootStatusData(v1);
  }
  return result;
}
