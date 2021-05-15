// MiUnlockPageTableRange 
 
int __fastcall MiUnlockPageTableRange(unsigned int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r7
  unsigned int v4; // r8
  int v5; // r9
  unsigned int v6; // r6
  unsigned int v7; // r4
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // t1

  v2 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v3 = (unsigned int *)(((a1 >> 20) & 0xFFC) - 1070596096);
  v4 = ((a2 >> 20) & 0xFFC) - 1070596096;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v8 = (unsigned __int8 *)v2 + 3;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v10 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex(v2);
        while ( v11 == v10 && __strex(v10 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v6 = 1;
  if ( (unsigned int)v3 > v4 )
    v7 = 0;
  else
    v7 = (v4 - (unsigned int)v3 + 4) >> 2;
  if ( v7 )
  {
    do
    {
      v12 = *v3++;
      MiUnlockPageTableCharges(MmPfnDatabase + 24 * (v12 >> 12), 2, 1);
      ++v6;
    }
    while ( v6 <= v7 );
  }
  return MiUnlockWorkingSetExclusive((int)v2, v5);
}
