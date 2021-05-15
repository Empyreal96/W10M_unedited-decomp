// PopIdleAoAcDozeS4TimerCallback 
 
int PopIdleAoAcDozeS4TimerCallback()
{
  int v0; // r6
  unsigned int v1; // r2
  int vars4; // [sp+14h] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopIdleAoAcDozeS4Lock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&PopIdleAoAcDozeS4Lock);
    while ( __strex(1u, (unsigned int *)&PopIdleAoAcDozeS4Lock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopIdleAoAcDozeS4Lock);
  }
  byte_61E83C = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopIdleAoAcDozeS4Lock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopIdleAoAcDozeS4Lock = 0;
  }
  KfLowerIrql(v0);
  return ExQueueWorkItem(&PopIdleAoAcDozeS4WorkItem, 1);
}
