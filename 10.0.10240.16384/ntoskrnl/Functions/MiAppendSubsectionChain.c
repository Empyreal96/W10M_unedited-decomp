// MiAppendSubsectionChain 
 
int __fastcall MiAppendSubsectionChain(int a1, _DWORD *a2, char a3)
{
  _DWORD *v3; // r10
  int v5; // r5
  unsigned int *v7; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  int v12; // r3
  int i; // r5
  int v14; // r5
  unsigned int v15; // r1
  int v17; // [sp+4h] [bp-24h]

  v3 = *(_DWORD **)a1;
  v5 = a2[2];
  v7 = (unsigned int *)(*(_DWORD *)a1 + 36);
  v17 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51AD30();
  v9 = (unsigned __int8 *)v3 + 39;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v3 + 9);
  while ( 1 )
  {
    v11 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v11 & 0x40000000) == 0 )
    {
      do
        v15 = __ldrex(v7);
      while ( v15 == v11 && __strex(v11 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( !v3[6] )
  {
    if ( *(_DWORD *)(v5 + 4) )
    {
      do
      {
        if ( *(_DWORD *)(v5 + 32) )
          *(_DWORD *)(v5 + 32) = -1;
        *(_WORD *)(v5 + 18) &= 0xFFFEu;
        MiInsertUnusedSubsection(v5, 1);
        v5 = *(_DWORD *)(v5 + 8);
      }
      while ( v5 );
    }
LABEL_10:
    *(_WORD *)(a1 + 18) &= 0xFu;
    *(_DWORD *)(a1 + 24) = a2[6];
    *(_DWORD *)(a1 + 28) = a2[7];
    *(_DWORD *)(a1 + 36) = a2[9];
    v12 = a2[2];
    __dmb(0xBu);
    *(_DWORD *)(a1 + 8) = v12;
    for ( i = *(_DWORD *)(a1 + 8); i; i = *(_DWORD *)(i + 8) )
      MiInsertSubsectionNode(v3, i, 1);
    v14 = 0;
    if ( (dword_682604 & 0x10000) == 0 )
      goto LABEL_14;
LABEL_28:
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 9);
    goto LABEL_15;
  }
  v14 = 1;
  if ( (a3 & 1) != 0 )
    goto LABEL_10;
  if ( (dword_682604 & 0x10000) != 0 )
    goto LABEL_28;
LABEL_14:
  __dmb(0xBu);
  *v7 = 0;
LABEL_15:
  KfLowerIrql(v17);
  return v14;
}
