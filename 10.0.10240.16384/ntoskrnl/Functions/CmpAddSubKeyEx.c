// CmpAddSubKeyEx 
 
int __fastcall CmpAddSubKeyEx(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int (__fastcall *v7)(int, unsigned int, int *); // r4
  __int16 *v8; // r6
  unsigned int v9; // r10
  int v10; // r0
  int v11; // r4
  int v13; // r9
  int (__fastcall *v14)(int, _DWORD, int); // r3
  int v15; // r0
  int v16; // r0
  int v17; // r8
  unsigned int v18; // r4
  unsigned __int16 *v19; // r0
  int v20; // r1
  int v21; // r1
  __int16 v22; // r7
  int v23; // r0
  int v24; // r0
  int *v25; // r7
  int v26; // r0
  unsigned int v27; // r1
  __int16 *v28; // r0
  __int16 *v29; // r2
  int v30; // r3
  int v31; // r0
  unsigned int v32; // r6
  int v33; // r0
  int v34; // r4
  unsigned int v35; // r4
  int *v36; // [sp+0h] [bp-50h]
  int v37; // [sp+8h] [bp-48h] BYREF
  __int16 *v38; // [sp+Ch] [bp-44h]
  int v39; // [sp+10h] [bp-40h] BYREF
  int v40; // [sp+14h] [bp-3Ch]
  int v41; // [sp+18h] [bp-38h]
  int v42; // [sp+1Ch] [bp-34h]
  int *v43; // [sp+20h] [bp-30h] BYREF
  unsigned int v44; // [sp+24h] [bp-2Ch]
  __int16 v45[2]; // [sp+28h] [bp-28h] BYREF
  int v46; // [sp+2Ch] [bp-24h]

  v44 = a3;
  v7 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4);
  v39 = -1;
  v37 = -1;
  v8 = 0;
  v42 = 0;
  v43 = 0;
  v9 = 0;
  v38 = 0;
  v10 = v7(a1, a3, &v39);
  v11 = v10;
  if ( !v10 )
    return 0;
  if ( (*(_WORD *)(v10 + 2) & 0x20) == 0 )
    return sub_805994();
  v40 = 1;
  v13 = (unsigned __int16)(2 * *(_WORD *)(v10 + 72));
  v14 = *(int (__fastcall **)(int, _DWORD, int))(a1 + 12);
  v45[0] = v13;
  v45[1] = v13;
  v15 = v14(v13, 0, 540560707);
  v41 = v15;
  v46 = v15;
  if ( !v15 )
    goto LABEL_55;
  CmpCopyCompressedName(v15, v13, v11 + 76, *(unsigned __int16 *)(v11 + 72));
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
  v16 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v39);
  v17 = v16;
  if ( !v16 )
    goto LABEL_43;
  v9 = v44 >> 31;
  v18 = v16 + 4 * (v44 >> 31);
  if ( !*(_DWORD *)(v18 + 20) )
  {
    v21 = 12;
    if ( *(_DWORD *)(a1 + 148) < 5u )
    {
      v22 = 26220;
    }
    else
    {
      if ( a4 )
      {
        if ( a4 >= 0x3F4 )
          a4 = 1012;
        v21 = 8 * (a4 - 1) + 12;
      }
      v22 = 26732;
    }
    v36 = &v37;
    v23 = HvAllocateCell(a1, v21);
    if ( v23 != -1 )
    {
      v8 = v38;
      *v38 = v22;
      v8[1] = 0;
      *(_DWORD *)(v18 + 28) = v23;
      v42 = 1;
      goto LABEL_18;
    }
    goto LABEL_32;
  }
  v19 = (unsigned __int16 *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v18 + 28), &v37);
  v8 = (__int16 *)v19;
  if ( !v19 )
    goto LABEL_43;
  v20 = *v19;
  if ( v20 != 26220 || v19[1] < 0x1FBu )
  {
    if ( v20 != 26988 && v20 != 26732 || v19[1] < 0x3F5u )
      goto LABEL_18;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v37);
    v38 = 0;
    v36 = &v37;
    v31 = HvAllocateCell(a1, 12);
    if ( v31 != -1 )
    {
      v8 = v38;
      *v38 = 26994;
      v8[1] = 1;
      *((_DWORD *)v8 + 1) = *(_DWORD *)(v18 + 28);
      v42 = 2;
      *(_DWORD *)(v18 + 28) = v31;
      goto LABEL_18;
    }
LABEL_32:
    v8 = v38;
    goto LABEL_43;
  }
  if ( !HvpMarkCellDirty(a1, *(_DWORD *)(v18 + 28), 0, 0) )
    goto LABEL_43;
  v27 = 0;
  if ( v8[1] )
  {
    v28 = v8;
    v29 = v8;
    do
    {
      v30 = *((_DWORD *)v29 + 1);
      ++v27;
      v29 += 4;
      *((_DWORD *)v28 + 1) = v30;
      v28 += 2;
    }
    while ( v27 < (unsigned __int16)v8[1] );
  }
  *v8 = 26988;
LABEL_18:
  v24 = *(_DWORD *)(v18 + 28);
  if ( *v8 != 26994 )
  {
    v25 = 0;
    goto LABEL_20;
  }
  v24 = CmpSelectLeaf(a1, v17, v45, v9, &v43);
  if ( v24 == -1 )
  {
LABEL_43:
    if ( v40 )
      (*(void (__fastcall **)(int, int))(a1 + 16))(v41, v13);
    if ( v42 == 1 )
    {
      v35 = v17 + 4 * v9;
      HvFreeCell(a1, *(_DWORD *)(v35 + 28));
      *(_DWORD *)(v35 + 28) = -1;
    }
    else if ( v42 == 2 )
    {
      if ( v8 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v37);
      v32 = v17 + 4 * v9;
      v33 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v32 + 28), &v37);
      if ( v33 )
      {
        v34 = *(_DWORD *)(v33 + 4);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v37);
        HvFreeCell(a1, *(_DWORD *)(v32 + 28));
        *(_DWORD *)(v32 + 28) = v34;
      }
      goto LABEL_54;
    }
    if ( v8 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v37);
LABEL_54:
    if ( !v17 )
      return 0;
LABEL_55:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
    return 0;
  }
  v25 = v43;
LABEL_20:
  v26 = CmpAddToLeaf(a1, v24, v44, v45, v36);
  if ( v26 == -1 )
    goto LABEL_43;
  ++*(_DWORD *)(v18 + 20);
  if ( v25 )
    *v25 = v26;
  else
    *(_DWORD *)(v18 + 28) = v26;
  if ( v40 )
    (*(void (__fastcall **)(int, int))(a1 + 16))(v41, v13);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v37);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
  return 1;
}
