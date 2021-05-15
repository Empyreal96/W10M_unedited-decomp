// sub_552628 
 
void __fastcall sub_552628(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  unsigned int v14; // r4
  int v15; // r8
  int v16; // r0
  int v17; // r4
  int v18; // r7
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  int v21; // r2
  _WORD *v22; // r9
  int v23; // r6
  int v24; // r3
  unsigned int v25; // r2
  int v26; // r3
  char v27; // r3
  unsigned int *v28; // r1
  unsigned int i; // r6
  unsigned int v30; // r2
  unsigned int *v31; // r2
  unsigned int v32; // r0
  char v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r0

  v16 = MI_IS_PFN(v14);
  if ( !v16 || (v17 = MmPfnDatabase + 24 * v14, (*(_BYTE *)(v17 + 18) & 0x10) != 0) )
    JUMPOUT(0x4F1CDE);
  v18 = 17;
  if ( (unsigned int)KeGetCurrentIrql(v16) <= 2 )
    v18 = KfRaiseIrql(2);
  v19 = (unsigned __int8 *)(v17 + 15);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 | 0x80, v19) );
  __dmb(0xBu);
  if ( v20 >> 7 )
  {
    if ( v18 != 17 )
      KfLowerIrql(v18);
    goto LABEL_55;
  }
  v21 = *(_DWORD *)(v17 + 8);
  if ( (v21 & 0x400) == 0 )
  {
    if ( (*(_BYTE *)(v17 + 18) & 8) == 0 && (v21 & 0x10) != 0 )
    {
      v28 = (unsigned int *)(v15 + 6928);
      for ( i = 0; i < 0x20; ++i )
      {
        do
          v30 = __ldrex(v28);
        while ( !v30 && __strex(v17, v28) );
        if ( !v30 )
          break;
        if ( (v30 | 1) == (v17 | 1) )
          goto LABEL_50;
        ++v28;
      }
      if ( i != 32 )
      {
        if ( *(unsigned __int16 *)(v17 + 16) == -1 )
        {
          __dmb(0xBu);
          v31 = (unsigned int *)(v15 + 6928 + 4 * i);
          do
            v32 = __ldrex(v31);
          while ( __strex(0, v31) );
        }
        else
        {
          v33 = 1;
          if ( v18 == 17 )
            v33 = 5;
          MiAddLockedPageCharge(v17, v33);
          v34 = (unsigned int *)(v15 + 6928 + 4 * i);
          do
            v35 = __ldrex(v34);
          while ( __strex(v35 + 1, v34) );
          __dmb(0xBu);
          do
            v36 = __ldrex((unsigned int *)&ExpDebuggerWork);
          while ( !v36 && __strex(1u, (unsigned int *)&ExpDebuggerWork) );
        }
      }
      goto LABEL_50;
    }
    v27 = *(_BYTE *)(v17 + 18) | 0x10;
    goto LABEL_49;
  }
  if ( (*(_BYTE *)(v17 + 18) & 0x10) == 0 )
  {
    v22 = (_WORD *)(*(_DWORD *)(v17 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v17 + 8) & 0x3FC)));
    v23 = *(_DWORD *)v22;
    v24 = *(_DWORD *)(*(_DWORD *)v22 + 28);
    if ( (v24 & 0x20) == 0 )
    {
LABEL_26:
      v27 = *(_BYTE *)(v17 + 18) | 0x10;
LABEL_49:
      *(_BYTE *)(v17 + 18) = v27;
      goto LABEL_50;
    }
    if ( (v24 & 0x40000) != 0 || !**(_DWORD **)(v23 + 56) )
    {
LABEL_20:
      if ( (v22[8] & 0x3Eu) < 8 )
      {
        v25 = *(_DWORD *)(v15 + 3612);
        if ( a5 >= v25 )
        {
          v26 = *(unsigned __int8 *)(v15 + ((int)(((a5 >> 20) & 0xFFC) - ((v25 >> 20) & 0xFFC)) >> 2) + 9692);
          if ( v26 == 1 || v26 == 11 )
            *(_BYTE *)(v15 + 1272) = 1;
        }
      }
      *(_BYTE *)(v15 + 6913) = 1;
      goto LABEL_26;
    }
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)(v23 + 36)) )
    {
      *(_DWORD *)(v23 + 28) |= 0x40000u;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v23 + 36), a14);
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)(v23 + 36) = 0;
      }
      goto LABEL_20;
    }
  }
LABEL_50:
  __dmb(0xBu);
  v37 = (unsigned int *)(v17 + 12);
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 & 0x7FFFFFFF, v37) );
  if ( v18 != 17 )
    KfLowerIrql(v18);
LABEL_55:
  JUMPOUT(0x4F1CE0);
}
