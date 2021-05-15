// PopBatteryUpdateCompositeInformation 
 
int PopBatteryUpdateCompositeInformation()
{
  unsigned int v0; // r7
  unsigned int v1; // r8
  int v2; // r4
  unsigned int v3; // r9
  int *v4; // r2
  int v5; // r5
  int v6; // r6
  int v7; // r3
  int v8; // r3
  int v9; // r0
  int result; // r0
  int v11[16]; // [sp+18h] [bp-40h] BYREF

  memset(v11, 0, 36);
  v1 = v11[6];
  v0 = v11[7];
  v2 = v11[4];
  v3 = v11[5];
  v4 = (int *)dword_61ED7C;
  v5 = v11[3];
  v6 = v11[0];
  if ( (int *)dword_61ED7C != &dword_61ED7C )
  {
    do
    {
      v6 |= v4[8];
      v7 = v4[11];
      if ( v7 != -1 )
        v5 += v7;
      v8 = v4[12];
      if ( v8 != -1 )
        v2 += v8;
      if ( v3 < v4[13] )
      {
        v3 = v4[13];
        v11[5] = v3;
      }
      if ( v1 < v4[14] )
      {
        v1 = v4[14];
        v11[6] = v1;
      }
      if ( v0 < v4[15] )
      {
        v0 = v4[15];
        v11[7] = v0;
      }
      v4 = (int *)*v4;
    }
    while ( v4 != &dword_61ED7C );
    v11[3] = v5;
    v11[4] = v2;
    v11[0] = v6;
  }
  if ( !v2 )
    v11[4] = v5;
  memmove((int)&dword_61ED98, (int)v11, 0x24u);
  DbgPrintEx(
    146,
    2,
    (int)"\n"
         "Composite Information\n"
         "|-- Capabilities        = 0x%08x\n"
         "|-- DesignedCapacity    = %u\n"
         "|-- FullChargedCapacity = %u\n"
         "|-- DefaultAlert1       = %u\n"
         "|-- DefaultAlert2       = %u\n"
         "|-- CriticalBias        = %u\n",
    v6);
  PopAcquirePolicyLock();
  v9 = PopResetCBTriggers(128);
  if ( byte_61EA5F )
    result = sub_7F1770(v9);
  else
    result = PopReleasePolicyLock();
  return result;
}
