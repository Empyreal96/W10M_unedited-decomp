// MiLockDownWorkingSet 
 
unsigned int __fastcall MiLockDownWorkingSet(int a1, int a2)
{
  unsigned int *v2; // r5
  _DWORD *v3; // r9
  int v4; // r6
  int v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned __int8 *v8; // r1
  int v9; // r3
  unsigned int v10; // r2
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r4
  int v18; // [sp+0h] [bp-48h]
  int v19; // [sp+4h] [bp-44h]
  char v21[56]; // [sp+10h] [bp-38h] BYREF

  v2 = (unsigned int *)(a1 + 492);
  v3 = (_DWORD *)MEMORY[0xC04020FC];
  v19 = a1 + 492;
  KiStackAttachProcess(a1, 0, (int)v21);
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v11 = (unsigned __int8 *)v2 + 3;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v13 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v2);
        while ( v14 == v13 && __strex(v13 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v4 = 3;
  do
  {
    v5 = MmPfnDatabase + 24 * (*(_DWORD *)(((*v3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
    v6 = (unsigned __int8 *)(v5 + 15);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
    {
      v8 = (unsigned __int8 *)(v5 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v9 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v9 & 0x80000000) != 0 );
        do
          v10 = __ldrex(v8);
        while ( __strex(v10 | 0x80, v8) );
        __dmb(0xBu);
      }
      while ( v10 >> 7 );
    }
    if ( a2 == 1 )
      MiAddLockedPageCharge(v5, 1);
    else
      MiRemoveLockedPageChargeAndDecRef(v5);
    __dmb(0xBu);
    v15 = (unsigned int *)(v5 + 12);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 & 0x7FFFFFFF, v15) );
    --v4;
    v3 = (_DWORD *)((char *)v3 + MEMORY[0xC0402024]);
  }
  while ( v4 );
  MiUnlockWorkingSetExclusive(v19, v18);
  return KiUnstackDetachProcess((unsigned int)v21, 0);
}
