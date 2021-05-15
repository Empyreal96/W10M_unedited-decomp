// -BTreeRedistribute@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(int a1, _DWORD *a2)
{
  int v2; // r3
  unsigned __int16 *v3; // r2
  unsigned __int16 *v4; // r5
  void **v5; // r1
  void **v6; // r4
  int v7; // r6
  _DWORD **v8; // r3
  struct NP_CONTEXT::NP_CTX *v9; // r0
  void *v10; // r0
  int result; // r0
  unsigned __int16 *v12; // r9
  unsigned int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r0
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r6
  unsigned __int16 *v20; // r7
  unsigned int v21; // lr
  int v22; // r8
  unsigned __int16 *v23; // r1
  int v24; // r10
  unsigned int v25; // r2
  int v26; // r3
  unsigned __int16 *v27; // r2
  unsigned __int16 *v28; // r2
  int v29; // r2
  _DWORD *v30; // r2
  unsigned int v31; // r3
  unsigned __int16 *v32; // [sp+0h] [bp-30h] BYREF
  int v33; // [sp+4h] [bp-2Ch]
  unsigned __int16 *v34; // [sp+8h] [bp-28h] BYREF
  int v35; // [sp+Ch] [bp-24h]

  v2 = *a2 + 8 * a2[3];
  v4 = *(unsigned __int16 **)(v2 - 12);
  v3 = *(unsigned __int16 **)(v2 - 16);
  if ( v4 == &v3[4 * *v3 + 4] )
  {
    v4 -= 4;
    if ( v4 <= v3 + 4 )
      v5 = (void **)(v3 + 2);
    else
      v5 = (void **)(v4 - 2);
    v6 = (void **)&v32;
    v34 = *(unsigned __int16 **)(v2 - 8);
    v7 = 1;
  }
  else
  {
    v32 = *(unsigned __int16 **)(v2 - 8);
    v5 = (void **)(v4 + 2);
    v6 = (void **)&v34;
    v7 = 0;
  }
  v8 = (_DWORD **)(a1 + 8);
  if ( !a1 )
    v8 = 0;
  if ( **v8 == -1 || *((_BYTE *)v3 + 2) != 2 )
  {
    *v6 = *v5;
  }
  else
  {
    if ( a1 )
      v9 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    else
      v9 = 0;
    if ( **(_DWORD **)v9 == -1 )
      v10 = *v5;
    else
      v10 = NP_CONTEXT::NpLeafRefInternal(v9, v5, 0);
    *v6 = v10;
    if ( !v10 )
      return 0;
  }
  v12 = v34;
  v13 = (unsigned int)*v6;
  v14 = *v34;
  v15 = *v32;
  v33 = v13 | v7;
  v16 = v15 + v14;
  if ( v15 + v14 < 0x1FF || v16 >= 0x3FD )
    return v33;
  if ( v15 <= v14 )
  {
    v20 = v32;
    v18 = 0;
    v17 = (int)v34;
    v21 = v15;
    v19 = (v16 >> 1) - v15;
  }
  else
  {
    v17 = (int)v32;
    v18 = v16 >> 1;
    v19 = v15 - (v16 >> 1);
    v20 = v34;
    v21 = 0;
  }
  v35 = v17 + 8 * v18;
  v22 = v35 + 8;
  v23 = v32;
  v24 = (int)&v20[4 * v21 + 4];
  v34 = &v20[4 * v21];
  if ( (unsigned __int16 *)v17 == v32 )
  {
    memmove(v24 + 8 * v19, (int)&v20[4 * v21 + 4], 8 * *v20);
    v23 = v32;
  }
  if ( *(_BYTE *)(v17 + 3) )
  {
    v25 = 8 * v19;
  }
  else
  {
    v26 = *(_DWORD *)v4;
    if ( (unsigned __int16 *)v17 == v23 )
    {
      v27 = &v20[4 * v19];
      *(_DWORD *)v27 = v26;
      *((_DWORD *)v27 + 1) = *((_DWORD *)v20 + 1);
    }
    else
    {
      v28 = v34;
      v24 = (int)&v20[4 * v21 + 8];
      *((_DWORD *)v34 + 2) = v26;
      *((_DWORD *)v28 + 3) = *(_DWORD *)(v17 + 4);
    }
    if ( (unsigned __int16 *)v17 == v23 )
    {
      v29 = v35;
      v22 += 8;
      *(_DWORD *)v4 = *(_DWORD *)(v35 + 8);
      *((_DWORD *)v20 + 1) = *(_DWORD *)(v29 + 12);
    }
    else
    {
      v30 = (_DWORD *)(v17 + 8 * v19);
      *(_DWORD *)v4 = *v30;
      *(_DWORD *)(v17 + 4) = v30[1];
    }
    v25 = 8 * (v19 - 1);
  }
  memmove(v24, v22, v25);
  *v20 = *(_DWORD *)v20 + v19;
  v31 = *(_DWORD *)v17 - v19;
  *(_WORD *)v17 = v31;
  if ( (unsigned __int16 *)v17 == v12 )
    memmove(v22, v22 + 8 * v19, 8 * (unsigned __int16)v31);
  result = v33;
  if ( *((_BYTE *)v12 + 3) )
    *(_DWORD *)v4 = *((_DWORD *)v12 + 2);
  return result;
}
