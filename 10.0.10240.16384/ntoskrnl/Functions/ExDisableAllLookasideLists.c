// ExDisableAllLookasideLists 
 
__int64 ExDisableAllLookasideLists()
{
  int v0; // r7
  unsigned int v1; // r2
  int *i; // r3
  int v3; // r7
  unsigned int v4; // r2
  int *j; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  __dmb(0xBu);
  ExMinimumLookasideDepth = 0;
  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ExNPagedLookasideLock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&ExNPagedLookasideLock);
    while ( __strex(1u, (unsigned int *)&ExNPagedLookasideLock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ExNPagedLookasideLock);
  }
  for ( i = (int *)ExNPagedLookasideListHead; i != &ExNPagedLookasideListHead; i = (int *)*i )
  {
    *((_WORD *)i - 19) = -1;
    *((_WORD *)i - 20) = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExNPagedLookasideLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ExNPagedLookasideLock = 0;
  }
  KfLowerIrql(v0);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ExPagedLookasideLock);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&ExPagedLookasideLock);
    while ( __strex(1u, (unsigned int *)&ExPagedLookasideLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ExPagedLookasideLock);
  }
  for ( j = (int *)ExPagedLookasideListHead; j != &ExPagedLookasideListHead; j = (int *)*j )
  {
    *((_WORD *)j - 19) = -1;
    *((_WORD *)j - 20) = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExPagedLookasideLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ExPagedLookasideLock = 0;
  }
  return KfLowerIrql(v3);
}
