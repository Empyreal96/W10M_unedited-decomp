// PfpStartLoggingHardFaultEvents 
 
int PfpStartLoggingHardFaultEvents()
{
  _DWORD *v0; // r6
  int v2; // r8
  unsigned int v3; // r1
  unsigned int v4; // r0
  unsigned int v5; // r1
  int vars4; // [sp+2Ch] [bp+4h]

  v0 = (_DWORD *)ExAllocatePoolWithTag(512, 104, 1146119760);
  if ( !v0 )
    return -1073741670;
  v0[24] = 0;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_6372D0);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&dword_6372D0);
    while ( __strex(1u, (unsigned int *)&dword_6372D0) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6372D0);
  }
  v0[25] = ++dword_6372D8;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_643B6C);
  while ( __strex(v4 | 1, (unsigned int *)&dword_643B6C) );
  __dmb(0xBu);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_6372D0, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_6372D0 = 0;
  }
  KfLowerIrql(v2);
  KeInitializeTimerEx(v0 + 8, 0);
  KeInitializeDpc((int)v0, (int)PfpPowerActionDpcRoutine, (int)v0);
  KiSetTimerEx((int)(v0 + 8), v5, -200000000i64, 0, 0, (int)v0);
  return 0;
}
