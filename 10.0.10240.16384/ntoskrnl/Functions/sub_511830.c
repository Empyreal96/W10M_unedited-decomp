// sub_511830 
 
void __fastcall sub_511830(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r9
  unsigned int v12; // r4
  int v13; // r0
  int v14; // r7

  v11 = *(_DWORD *)(v8 + 304);
  v12 = *(_WORD *)(v11 + 2 * v7) & 0x1FFF;
  if ( *(_BYTE *)(v8 + 72) )
  {
    if ( ST_STORE<SM_TRAITS>::StStagingRegionMap(v8, v7, &a7) < 0 )
      goto LABEL_17;
    v12 = *(_WORD *)(v11 + 2 * v7) & 0x1FFF;
    if ( v12 >= *(_DWORD *)(v8 + 104) - *(_DWORD *)(v8 + 108) + 1 )
      goto LABEL_17;
    if ( (*(_WORD *)(v11 + 2 * v7) & 0x1FFF) == 0 )
    {
      if ( v7 == *(_DWORD *)(v10 + 392) )
        goto LABEL_18;
      ++*(_DWORD *)(v8 + 8 * v9 + 684);
    }
    v14 = a7;
  }
  else if ( v7 == *(_DWORD *)(v10 + 392) )
  {
    v14 = *(_DWORD *)(v10 + 400);
  }
  else
  {
    v13 = ST_STORE<SM_TRAITS>::StMapAndLockRegion(v8, v7, v9, 0);
    v14 = v13;
    if ( !v13 || v13 == -1 )
      goto LABEL_17;
    v12 = *(_WORD *)(v11 + 2 * v7) & 0x1FFF;
  }
  if ( !v12 || ST_STORE<SM_TRAITS>::StCompactRegions(v8, v14, v7, v14) >= 0 )
LABEL_18:
    JUMPOUT(0x42A2C2);
LABEL_17:
  JUMPOUT(0x42A2DE);
}
