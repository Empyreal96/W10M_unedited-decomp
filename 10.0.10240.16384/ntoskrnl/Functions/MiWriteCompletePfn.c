// MiWriteCompletePfn 
 
int __fastcall MiWriteCompletePfn(int a1, int a2)
{
  char v2; // r5
  int v3; // r7
  char v5; // r3
  __int16 v6; // r2
  unsigned int v7; // r8
  int v8; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r1
  unsigned int v14; // r1
  int v15; // r3
  char v16; // r1
  int _30; // [sp+30h] [bp+8h]

  _30 = a1;
  v2 = a2;
  v3 = 0;
  if ( (a2 & 1) == 0 )
  {
    if ( (a2 & 2) == 0 )
      goto LABEL_3;
    v11 = *(_DWORD *)(a1 + 8);
    v12 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v11 >> 2) & 1) + 1800] + 96);
    if ( (v12 & 0x10) != 0
      || (v12 & 0x20) != 0 && (v11 & 8) != 0
      || (v13 = 0, (*(_DWORD *)(a1 + 8) & 8) != 0) && (*(_BYTE *)(a1 + 23) & 7) == 2 )
    {
      v13 = 1;
    }
    v3 = *(_DWORD *)(a1 + 8);
    if ( (v3 & 0x10) != 0 )
    {
      *(_DWORD *)(a1 + 8) = v3 & 0xFFFFFFEF;
      if ( v13 )
        goto LABEL_34;
      v3 &= 0xFFFFFFF7;
    }
    else if ( !v13 || (v3 & 8) == 0 )
    {
      v3 = 0;
    }
    if ( !v13 )
      goto LABEL_3;
LABEL_34:
    *(_DWORD *)(a1 + 8) &= 0xFFFFFFF7;
    goto LABEL_3;
  }
  if ( (*(_DWORD *)(a1 + 8) & 0x400) == 0 )
    return sub_5311C8();
  *(_BYTE *)(a1 + 18) |= 0x10u;
LABEL_3:
  v5 = *(_BYTE *)(a1 + 18) & 0xF7;
  *(_BYTE *)(a1 + 18) = v5;
  if ( (v5 & 0x20) != 0 )
  {
    v14 = *(_DWORD *)(a1 + 4) << 10;
    if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0
      || v14 < dword_63389C
      || (v15 = *((unsigned __int8 *)&MiState[2423]
                + ((int)(((v14 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
          v15 != 6)
      && v15 != 14
      && v15 != 7 )
    {
      if ( (MiFlags & 0x80000) == 0 )
      {
        v16 = 6;
        if ( ((*(_DWORD *)(a1 + 8) >> 5) & 4) != 0 && ((*(_DWORD *)(a1 + 8) >> 5) & 5) != 5 )
          v16 = 7;
        MiMarkPfnVerified(a1, v16);
        v2 = a2;
      }
      *(_BYTE *)(a1 + 18) &= 0xDFu;
    }
  }
  v6 = *(_WORD *)(a1 + 16);
  *(_WORD *)(a1 + 16) = v6 - 1;
  if ( v6 != 1 )
    return v3;
  if ( (*(_DWORD *)(a1 + 8) & 0x400) == 0 && (*(_DWORD *)(a1 + 12) & 0x40000000) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 4) | 0x80000000;
    if ( v10 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
      || v10 < 0xC0000000
      || ((*(unsigned __int8 *)(a1 + 19) >> 5) & 1) == 0 )
    {
      MiReturnCommit(MiSystemPartition, 1);
      v2 = a2;
    }
  }
  v7 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
  if ( (v2 & 4) != 0 )
  {
    MiRestoreTransitionPte(a1, 2);
LABEL_22:
    MiInsertPageInFreeOrZeroedList(v7 + (v7 >> 31), 2);
    return v3;
  }
  v8 = *(_DWORD *)(a1 + 12);
  if ( (v8 & 0x3FFFFFFF) != 0 )
    KeBugCheckEx(78, 7, v7 + (v7 >> 31));
  if ( (v8 & 0x40000000) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 19) & 0x10) != 0 )
      *(_BYTE *)(a1 + 19) &= 0xEFu;
    MiReleasePageFileSpace(MiSystemPartition, *(_DWORD *)(a1 + 8), 1);
    goto LABEL_22;
  }
  if ( (*(_BYTE *)(a1 + 18) & 0x10) == 0 )
  {
    MiInsertPageInList(a1, 4);
    return v3;
  }
  MiInsertPageInList(a1, 8);
  return v3;
}
