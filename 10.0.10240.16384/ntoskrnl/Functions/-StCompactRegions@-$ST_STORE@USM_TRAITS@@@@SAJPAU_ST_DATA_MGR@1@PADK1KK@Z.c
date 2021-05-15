// -StCompactRegions@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PADK1KK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCompactRegions(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r7
  _WORD *v8; // r3
  int v10; // r10
  int v11; // r4
  unsigned int v12; // r7
  unsigned __int16 *v13; // r9
  int v14; // r3
  _DWORD **v15; // r3
  _DWORD **v16; // r3
  int v17; // r0
  int v18; // r1
  int v19; // r8
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r0
  unsigned int v25; // r4
  int v26; // r1
  int v27; // r3
  unsigned int *v28; // r8
  int v29; // r2
  int *v30; // r4
  int v31; // r3
  int v32; // r2
  int v33; // r0
  int v34; // r3
  int v35; // r2
  _DWORD *v36; // r3
  int v38; // [sp+0h] [bp-58h]
  int v39; // [sp+4h] [bp-54h]
  _WORD *v42; // [sp+10h] [bp-48h]
  int *v44; // [sp+18h] [bp-40h]
  _WORD *v45; // [sp+1Ch] [bp-3Ch]
  unsigned int v46; // [sp+20h] [bp-38h]
  unsigned __int16 *v47; // [sp+28h] [bp-30h] BYREF
  int v48; // [sp+2Ch] [bp-2Ch]
  unsigned int *v49; // [sp+30h] [bp-28h] BYREF
  int v50; // [sp+34h] [bp-24h]

  v39 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v6 = *(_DWORD *)(a1 + 304);
  v7 = a3;
  v38 = a5;
  v8 = (_WORD *)(v6 + 2 * a5);
  v42 = v8;
  v45 = (_WORD *)(v6 + 2 * a3);
  if ( v45 == v8 )
    v10 = 0;
  else
    v10 = *v8 & 0x1FFF;
  if ( (*(_DWORD *)(a1 + 32) & 1) != 0 )
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
  *(_DWORD *)(a1 + 32) &= 0xFFFFFFFE;
  if ( (*(_DWORD *)(a1 + 68) & 1) != 0 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
      a1 + 36,
      a1 + 48);
  *(_DWORD *)(a1 + 68) &= 0xFFFFFFFE;
  v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
          (unsigned __int16 **)(a1 + 36),
          v7 << *(_DWORD *)(a1 + 100),
          a1 + 48);
  if ( v11 != -1073741818 )
  {
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorFromSearchResult(
      a1 + 36,
      &v47,
      a1 + 48);
    v13 = v47;
    v12 = v48;
    while ( 1 )
    {
      if ( v39 )
      {
        v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
                (unsigned __int16 **)(a1 + 36),
                a3 << *(_DWORD *)(a1 + 100),
                a1 + 48);
        if ( v11 == -1073741818 )
          break;
        B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v47, a1 + 36);
        B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorFromSearchResult(
          a1 + 36,
          &v47,
          a1 + 48);
        v13 = v47;
        v12 = v48;
      }
      if ( !v13 )
      {
LABEL_78:
        v11 = 0;
        break;
      }
      v14 = *v13;
      v12 += 8;
      v48 = v12;
      if ( v12 >= (unsigned int)&v13[4 * v14 + 4] )
      {
        v15 = (_DWORD **)(a1 + 44);
        if ( a1 == -36 )
          v15 = 0;
        if ( **v15 == -1 )
        {
          v16 = (_DWORD **)(a1 + 44);
          if ( a1 == -36 )
            v16 = 0;
          if ( **v16 == -1 )
            v17 = *((_DWORD *)v13 + 1);
          else
            v17 = 3358;
        }
        else
        {
          v17 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSibling(
                  a1 + 36,
                  v13);
          if ( v17 == -1 )
          {
            v18 = -1;
            goto LABEL_29;
          }
        }
        if ( !v17 )
        {
          v18 = 0;
          goto LABEL_29;
        }
        v12 = v17 + 8;
        v47 = (unsigned __int16 *)v17;
        v48 = v17 + 8;
        v13 = (unsigned __int16 *)v17;
      }
      v18 = v12;
