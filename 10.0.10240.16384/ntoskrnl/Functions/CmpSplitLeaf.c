// CmpSplitLeaf 
 
unsigned int __fastcall CmpSplitLeaf(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int (__fastcall *v5)(int, unsigned int, int *); // r4
  int v7; // r6
  __int16 *v8; // r7
  unsigned int v9; // r10
  int v10; // r0
  __int16 *v11; // r4
  int v12; // r0
  int v13; // r9
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r1
  int v17; // r0
  __int16 v18; // r3
  int v19; // r2
  int v20; // r4
  int v21; // r0
  int v22; // r4
  __int16 v24; // r6
  int v25; // r1
  __int16 v26; // r3
  int v27; // r2
  unsigned int v28; // r1
  int v29; // [sp+8h] [bp-40h] BYREF
  __int16 *v30; // [sp+Ch] [bp-3Ch] BYREF
  int v31; // [sp+10h] [bp-38h] BYREF
  int v32; // [sp+14h] [bp-34h] BYREF
  unsigned int v33; // [sp+18h] [bp-30h]
  unsigned int v34; // [sp+1Ch] [bp-2Ch]
  int v35; // [sp+20h] [bp-28h]
  unsigned int v36; // [sp+24h] [bp-24h]
  int v37; // [sp+28h] [bp-20h]

  v5 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4);
  v7 = -1;
  v8 = 0;
  v37 = a4;
  v9 = a2;
  v29 = -1;
  v30 = 0;
  v31 = -1;
  v32 = -1;
  v10 = v5(a1, a2, &v29);
  v11 = (__int16 *)v10;
  if ( !v10 )
    return v7;
  v36 = *(_DWORD *)(v10 + 4 * a3 + 4);
  v12 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, v36, &v32);
  v13 = v12;
  if ( !v12 )
    goto LABEL_16;
  v14 = *(unsigned __int16 *)(v12 + 2);
  v34 = v14 >> 1;
  v35 = (unsigned __int16)(v14 - (v14 >> 1));
  if ( *(_DWORD *)(a1 + 148) < 5u )
    v15 = 4;
  else
    v15 = 8;
  v33 = v15;
  if ( !HvpMarkCellDirty(a1, v36, 0, 0)
    || (v16 = v33 * v35 + 5, v33 *= v35, v17 = HvAllocateCell(a1, v16), v8 = v30, v36 = v17, v17 == -1) )
  {
LABEL_14:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v32);
    if ( v8 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
LABEL_16:
    if ( v11 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v29);
    return v7;
  }
  if ( *(_DWORD *)(a1 + 148) < 5u )
    v18 = 26988;
  else
    v18 = 26732;
  *v30 = v18;
  v19 = *((_DWORD *)v11 - 1);
  if ( ((-8 - 4 * (unsigned __int16)v11[1] - v19) & 0xFFFFFFFC) < 4 )
  {
    v20 = -4 - v19;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v29);
    v30 = 0;
    v21 = HvReallocateCell(a1, v9, v20 + 4, 0, (int *)&v30, &v29);
    v22 = v21;
    if ( v21 == -1 )
    {
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
      v8 = 0;
      HvFreeCell(a1, v36);
      v11 = v30;
      goto LABEL_14;
    }
    if ( v9 != v21 )
    {
      HvFreeCell(a1, v9);
      v9 = v22;
    }
    v11 = v30;
  }
  v24 = v34;
  if ( *(_DWORD *)(a1 + 148) < 5u )
    v25 = v13 + 4 * (v34 + 1);
  else
    v25 = v13 + 8 * v34 + 4;
  memmove((int)(v8 + 2), v25, v33);
  v26 = v35;
  *(_WORD *)(v13 + 2) = v24;
  v8[1] = v26;
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v32);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
  v27 = (unsigned __int16)v11[1];
  if ( a3 < v27 - 1 )
    memmove((int)&v11[2 * a3 + 6], (int)&v11[2 * a3 + 4], 4 * (v27 - a3) - 4);
  v28 = v36;
  ++v11[1];
  *(_DWORD *)&v11[2 * a3 + 4] = v28;
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v29);
  return v9;
}
