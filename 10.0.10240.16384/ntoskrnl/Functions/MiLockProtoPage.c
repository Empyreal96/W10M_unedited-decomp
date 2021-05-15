// MiLockProtoPage 
 
int __fastcall MiLockProtoPage(unsigned int a1, unsigned int a2, int a3)
{
  int v5; // r6
  int v6; // r5
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned int *v12; // r5
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r6
  unsigned int v18; // r1
  int v19; // lr
  unsigned int v20; // r0
  int v21; // [sp+0h] [bp-28h]
  _DWORD *v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h]

  v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( !a2 )
    goto LABEL_11;
  v6 = MmPfnDatabase + 24 * (*(_DWORD *)(((a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v21 = KfRaiseIrql(2);
  v7 = (unsigned __int8 *)(v6 + 15);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    return sub_51CAC0();
  MiRemoveLockedPageChargeAndDecRef(v6);
  __dmb(0xBu);
  v10 = (unsigned int *)(v6 + 12);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  KfLowerIrql(v21);
  if ( !a1 )
    return 0;
LABEL_11:
  v12 = (unsigned int *)(v5 + 492);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5 + 492);
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0xBFFFFFFF, v12) );
    __dmb(0xBu);
    do
      v14 = __ldrex(v12);
    while ( __strex(v14 - 1, v12) );
  }
  KfLowerIrql(a3);
  MiMakeProtoAddressValid(a1);
  v22 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (*v22 & 0x10) == 0 )
  {
    v23 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      v17 = 2304;
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E80);
    }
    else
    {
      do
        v18 = __ldrex((unsigned __int8 *)&dword_634E80 + 3);
      while ( __strex(v18 | 0x80, (unsigned __int8 *)&dword_634E80 + 3) );
      __dmb(0xBu);
      v17 = 0x900u;
      if ( v18 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E80);
      while ( 1 )
      {
        v19 = dword_634E80;
        if ( (dword_634E80 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_634E80 & 0x40000000) == 0 )
        {
          do
            v20 = __ldrex((unsigned int *)&dword_634E80);
          while ( v20 == v19 && __strex(v19 | 0x40000000, (unsigned int *)&dword_634E80) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    MI_WRITE_VALID_PTE_VOLATILE(v22, 1);
    MiUnlockWorkingSetExclusive(&MiState[v17], v23);
    KeFlushSingleTb(a1, 1);
  }
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v12);
  }
  else
  {
    v15 = *v12 & 0x7FFFFFFF;
    do
      v16 = __ldrex(v12);
    while ( v16 == v15 && __strex(v15 + 1, v12) );
    __dmb(0xBu);
    if ( v16 != v15 )
      ExpWaitForSpinLockSharedAndAcquire(v12, v16);
  }
  return a1;
}
