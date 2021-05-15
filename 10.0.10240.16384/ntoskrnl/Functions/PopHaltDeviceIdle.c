// PopHaltDeviceIdle 
 
int PopHaltDeviceIdle()
{
  char *v0; // r5
  int v1; // r7
  unsigned int v2; // r2
  int result; // r0
  char v4[4]; // [sp+8h] [bp-28h] BYREF
  int v5; // [sp+Ch] [bp-24h]
  int var20[10]; // [sp+10h] [bp-20h] BYREF

  v0 = 0;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopDopeGlobalLock);
  }
  else
  {
    do
      v2 = __ldrex((unsigned int *)&PopDopeGlobalLock);
    while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
  }
  byte_64B140 = 1;
  if ( dword_64B13C )
  {
    v4[0] = 1;
    v4[1] = 0;
    v4[2] = 4;
    v5 = 0;
    var20[1] = (int)var20;
    var20[0] = (int)var20;
    v0 = v4;
    PopDeviceIdleSync = (int)v4;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopDopeGlobalLock, var20[9]);
  }
  else
  {
    __dmb(0xBu);
    PopDopeGlobalLock = 0;
  }
  result = KfLowerIrql(v1);
  if ( v0 )
    result = KeWaitForSingleObject((unsigned int)v0, 0, 0, 0, 0);
  return result;
}
