// ExInitializeResourceLite 
 
int __fastcall ExInitializeResourceLite(int a1)
{
  _BYTE *v2; // r0
  int v4; // r8
  unsigned int v5; // r1
  int v6; // r6
  int **v7; // r1
  unsigned int v8; // r3
  unsigned int v9; // r1

  v2 = memset((_BYTE *)a1, 0, 56);
  if ( (NtGlobalFlag & 0x2000) != 0 )
    return sub_50A480(v2);
  *(_DWORD *)(a1 + 48) = 0;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&ExpResourceSpinLock);
  }
  else
  {
    do
      v5 = __ldrex((unsigned __int8 *)&ExpResourceSpinLock + 3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)&ExpResourceSpinLock + 3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(&ExpResourceSpinLock);
    while ( 1 )
    {
      v6 = ExpResourceSpinLock;
      if ( (ExpResourceSpinLock & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (ExpResourceSpinLock & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex((unsigned int *)&ExpResourceSpinLock);
        while ( v9 == v6 && __strex(v6 | 0x40000000, (unsigned int *)&ExpResourceSpinLock) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = (int **)dword_61A0E4;
  *(_DWORD *)a1 = &ExpSystemResourcesList;
  *(_DWORD *)(a1 + 4) = v7;
  if ( *v7 != &ExpSystemResourcesList )
    __fastfail(3u);
  *v7 = (int *)a1;
  dword_61A0E4 = a1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpResourceSpinLock);
  }
  else
  {
    __dmb(0xBu);
    ExpResourceSpinLock = 0;
  }
  KfLowerIrql(v4);
  v8 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v8 & 0xFFFFF000) + 0x1418);
  if ( (dword_682604 & 0x20000) != 0 )
    PerfLogExecutiveResourceInitialize(65544, a1, 0, 0);
  return 0;
}
