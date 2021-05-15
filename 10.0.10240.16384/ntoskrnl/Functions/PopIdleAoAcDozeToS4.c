// PopIdleAoAcDozeToS4 
 
int PopIdleAoAcDozeToS4()
{
  int v0; // r0
  int v1; // r4
  int v3[4]; // [sp+8h] [bp-28h] BYREF
  int v4[6]; // [sp+18h] [bp-18h] BYREF

  v0 = PopAcquirePolicyLock();
  v1 = PopIdleCheckForUserInput(v0);
  PopTraceSystemIdleS0LowPowerDoze(v1);
  if ( !v1 )
  {
    v4[2] = 0;
    v4[3] = 0;
    v4[0] = 6;
    v4[1] = 128;
    v3[2] = 0;
    v3[0] = 3;
    v3[1] = -2147483644;
    PopExecutePowerAction(v4, 0, v3, 5, 1);
  }
  return PopReleasePolicyLock();
}
