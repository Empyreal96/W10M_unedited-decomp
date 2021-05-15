// -SmFeAddComplete@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAT_SM_PAGE_KEY@@KKK@Z 
 
_BYTE *__fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeAddComplete(int a1, int *a2, int a3, char a4, char a5)
{
  _BYTE *result; // r0
  int v9; // r10
  int v10; // r9
  int v11; // r8
  unsigned int v12; // r2
  unsigned __int8 *v13; // r5
  _BYTE *v14; // r4
  unsigned int v15; // r2
  int v16; // r3
  unsigned int v17; // r4
  unsigned __int16 *v18; // r5
  int v19; // r0
  int v20; // r3
  unsigned __int16 *v21; // r3
  unsigned int v22; // r2
  int *v23; // r2
  int *v24; // r3
  unsigned int *v25; // r4
  unsigned int v26; // r1
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned __int16 *v29; // [sp+0h] [bp-88h] BYREF
  unsigned int v30; // [sp+4h] [bp-84h]
  int v31; // [sp+8h] [bp-80h]
  int v32; // [sp+Ch] [bp-7Ch]
  int v33[6]; // [sp+10h] [bp-78h] BYREF
  char v34; // [sp+28h] [bp-60h] BYREF

  v32 = a3;
  result = memset(v33, 0, sizeof(v33));
  v33[3] = 0;
  v33[4] = 8;
  v9 = *a2;
  v31 = a5 & 2;
  v33[0] = (int)&v34;
  v10 = 0;
  v11 = 1;
  if ( (a5 & 2) == 0 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v12 + 310);
    v13 = (unsigned __int8 *)(a1 + 3192);
    result = (_BYTE *)KeAbPreAcquire(a1 + 3192, 0, 0);
    v14 = result;
    do
      v15 = __ldrex(v13);
    while ( __strex(v15 | 1, v13) );
    __dmb(0xBu);
    if ( (v15 & 1) != 0 )
      result = (_BYTE *)ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3192), (int)result, a1 + 3192);
    if ( v14 )
      v14[14] |= 1u;
  }
  v16 = *(_DWORD *)(a1 + 3204);
  if ( ((1 << a4) & v16) == 0 )
  {
    v18 = v29;
    v17 = v30;
    while ( 1 )
    {
      if ( v11 )
      {
        v19 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
                (unsigned __int16 **)(a1 + 3196),
                v9,
                (int)v33,
                v16);
        result = (_BYTE *)B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
                            v19,
                            &v29,
                            v33);
        v18 = v29;
        v17 = v30;
        v11 = 0;
      }
      if ( !v18 )
        break;
      v20 = *v18;
      v17 += 8;
      v30 = v17;
      if ( v17 >= (unsigned int)&v18[4 * v20 + 4] )
      {
        v21 = (unsigned __int16 *)*((_DWORD *)v18 + 1);
        if ( !v21 )
          break;
        v17 = (unsigned int)(v21 + 4);
        v29 = (unsigned __int16 *)*((_DWORD *)v18 + 1);
        v30 = (unsigned int)(v21 + 4);
        v18 = v21;
      }
      v22 = v17;
LABEL_18:
      if ( (*(_BYTE *)(v22 + 7) & 1) != 0 )
      {
        if ( (a5 & 1) != 0 )
          goto LABEL_37;
      }
      else
      {
        if ( *(_BYTE *)(v22 + 6) != 1 )
          goto LABEL_37;
        if ( (a5 & 1) != 0 )
        {
          *(_BYTE *)(v22 + 6) = 3;
          goto LABEL_37;
        }
      }
      *(_BYTE *)(v22 + 6) = 0;
      if ( v33[3] == -1 || !v33[3] )
        v23 = &v33[1];
      else
        v23 = (int *)(v33[0] + 8 * v33[3] - 8);
      v24 = (int *)*v23;
      if ( (unsigned __int16 *)*v23 != v18 )
      {
        B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchResultDeref(
          (int)result,
          (int)v33);
        v24 = (int *)v33[3];
        if ( v33[3] != -1 )
        {
          B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
            (unsigned __int16 **)(a1 + 3196),
            *((_DWORD *)v18 + 2),
            (int)v33,
            v33[3]);
          v23 = (int *)v33[3];
          if ( v33[3] == -1 || !v33[3] )
            v24 = &v33[1];
          else
            v24 = (int *)(v33[0] + 8 * v33[3] - 8);
          v24[1] = v17;
          goto LABEL_36;
        }
        *v23 = (int)v18;
      }
      v23[1] = v17;
LABEL_36:
      result = (_BYTE *)B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(
                          (unsigned __int16 **)(a1 + 3196),
                          v33,
                          (int)v23,
                          v24);
      v11 = 1;
LABEL_37:
      v16 = v32;
      if ( ++v10 == v32 )
        goto LABEL_39;
      ++v9;
    }
    v22 = 0;
    goto LABEL_18;
  }
LABEL_39:
  if ( !v31 )
  {
    v25 = (unsigned int *)(a1 + 3192);
    __dmb(0xBu);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 - 1, v25) );
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 3192));
    result = (_BYTE *)KeAbPostRelease(a1 + 3192);
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = *(_WORD *)(v27 + 0x136) + 1;
    *(_WORD *)(v27 + 310) = v28;
    if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 )
      result = (_BYTE *)KiCheckForKernelApcDelivery((int)result);
  }
  return result;
}
