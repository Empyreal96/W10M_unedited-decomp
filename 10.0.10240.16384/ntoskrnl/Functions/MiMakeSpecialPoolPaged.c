// MiMakeSpecialPoolPaged 
 
int __fastcall MiMakeSpecialPoolPaged(void *a1, _DWORD *a2)
{
  int v3; // r7
  int v4; // r6
  int *v5; // r5
  int v6; // r10
  int v7; // r4
  int v8; // r4
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r1
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r1

  v3 = MmPfnDatabase + 24 * (*a2 >> 12);
  if ( a1 == &unk_634D00 )
  {
    v4 = 0;
    v5 = &dword_634E80;
  }
  else
  {
    v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v5 = (int *)(v4 + 3248);
  }
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)v5);
  }
  else
  {
    v11 = (unsigned __int8 *)v5 + 3;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v5);
    while ( 1 )
    {
      v13 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex((unsigned int *)v5);
        while ( v14 == v13 && __strex(v13 | 0x40000000, (unsigned int *)v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = MiAllocateWsle((int)v5, (unsigned int)a2, v3, 0, 0, 0);
  MiUnlockWorkingSetExclusive((int)v5, v6);
  if ( v7 )
    return 1;
  v8 = KfRaiseIrql(2);
  v9 = (unsigned __int8 *)(v3 + 15);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v10 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v15 = *(_DWORD *)(v3 + 12);
      __dmb(0xBu);
    }
    while ( (v15 & 0x80000000) != 0 );
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
  }
  *(_BYTE *)(v3 + 19) |= 8u;
  __dmb(0xBu);
  v16 = (unsigned int *)(v3 + 12);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 & 0x7FFFFFFF, v16) );
  KfLowerIrql(v8);
  if ( (v5[28] & 7u) < 2 )
  {
    v18 = (unsigned int *)(v4 + 28);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 + 1, v18) );
  }
  return 0;
}
