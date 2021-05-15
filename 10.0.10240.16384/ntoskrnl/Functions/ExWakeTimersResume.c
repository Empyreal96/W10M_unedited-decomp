// ExWakeTimersResume 
 
unsigned int ExWakeTimersResume()
{
  int v0; // r0
  int v1; // r1
  int v2; // r10
  int *v3; // r5
  int v4; // r6
  unsigned int *v5; // r4
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r7
  unsigned int v9; // r1
  int v11; // [sp+0h] [bp-28h]
  int v12; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  v12 = KfRaiseIrql(2);
  v0 = KeQueryInterruptTime();
  v2 = v1;
  v11 = v0;
  v3 = (int *)ExpWakeTimerList;
  while ( v3 != &ExpWakeTimerList )
  {
    v4 = (int)(v3 - 38);
    v3 = (int *)*v3;
    v5 = (unsigned int *)(v4 + 48);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v4 + 48);
    }
    else
    {
      v6 = 1;
      do
        v7 = __ldrex(v5);
      while ( __strex(1u, v5) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v4 + 48));
    }
    v8 = *(_DWORD *)(v4 + 148);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v4 + 48), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    if ( v8 )
      ExpTimerResume(v4, v6, v11, v2);
  }
  KfLowerIrql(v12);
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&ExpWakeTimerLock);
  while ( __strex(v9 - 1, (unsigned int *)&ExpWakeTimerLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpWakeTimerLock);
  return KeAbPostRelease((unsigned int)&ExpWakeTimerLock);
}