LABEL_29:
      if ( v18 == -1 )
      {
        v11 = -1073741818;
        break;
      }
      if ( !v18 )
        goto LABEL_78;
      v19 = *(_DWORD *)(a1 + 96) & *(_DWORD *)v18;
      v20 = *(_DWORD *)v18 >> *(_DWORD *)(a1 + 100);
      if ( v20 != a3 )
        goto LABEL_78;
      v11 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
              (unsigned __int16 **)a1,
              *(_DWORD *)(v18 + 4),
              a1 + 12,
              v20);
      if ( v11 == -1073741818 )
        break;
      v21 = *(_DWORD *)(a1 + 24);
      if ( v21 == -1 || !v21 )
        v22 = a1 + 16;
      else
        v22 = *(_DWORD *)(a1 + 12) + 8 * v21 - 8;
      v44 = *(int **)(v22 + 4);
      v23 = v44[2] & 0xFFF;
      if ( !v23 )
        v23 = 4096;
      v24 = *(_DWORD *)(a1 + 112);
      v25 = v24 + v23 + 15;
      v46 = v25;
      v26 = (*(_DWORD *)(*(_DWORD *)(a1 + 288) + 4) + v23 - 1) & ~(*(_DWORD *)(*(_DWORD *)(a1 + 288) + 4) - 1);
      v27 = v38;
      if ( v38 != a3 )
      {
        if ( (*v42 & 0x1FFF) + (v25 >> 4) <= *(_DWORD *)(a1 + 104) )
        {
          v27 = v38;
        }
        else
        {
          v27 = a3;
          v38 = a3;
          v42 = v45;
          v10 = 0;
          a4 = a2;
          v39 = 0;
        }
      }
      if ( v19 != v10 || a3 != v27 )
      {
        if ( !a4 )
        {
          v11 = -1073741802;
          break;
        }
        memmove(a4 + 16 * v10, a2 + 16 * v19, v26 + v24);
        v28 = (unsigned int *)((v38 << *(_DWORD *)(a1 + 100)) | v10);
        if ( v39 )
        {
LABEL_64:
          B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(
            &v47,
            a1 + 36);
          v47 = 0;
          v48 = 0;
          v34 = *v44;
          v49 = v28;
          v50 = v34;
          v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsert(
                  a1 + 36,
                  &v49,
                  a1 + 48);
          if ( v11 < 0 )
            break;
          v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
                  (unsigned __int16 **)(a1 + 36),
                  v44[1],
                  a1 + 48);
          if ( v11 >= 0 )
            v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(
                    a1 + 36,
                    (_DWORD *)(a1 + 48),
                    v35,
                    v36);
          if ( v11 == -1073741818 )
            break;
          v13 = v47;
          v12 = v48;
        }
        else
        {
          v29 = *(_DWORD *)(a1 + 60);
          if ( v29 == -1 || !v29 )
            v30 = (int *)(a1 + 52);
          else
            v30 = (int *)(*(_DWORD *)(a1 + 48) + 8 * v29 - 8);
          v31 = *v30;
          if ( (unsigned __int16 *)*v30 == v13 )
          {
LABEL_54:
            v30[1] = v12;
          }
          else
          {
            B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
              a1 + 36,
              a1 + 48);
            v31 = *(_DWORD *)(a1 + 60);
            if ( v31 == -1 )
            {
              *v30 = (int)v13;
              goto LABEL_54;
            }
            B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
              (unsigned __int16 **)(a1 + 36),
              *((_DWORD *)v13 + 2),
              a1 + 48);
            v32 = *(_DWORD *)(a1 + 60);
            if ( v32 == -1 || !v32 )
              v31 = a1 + 52;
            else
              v31 = *(_DWORD *)(a1 + 48) + 8 * v32 - 8;
            *(_DWORD *)(v31 + 4) = v12;
          }
          v33 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeChangeKey(
                  a1 + 36,
                  a1 + 48,
                  v28,
                  v31);
          if ( !v33 || v33 == -1 )
          {
            if ( v33 == -1 )
            {
              v11 = -1073741818;
              break;
            }
            v39 = 1;
            goto LABEL_64;
          }
        }
        v25 = v46;
        v44[1] = (int)v28;
        if ( a3 != v38 )
        {
          *v45 = *v45 & 0xE000 | (*v45 - (v46 >> 4)) & 0x1FFF;
          *v42 = *v42 & 0xE000 | (*v42 + (v46 >> 4)) & 0x1FFF;
        }
      }
      v10 += v25 >> 4;
      if ( a6 && ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0) != 2 )
      {
        v11 = -2147483634;
        break;
      }
    }
  }
  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v47, a1 + 36);
  return v11;
}
