// MiActivePageClaimCandidate 
 
int __fastcall MiActivePageClaimCandidate(int a1, int a2)
{
  __int64 v3; // r2
  int v4; // r0
  unsigned int v5; // r4
  unsigned int v6; // r9
  int result; // r0
  int v8; // r1
  int *v9; // r6
  int v10; // r3
  int v11; // r1
  unsigned int v12; // lr
  __int16 *v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // lr
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r3
  int v21; // r6
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // [sp+0h] [bp-30h]
  int v26; // [sp+8h] [bp-28h]
  unsigned int v27; // [sp+8h] [bp-28h]
  int v28[9]; // [sp+Ch] [bp-24h] BYREF

  v3 = 715827883i64 * (a1 - MmPfnDatabase);
  v4 = *(_DWORD *)(a1 + 4);
  v5 = v4 | 0x80000000;
  v6 = (SHIDWORD(v3) >> 2) + (HIDWORD(v3) >> 31);
  if ( (*(_BYTE *)(a1 + 19) & 8) != 0 )
    return 1;
  v8 = *(_DWORD *)(a1 + 20);
  if ( (v8 & 0x8000000) != 0 )
  {
    v21 = *(_DWORD *)(a1 + 12);
    if ( (v21 & 0x40000000) == 0 && v5 != dword_6337D8 )
    {
      if ( (v8 & 0xFFFFF) == 0xFFFFF )
        return (v6 & 0x3FF) + 1;
      v22 = *(unsigned __int16 *)(a1 + 16);
      if ( v22 <= 1 && v22 <= (v21 & 0x3FFFFFFFu) && *(_DWORD *)a1 && v4 < 0 )
        return 0;
    }
    return 1;
  }
  if ( v5 == -4 )
    return sub_513A94();
  v9 = MiState;
  if ( v5 >= dword_63389C )
  {
    v10 = *((unsigned __int8 *)&MiState[2423]
          + ((int)(((v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v10 == 5 || v10 == 13 )
      return 1;
  }
  if ( (v8 & 0x7000000) == 0x1000000 )
    goto LABEL_12;
  v11 = v8 & 0xFFFFF;
  if ( v11 == 1048573 )
    goto LABEL_12;
  if ( v5 + 0x40000000 > 0x3FFFFF )
    return 1;
  v12 = v5 << 10;
  if ( *(_DWORD *)a1 )
  {
    if ( PsInitialSystemProcess && v6 == *(_DWORD *)(PsInitialSystemProcess + 24) >> 12 )
      return 1;
    v27 = -1070596096;
    v24 = (((unsigned int)MmHighestUserAddress >> 20) & 0xFFC) - 1070596096;
    v28[0] = 0;
    do
    {
      if ( v5 >= v27 )
      {
        v9 = MiState;
        if ( v5 <= v24 )
          return *(unsigned __int16 *)(a1 + 16) > 1u || (*(_DWORD *)(a1 + 12) & 0x3FFFFFFFu) >= 0x10000;
      }
      v27 = ((v27 >> 10) & 0x3FFFFC) - 0x40000000;
      v24 = ((v24 >> 10) & 0x3FFFFC) - 0x40000000;
      ++v28[0];
    }
    while ( !v28[0] );
    if ( v11 == v6 )
    {
      result = 0;
      if ( v5 == -1070593024 && *(unsigned __int16 *)(a1 + 16) <= 1u )
        return result;
      return 1;
    }
    v18 = *(_DWORD *)(a1 + 12);
    v19 = v18 & 0x3FFFFFFF;
    if ( (v18 & 0x3FFFFFFFu) > 1 )
    {
      if ( v12 >= dword_63389C
        && ((v23 = *((unsigned __int8 *)v9
                   + ((int)(((v12 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)
                   + 9692),
             v23 == 14)
         || v23 == 6) )
      {
        if ( *(unsigned __int16 *)(a1 + 16) <= 1u && v19 < 0x10000 )
          return 0;
      }
      else if ( MiPageInRange(a1, -1070592000, (((unsigned int)v9[901] >> 10) & 0x3FFFFC) - 0x40000000, 0)
             && *(unsigned __int16 *)(a1 + 16) <= 1u )
      {
        return 0;
      }
      return 1;
    }
    if ( (v18 & 0xFFFFF) == 0 || v12 >= MmSessionSpace && v12 < MmSessionSpace + 12288 )
      return 1;
    v20 = *(unsigned __int16 *)(a1 + 16);
    return v20 > 1 || v20 > v19;
  }
  if ( MiPageInRange(a1, -1070592000, (((unsigned int)dword_633894 >> 10) & 0x3FFFFC) - 0x40000000, 0)
    || MiSystemWsMetaPage(a1, v28)
    || MiSessionWsMetaPage(a1) )
  {
    return 0;
  }
  v13 = MiSystemPartition;
  v14 = dword_64050C;
  v26 = dword_64050C;
  __dmb(0xBu);
  v15 = 0;
  if ( v14 )
  {
    v16 = v5 << 10;
    while ( 1 )
    {
      v28[0] = *((_DWORD *)v13 + 900);
      v17 = *(_DWORD *)(v28[0] + 108);
      if ( v16 >= v17 && v17 )
      {
        if ( v16 < v17 + 4 * *(_DWORD *)(v28[0] + 4) )
          return 0;
        v14 = v26;
      }
      ++v15;
      v13 += 2;
      if ( v15 >= v14 )
        goto LABEL_21;
    }
  }
  v16 = v5 << 10;
LABEL_21:
  if ( v16 < dword_63389C
    || *((_BYTE *)&MiState[2423] + ((int)(((v16 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 5 )
  {
    if ( (v16 < MmPfnDatabase || v16 > MmPfnDatabase + (MxPfnAllocation << 12))
      && (!PsNtosImageBase
       || (v16 < PsNtosImageBase || v16 >= PsNtosImageEnd) && (v16 < PsHalImageBase || v16 >= PsHalImageEnd)) )
    {
      return 1;
    }
LABEL_12:
    if ( ((*(char *)((v6 >> 13) + dword_634C94) >> ((v6 >> 10) & 7)) & 1) != 0 )
      return (v6 & 0x3FF) + 1;
    return 1;
  }
  if ( ((*(char *)((v6 >> 13) + dword_634C94) >> ((v6 >> 10) & 7)) & 1) != 0 )
    return (v6 & 0x3FF) + 1;
  return *(unsigned __int16 *)(a1 + 16) > 1u
      || (MiFlags & 0x800) != 0
      || a2 == 1 && ((*(_DWORD *)v5 & 2) == 0 || (*(_DWORD *)v5 & 0x100) != 0);
}
