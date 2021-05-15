// CmpMarkIndexDirty 
 
int __fastcall CmpMarkIndexDirty(int a1, int a2, int a3)
{
  int (__fastcall *v5)(int, int, int *); // r3
  int v6; // r0
  int v7; // r5
  unsigned __int16 v8; // r3
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r6
  int v13; // r7
  unsigned int v14; // r9
  int v15; // r10
  _WORD *v16; // r0
  int v17; // r5
  int v18; // r5
  int v19; // [sp+8h] [bp-38h] BYREF
  int v20; // [sp+Ch] [bp-34h] BYREF
  int v21; // [sp+10h] [bp-30h] BYREF
  int v22; // [sp+14h] [bp-2Ch] BYREF
  unsigned __int16 v23; // [sp+18h] [bp-28h] BYREF
  unsigned __int16 v24; // [sp+1Ah] [bp-26h]
  int v25; // [sp+1Ch] [bp-24h]

  v19 = -1;
  v20 = -1;
  v21 = -1;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v6 = v5(a1, a3, &v19);
  v7 = v6;
  if ( !v6 )
    JUMPOUT(0x7E95A4);
  if ( (*(_WORD *)(v6 + 2) & 0x20) == 0 )
    JUMPOUT(0x7E956A);
  v8 = 2 * *(_WORD *)(v6 + 72);
  v9 = v8;
  v23 = v8;
  v24 = v8;
  v10 = ExAllocatePoolWithTag(1, v8, 538987843);
  v11 = v10;
  v25 = v10;
  if ( !v10 )
    return sub_7E9560();
  CmpCopyCompressedName(v10, v9, v7 + 76, *(unsigned __int16 *)(v7 + 72));
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
  v13 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v19);
  if ( !v13 )
LABEL_22:
    JUMPOUT(0x7E9596);
  v14 = 0;
  if ( !*(_DWORD *)(a1 + 144) )
  {
LABEL_17:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
    goto LABEL_22;
  }
  while ( 1 )
  {
    if ( *(_DWORD *)(v13 + 20) )
    {
      v15 = *(_DWORD *)(v13 + 28);
      v16 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v15, &v20);
      v17 = (int)v16;
      if ( !v16 )
        goto LABEL_17;
      if ( *v16 == 26994 )
      {
        if ( CmpFindSubKeyInRoot(a1, v16, &v23, &v21) < 0 )
LABEL_23:
          JUMPOUT(0x7E9584);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v20);
        v18 = v21;
        if ( v21 == -1 )
          goto LABEL_18;
        if ( !HvpMarkCellDirty(a1, v15, 0, 0) )
          goto LABEL_17;
        v15 = v18;
        v17 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v18, &v20);
        if ( !v17 )
          goto LABEL_17;
      }
      CmpFindSubKeyInLeafWithStatus(a1, v17, &v23, &v21, &v22);
      if ( v22 < 0 )
        goto LABEL_23;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v20);
      if ( v21 != -1 )
        break;
    }
LABEL_18:
    ++v14;
    v13 += 4;
    if ( v14 >= *(_DWORD *)(a1 + 144) )
      goto LABEL_17;
  }
  ExFreePoolWithTag(v11);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
  return HvpMarkCellDirty(a1, v15, 0, 0);
}
