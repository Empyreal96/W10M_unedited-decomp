// -StCompactionPerformFile@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCompactionPerformFile(int a1)
{
  int v1; // r3
  void *v3; // r10
  int v4; // r7
  int v5; // r5
  int v6; // r6
  int v7; // r2
  int v8; // r9
  int v9; // r5
  int v10; // r2
  unsigned int v11; // r3
  _DWORD **v12; // r3
  _DWORD **v13; // r3
  int v14; // r0
  int v15; // r5
  int v16; // r2
  unsigned int v17; // r9
  int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r3
  int v21; // r2
  unsigned __int16 *v23; // [sp+10h] [bp-58h] BYREF
  unsigned int v24; // [sp+14h] [bp-54h]
  int v25; // [sp+18h] [bp-50h]
  _WORD *v26; // [sp+1Ch] [bp-4Ch] BYREF
  int v27; // [sp+20h] [bp-48h]
  unsigned int v28; // [sp+24h] [bp-44h] BYREF
  int v29; // [sp+28h] [bp-40h]
  int v30; // [sp+2Ch] [bp-3Ch]
  int v31; // [sp+30h] [bp-38h] BYREF
  int v32; // [sp+34h] [bp-34h]
  char v33[8]; // [sp+38h] [bp-30h] BYREF
  int v34; // [sp+40h] [bp-28h]

  v23 = 0;
  v24 = 0;
  v1 = *(_DWORD *)(a1 + 668);
  v3 = 0;
  if ( v1 )
  {
    v4 = *(_DWORD *)(a1 + 668);
    *(_DWORD *)(a1 + 668) = v1 | 1;
  }
  else
  {
    v4 = ExAllocatePoolWithTag(512, 16 * ((unsigned int)(*(_DWORD *)(a1 + 112) + 4111) >> 4));
    if ( !v4 )
    {
      v5 = -1073741670;
      goto LABEL_5;
    }
  }
  if ( ST_STORE<SM_TRAITS>::StCompactionFindEmptiest(
         a1,
         (unsigned int)&v26,
         1,
         *(_DWORD *)(a1 + 104) - *(_DWORD *)(a1 + 108) + 1) )
  {
    v7 = *(_DWORD *)(a1 + 304);
    v6 = ((int)v26 - v7) >> 1;
    if ( *(_BYTE *)(a1 + 72) )
      v8 = 0;
    else
      v8 = *(unsigned __int16 *)(v7 + 2 * v6) >> 13;
    v9 = *(_DWORD *)(a1 + 100);
    v25 = v8;
    v29 = v9;
    if ( (dword_636E9C & 0x10) != 0 )
    {
      v3 = &unk_636E90;
      SmEtwLogRegionOp(&unk_636E90, 6, a1, v6, 0, *v26 & 0x1FFF, *(unsigned __int8 *)(*(_DWORD *)(a1 + 312) + v6));
    }
    else
    {
      v3 = 0;
    }
    v32 = (1 << (*(_DWORD *)(a1 + 100) - 8)) - 1;
    v27 = -1;
    while ( 1 )
    {
      v5 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
             (unsigned __int16 **)(a1 + 36),
             v6 << v9,
             a1 + 48);
      if ( v5 == -1073741818 )
        goto LABEL_50;
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorFromSearchResult(
        a1 + 36,
        &v23,
        a1 + 48);
      if ( !v23 )
      {
        v10 = 0;
        goto LABEL_33;
      }
      v11 = (unsigned int)&v23[4 * *v23 + 4];
      v10 = v24 + 8;
      v24 += 8;
      if ( v24 >= v11 )
      {
        v12 = (_DWORD **)(a1 + 44);
        if ( a1 == -36 )
          v12 = 0;
        if ( **v12 == -1 )
        {
          v13 = (_DWORD **)(a1 + 44);
          if ( a1 == -36 )
            v13 = 0;
          if ( **v13 == -1 )
            v14 = *((_DWORD *)v23 + 1);
          else
            v14 = 3358;
        }
        else
        {
          v14 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSibling(
                  a1 + 36,
                  v23);
          if ( v14 == -1 )
          {
            v10 = -1;
            goto LABEL_32;
          }
        }
        if ( v14 )
        {
          v10 = v14 + 8;
          v23 = (unsigned __int16 *)v14;
          v24 = v14 + 8;
        }
        else
        {
          v10 = 0;
        }
      }
LABEL_32:
      if ( v10 == -1 )
      {
        v5 = -1073741818;
        goto LABEL_50;
      }
LABEL_33:
      v30 = *(_DWORD *)(v10 + 4);
      v15 = v30;
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v23, a1 + 36);
      v23 = 0;
      v24 = 0;
      v5 = ST_STORE<SM_TRAITS>::StDmSinglePageRetrieveSync(a1, v15, v4, v33);
      if ( v5 < 0 )
        goto LABEL_50;
      v5 = ST_STORE<SM_TRAITS>::StDmpSinglePageFindSpace(a1, v8, *(_DWORD *)(a1 + 108), &v31, &v28);
      if ( v5 < 0 )
        goto LABEL_50;
      if ( v6 == *(_DWORD *)(a1 + 12 * v8 + 392) )
        goto LABEL_48;
      v16 = v34 & 0xFFF;
      if ( (v34 & 0xFFF) == 0 )
        v16 = 4096;
      memmove(v31, v4, 16 * ((unsigned int)(*(_DWORD *)(a1 + 112) + v16 + 15) >> 4));
      v17 = v28;
      v5 = ST_STORE<SM_TRAITS>::StDmPageMove(a1, v30, v28);
      if ( v5 < 0 )
        goto LABEL_50;
      v18 = *(_DWORD *)(a1 + 312);
      v19 = v17 >> *(_DWORD *)(a1 + 100);
      v20 = *(unsigned __int8 *)(v18 + v19);
      if ( v20 <= *(unsigned __int8 *)(v18 + v6) )
        LOBYTE(v20) = *(_BYTE *)(v18 + v6);
      *(_BYTE *)(v18 + v19) = v20;
      if ( (*v26 & 0x1FFF) == 0 )
      {
LABEL_48:
        v5 = 0;
        goto LABEL_50;
      }
      if ( (++v27 & v32) == 0
        && ST_STORE<SM_TRAITS>::StDmGetFreeStagingRegionBytes(a1) <= (unsigned int)(3 * *(_DWORD *)(a1 + 80)) )
      {
        v5 = -1073741110;
        goto LABEL_50;
      }
      if ( ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0) != 2 )
      {
        v5 = -2147483634;
        goto LABEL_50;
      }
      v8 = v25;
      LOBYTE(v9) = v29;
    }
  }
  v5 = 0;
LABEL_5:
  v6 = v25;
LABEL_50:
  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v23, a1 + 36);
  if ( v4 )
  {
    v21 = *(_DWORD *)(a1 + 668);
    if ( (v21 & 1) != 0 && (v4 | 1) == v21 )
      *(_DWORD *)(a1 + 668) = v21 & 0xFFFFFFFE;
    else
      ExFreePoolWithTag(v4);
  }
  if ( v3 )
    SmEtwLogRegionOp(v3, 7, a1, v6, v5, *v26 & 0x1FFF, *(unsigned __int8 *)(*(_DWORD *)(a1 + 312) + v6));
  return v5;
}
