// MiCountSystemImageCommitment 
 
int __fastcall MiCountSystemImageCommitment(_DWORD *a1)
{
  unsigned int v2; // r5
  int v3; // r0
  _DWORD *v4; // r6
  unsigned int *v5; // r8
  unsigned int *v7; // r7
  int v8; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  _DWORD *v12; // r0
  int v13; // r5
  int v14; // r6
  unsigned int v15; // r1
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  _DWORD *v20; // [sp+0h] [bp-38h]
  int v21; // [sp+8h] [bp-30h]
  int v22; // [sp+10h] [bp-28h]
  int v23; // [sp+14h] [bp-24h]
  int v24; // [sp+18h] [bp-20h]

  if ( (a1[28] & 7) != 0 )
    return a1[8] >> 12;
  v2 = a1[6];
  if ( (*(_DWORD *)(((v2 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return a1[8] >> 12;
  v3 = a1[15];
  if ( !v3 )
    return a1[8] >> 12;
  v4 = (_DWORD *)MiSectionControlArea(v3);
  if ( !v4[22] )
    return a1[8] >> 12;
  v21 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = (unsigned int *)v21;
  if ( v2 < dword_63389C )
    JUMPOUT(0x55290A);
  if ( *((_BYTE *)&MiState[2423] + ((int)(((v2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 11 )
    return sub_552904();
  v7 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
  v8 = 0;
  v23 = *(_BYTE *)(*v4 + 10) & 1;
  v22 = MiFreePrivateFixupEntryForSystemImage(v2, 0);
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
  }
  else
  {
    v9 = (unsigned __int8 *)v7 + 3;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v7);
    while ( 1 )
    {
      v11 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex(v7);
        while ( v19 == v11 && __strex(v11 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v12 = v4 + 20;
  v20 = v4 + 20;
  if ( v4 != (_DWORD *)-80 )
  {
    while ( (v12[4] & 0x3Eu) >= 8 || v12[3] )
    {
      v18 = v12[7];
      v5 += v18;
      v8 += v18;
LABEL_28:
      v12 = (_DWORD *)v12[2];
      v20 = v12;
      if ( !v12 )
        goto LABEL_29;
    }
    v13 = v12[7];
    if ( !v13 )
      goto LABEL_28;
    v14 = (int)v5 - v21;
    while ( 1 )
    {
      if ( v22
        && ((*(char *)(((unsigned int)(v14 >> 2) >> 3) + *(_DWORD *)(*(_DWORD *)(v22 + 20) + 4)) >> ((v14 >> 2) & 7)) & 1) != 0 )
      {
        goto LABEL_36;
      }
      v15 = *v5;
      if ( *v5 )
        break;
LABEL_26:
      v14 += 4;
      --v13;
      ++v5;
      if ( !v13 )
      {
        v12 = v20;
        goto LABEL_28;
      }
    }
    if ( v23 != 1 )
    {
      if ( (v15 & 2) != 0 )
      {
        v17 = MmPfnDatabase + 24 * (v15 >> 12);
        if ( *(_DWORD *)v17
          && (*(_BYTE *)(v17 + 19) & 8) == 0
          && (*(_DWORD *)(v17 + 20) & 0x8000000) != 0
          && *(int *)(v17 + 4) < 0
          && (*(_DWORD *)(v17 + 8) & 0x400) != 0 )
        {
          goto LABEL_26;
        }
      }
      else if ( (v15 & 0x400) != 0 )
      {
        if ( (v15 & 0xFFFFE000) == -8192 )
          goto LABEL_26;
        v16 = (*v5 & 0x1FC | (*v5 >> 2) & 0x3FFFFE00) - 0x40000000;
        if ( v16 >= dword_640488 || v16 < dword_640484 )
          goto LABEL_26;
      }
    }
LABEL_36:
    ++v8;
    goto LABEL_26;
  }
LABEL_29:
  MiUnlockWorkingSetExclusive((int)v7, v24);
  return v8;
}
