// MiDecrementModifiedWriteCount 
 
int __fastcall MiDecrementModifiedWriteCount(int a1, int a2)
{
  unsigned int *v4; // r4
  int v5; // r7
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r4
  unsigned int v10; // r1

  if ( a2 == 1 )
    return sub_546B8C();
  v4 = (unsigned int *)(a1 + 36);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v6 = (unsigned __int8 *)v4 + 3;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v8 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(v4);
        while ( v10 == v8 && __strex(v8 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  --*(_DWORD *)(a1 + 40);
  v9 = MiBuildWakeList(a1, 8);
  if ( v5 != 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 36);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(a1 + 36) = 0;
    }
    KfLowerIrql(v5);
  }
  return v9;
}
