// -BTreeRedistribute@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(int a1, _DWORD *a2)
{
  unsigned int v2; // r7
  int v3; // r3
  unsigned __int16 *v4; // r5 OVERLAPPED
  unsigned __int16 *v5; // r6 OVERLAPPED
  unsigned __int16 *v6; // r2
  void **v7; // r1
  _DWORD *v8; // r4
  int v9; // r6
  _DWORD **v10; // r3
  struct NP_CONTEXT::NP_CTX *v11; // r0
  void *v12; // r0
  int result; // r0
  unsigned __int16 *v14; // r0
  unsigned __int16 *v15; // r9
  unsigned int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // lr
  unsigned __int16 *v20; // r1
  int v21; // r4
  unsigned __int16 *v22; // r6
  unsigned int v23; // r7
  int v24; // r3
  int v25; // r10
  int v26; // r2
  int v27; // r8
  unsigned int v28; // r2
  int v29; // r3
  unsigned __int16 *v30; // r2
  unsigned __int16 *v31; // r2
  int v32; // r2
  _DWORD *v33; // r2
  unsigned int v34; // r3
  int v35; // [sp+0h] [bp-30h]
  int v36; // [sp+4h] [bp-2Ch]
  unsigned __int16 *v37; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 *v38; // [sp+Ch] [bp-24h] BYREF
  int v39; // [sp+10h] [bp-20h]

  v2 = 511;
  v3 = *a2 + 8 * a2[3];
  *(_QWORD *)&v4 = *(_QWORD *)(v3 - 12);
  v6 = *(unsigned __int16 **)(v3 - 16);
  if ( *((_BYTE *)v5 + 3) )
    v2 = 255;
  if ( v4 == &v6[4 * *v6 + 4] )
  {
    v4 -= 4;
    if ( v4 <= v6 + 4 )
      v7 = (void **)(v6 + 2);
    else
      v7 = (void **)(v4 - 2);
    v8 = &v37;
    v38 = v5;
    v9 = 1;
  }
  else
  {
    v37 = v5;
    v7 = (void **)(v4 + 2);
    v8 = &v38;
    v9 = 0;
  }
  v10 = (_DWORD **)(a1 + 8);
  if ( !a1 )
    v10 = 0;
  if ( **v10 == -1 || *((_BYTE *)v6 + 2) != 2 )
  {
    *v8 = *v7;
  }
  else
  {
    if ( a1 )
      v11 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    else
      v11 = 0;
    if ( **(_DWORD **)v11 == -1 )
      v12 = *v7;
    else
      v12 = NP_CONTEXT::NpLeafRefInternal(v11, v7, 0);
    *v8 = v12;
    if ( !v12 )
      return 0;
  }
  v14 = v37;
  v15 = v38;
  v36 = *v8 | v9;
  v16 = *v38;
  v17 = *v37;
  v18 = v17 + v16;
  if ( v17 + v16 < v2 || v18 >= 2 * v2 - 1 )
    return v36;
  if ( v17 <= v16 )
  {
    v23 = (v18 >> 1) - v17;
    v20 = (unsigned __int16 *)*v37;
    v21 = (int)v38;
    v22 = v37;
    v19 = 0;
    v38 = v20;
  }
  else
  {
    v19 = v18 >> 1;
    v20 = 0;
    v38 = 0;
    v21 = (int)v37;
    v22 = v15;
    v23 = v17 - v19;
  }
  v24 = *(unsigned __int8 *)(v21 + 3);
  v39 = v19;
  if ( v24 )
  {
    v25 = v21 + 16 * v19 + 8;
    v26 = (int)&v22[8 * (_DWORD)v20 + 4];
    v27 = 16;
  }
  else
  {
    v25 = v21 + 8 * (v19 + 1);
    v26 = (int)&v22[4 * ((_DWORD)v20 + 1)];
    v27 = 8;
  }
  v35 = v26;
  if ( (unsigned __int16 *)v21 == v37 )
  {
    memmove(v26 + v27 * v23, v26, *v22 * v27);
    v20 = v38;
    v19 = v39;
    v14 = v37;
  }
  if ( *(_BYTE *)(v21 + 3) )
  {
    v28 = v27 * v23;
  }
  else
  {
    v29 = *(_DWORD *)v4;
    if ( (unsigned __int16 *)v21 == v14 )
    {
      v30 = &v22[4 * v23];
      *(_DWORD *)v30 = v29;
      *((_DWORD *)v30 + 1) = *((_DWORD *)v22 + 1);
    }
    else
    {
      v31 = &v22[4 * (_DWORD)v20];
      *((_DWORD *)v31 + 2) = v29;
      *((_DWORD *)v31 + 3) = *(_DWORD *)(v21 + 4);
      v35 += v27;
    }
    if ( (unsigned __int16 *)v21 == v14 )
    {
      v32 = v21 + 8 * v19;
      v25 += v27;
      *(_DWORD *)v4 = *(_DWORD *)(v32 + 8);
      *((_DWORD *)v22 + 1) = *(_DWORD *)(v32 + 12);
    }
    else
    {
      v33 = (_DWORD *)(v21 + 8 * v23);
      *(_DWORD *)v4 = *v33;
      *(_DWORD *)(v21 + 4) = v33[1];
    }
    v28 = (v23 - 1) * v27;
  }
  memmove(v35, v25, v28);
  *v22 = *(_DWORD *)v22 + v23;
  v34 = *(_DWORD *)v21 - v23;
  *(_WORD *)v21 = v34;
  if ( (unsigned __int16 *)v21 == v15 )
    memmove(v25, v25 + v27 * v23, (unsigned __int16)v34 * v27);
  result = v36;
  if ( *((_BYTE *)v15 + 3) )
    *(_DWORD *)v4 = *((_DWORD *)v15 + 2);
  return result;
}
