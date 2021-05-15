// IopFindPassiveInterruptBlock 
 
int __fastcall IopFindPassiveInterruptBlock(int a1)
{
  int v2; // r6
  unsigned int v4; // r2
  int v5; // r5

  v2 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51FCC4();
  do
    v4 = __ldrex((unsigned int *)&PassiveInterruptListLock);
  while ( __strex(1u, (unsigned int *)&PassiveInterruptListLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&PassiveInterruptListLock);
  v5 = IopFindPassiveInterruptBlockLocked(a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PassiveInterruptListLock);
  }
  else
  {
    __dmb(0xBu);
    PassiveInterruptListLock = 0;
  }
  KfLowerIrql(v2);
  return v5;
}
