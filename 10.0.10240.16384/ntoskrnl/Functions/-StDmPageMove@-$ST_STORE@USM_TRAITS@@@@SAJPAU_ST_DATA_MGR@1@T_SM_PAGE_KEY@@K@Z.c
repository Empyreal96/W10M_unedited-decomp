// -StDmPageMove@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@T_SM_PAGE_KEY@@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmPageMove(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // r3
  int v7; // r3
  int result; // r0
  int v9; // r2
  int v10; // r3
  int *v11; // r6
  int v12; // r3
  int v13; // r2
  _DWORD *v14; // r3
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r10
  int v20; // r3
  int v21; // r7
  int v22; // r2
  int v23; // lr
  int v24; // r4
  int v25; // r2
  int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // [sp+10h] [bp-28h] BYREF
  int v29; // [sp+14h] [bp-24h]
  unsigned int v30; // [sp+18h] [bp-20h]
  int varg_r0; // [sp+40h] [bp+8h]
  unsigned int varg_r1; // [sp+44h] [bp+Ch]
  unsigned int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = *(_DWORD *)(a1 + 32);
  varg_r1 = a2;
  if ( (v5 & 1) != 0 )
  {
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
    a2 = varg_r1;
  }
  v7 = *(_DWORD *)(a1 + 32) & 0xFFFFFFFE;
  *(_DWORD *)(a1 + 32) = v7;
  result = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
             (unsigned __int16 **)a1,
             a2,
             a1 + 12,
             v7);
  if ( result >= 0 )
  {
    v9 = *(_DWORD *)(a1 + 24);
    if ( v9 == -1 || !v9 )
      v10 = a1 + 16;
    else
      v10 = *(_DWORD *)(a1 + 12) + 8 * v9 - 8;
    v11 = *(int **)(v10 + 4);
    if ( (*(_DWORD *)(a1 + 68) & 1) != 0 )
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
        a1 + 36,
        a1 + 48);
    *(_DWORD *)(a1 + 68) &= 0xFFFFFFFE;
    v28 = 0;
    v29 = 0;
    v12 = *v11;
    v28 = a3;
    v29 = v12;
    result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsert(
               a1 + 36,
               &v28,
               a1 + 48);
    if ( result >= 0 )
    {
      result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
                 (unsigned __int16 **)(a1 + 36),
                 v11[1],
                 a1 + 48);
      if ( result >= 0 )
      {
        result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(
                   a1 + 36,
                   (_DWORD *)(a1 + 48),
                   v13,
                   v14);
        if ( result >= 0 )
        {
          v15 = v11[1];
          v16 = *(_DWORD *)(a1 + 100);
          v11[1] = a3;
          v17 = *(_DWORD *)(a1 + 304);
          v18 = v15 >> v16;
          v19 = a3 >> v16;
          v20 = *(unsigned __int8 *)(a1 + 72);
          v28 = v15;
          if ( v20 )
            v21 = 0;
          else
            v21 = *(unsigned __int16 *)(v17 + 2 * v18) >> 13;
          v22 = v11[2] & 0xFFF;
          if ( !v22 )
            v22 = 4096;
          v30 = (unsigned int)(*(_DWORD *)(a1 + 112) + v22 + 15) >> 4;
          v23 = -v30;
          if ( v20 )
            v24 = 0;
          else
            v24 = *(unsigned __int16 *)(v17 + 2 * v18) >> 13;
          *(_WORD *)(v17 + 2 * v18) -= v30;
          *(_DWORD *)(a1 + 8 * v24 + 688) += v23;
          if ( (*(_WORD *)(v17 + 2 * v18) & 0x1FFF) == 0 && v18 != *(_DWORD *)(a1 + 12 * v24 + 392) )
            ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v18);
          v25 = *(_DWORD *)(a1 + 304);
          if ( *(_BYTE *)(a1 + 72) )
            v26 = 0;
          else
            v26 = *(unsigned __int16 *)(v25 + 2 * v19) >> 13;
          v27 = v30;
          *(_WORD *)(v25 + 2 * v19) += v30;
          *(_DWORD *)(a1 + 8 * v26 + 688) += v27;
          *(_DWORD *)(a1 + 12 * v26 + 396) += v27;
          if ( (dword_636E9C & 0x10) != 0 )
          {
            SmEtwLogStoreOp(&unk_636E90, 1);
            SmEtwLogStoreOp(&unk_636E90, 0);
          }
          if ( *(_DWORD *)(a1 + 12 * v21 + 392) == -1
            || (unsigned int)(*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 12 * v21 + 396)) > *(_DWORD *)(a1 + 104) )
          {
            ST_STORE<SM_TRAITS>::StDmpCurrentRegionWrite(a1);
          }
          result = 0;
        }
      }
    }
  }
  return result;
}
