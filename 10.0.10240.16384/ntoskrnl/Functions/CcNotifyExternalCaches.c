// CcNotifyExternalCaches 
 
int __fastcall CcNotifyExternalCaches(int a1)
{
  unsigned int v1; // r7
  int v2; // r6
  int v3; // r10
  int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r0
  int *v7; // r4
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int *i; // r6
  int v14; // r3
  int vars4; // [sp+24h] [bp+4h]

  v2 = a1;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&CcExternalCacheListLock);
  }
  else
  {
    v4 = 1;
    do
      v5 = __ldrex((unsigned int *)&CcExternalCacheListLock);
    while ( __strex(1u, (unsigned int *)&CcExternalCacheListLock) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&CcExternalCacheListLock);
  }
  KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2600, v4);
  v6 = CcCalculatePagesToWrite(v2, &CcGlobalDirtyPageStatistics, (int)&CcGlobalDirtyPageThresholds, 0);
  if ( v6 == -1 )
    v1 = 100;
  if ( v6 != -1 )
  {
    if ( CcGlobalDirtyPageStatistics )
      v1 = 100 * v6 / CcGlobalDirtyPageStatistics;
    else
      v1 = 0;
  }
  v7 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2600);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v7, vars4);
    goto LABEL_23;
  }
  v8 = *v7;
  if ( *v7 )
    goto LABEL_21;
  v9 = (unsigned int *)v7[1];
  __dmb(0xBu);
  do
    v10 = __ldrex(v9);
  while ( (int *)v10 == v7 && __strex(0, v9) );
  if ( (int *)v10 != v7 )
  {
    v8 = KxWaitForLockChainValid(v7);
LABEL_21:
    *v7 = 0;
    __dmb(0xBu);
    v11 = (unsigned int *)(v8 + 4);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 ^ 1, v11) );
  }
LABEL_23:
  if ( v1 )
  {
    for ( i = (int *)CcExternalCacheList; i != &CcExternalCacheList; i = (int *)*i )
    {
      v14 = *(i - 3);
      if ( v14 )
        ((void (__fastcall *)(int *, unsigned int, int))*(i - 4))(i - 4, v14 * v1 / 0x64, a1);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&CcExternalCacheListLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    CcExternalCacheListLock = 0;
  }
  return KfLowerIrql(v3);
}
