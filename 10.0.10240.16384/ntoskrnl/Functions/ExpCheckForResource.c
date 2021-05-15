// ExpCheckForResource 
 
int __fastcall ExpCheckForResource(unsigned int a1, int a2)
{
  int v4; // r10
  int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r1
  int *i; // r4
  unsigned int v9; // r1
  unsigned int v10; // r2

  __dmb(0xBu);
  __dmb(0xBu);
  if ( ((MmVerifierData & 0x800) == 0 || !VfCheckForResource())
    && (unsigned int)KeNumberProcessors_0 <= 1
    && (ExResourceCheckFlags & 1) != 0 )
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&ExpResourceSpinLock);
    }
    else
    {
      v5 = ExpResourceSpinLock & 0x7FFFFFFF;
      v6 = (ExpResourceSpinLock & 0x7FFFFFFF) + 1;
      do
        v7 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( v7 == v5 && __strex(v6, (unsigned int *)&ExpResourceSpinLock) );
      __dmb(0xBu);
      if ( v7 != v5 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ExpResourceSpinLock);
    }
    for ( i = (int *)ExpSystemResourcesList; i != &ExpSystemResourcesList; i = (int *)*i )
    {
      if ( (unsigned int)i >= a1 && (unsigned int)i < a1 + a2 )
      {
        DbgPrintEx(
          0,
          0,
          (int)"EX: ExFreePool( %p, %Ix ) contains an ERESOURCE structure that has not been ExDeleteResourced\n",
          a1);
        __debugbreak();
      }
      __dmb(0xBu);
      __dmb(0xBu);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ExpResourceSpinLock);
    }
    else
    {
      __dmb(0xBu);
      do
        v9 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( __strex(v9 & 0xBFFFFFFF, (unsigned int *)&ExpResourceSpinLock) );
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( __strex(v10 - 1, (unsigned int *)&ExpResourceSpinLock) );
    }
    KfLowerIrql(v4);
  }
  return 0;
}
