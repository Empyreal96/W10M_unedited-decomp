// -BTreeDeleteEx@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAJPAU1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeDeleteEx(unsigned __int16 **a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v4; // r2
  unsigned int *v7; // r4
  int v8; // r0
  unsigned __int16 *v9; // r5
  int v10; // r3
  char *v11; // r7
  int v12; // r0
  int v13; // r6
  unsigned int v15; // r3
  int v16; // r3
  __int64 v17; // kr08_8
  int v18; // [sp+0h] [bp-20h] BYREF
  _DWORD *v19; // [sp+4h] [bp-1Ch]

  v18 = a3;
  v19 = a4;
  v4 = a2[3];
  v7 = (unsigned int *)(*a2 + 8 * v4 - 8);
  v8 = v7[1];
  v9 = (unsigned __int16 *)*v7;
  v10 = 8 * *(unsigned __int16 *)*v7 - *(_DWORD *)(*a2 + 8 * v4 - 4);
  v11 = (char *)(v10 + *v7);
  if ( v11 )
    v8 = memmove(v8, v8 + 8, v10 + *v7);
  *v9 = *(_DWORD *)v9 - 1;
  if ( *((_BYTE *)v9 + 3) )
    a1[1] = (unsigned __int16 *)((char *)a1[1] - 1);
  if ( *a1 != v9 )
  {
    if ( *v9 < 0xFFu )
    {
      v12 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeRedistribute(v8);
      v13 = v12;
      if ( !v12 )
        return -1073741818;
      v15 = *v9;
      if ( v15 < 0xFF )
      {
        B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeMergeNodes(
          a1,
          a2,
          v12);
        v7 = (unsigned int *)(*a2 + 8 * a2[3] - 8);
        if ( (v13 & 1) != 0 )
        {
          *v7 = v13 & 0xFFFFFFFE;
          v16 = 8 * (*(unsigned __int16 *)(v13 & 0xFFFFFFFE) + 1) - (_DWORD)v11 + (v13 & 0xFFFFFFFE);
          goto LABEL_17;
        }
      }
      else if ( (v12 & 1) != 0 )
      {
        v16 = v7[1] + 8 * (v15 - 254);
LABEL_17:
        v7[1] = v16;
        goto LABEL_18;
      }
    }
LABEL_18:
    v17 = *(_QWORD *)v7;
    if ( HIDWORD(v17) == (_DWORD)v17 + 8
      && *(_BYTE *)(v17 + 3)
      && B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
           a2,
           0,
           &v18) )
    {
      *v19 = *(_DWORD *)HIDWORD(v17);
    }
    return 0;
  }
  if ( !*v9 && !*((_BYTE *)v9 + 3) )
  {
    memmove((int)v7, (int)(v7 + 2), 8 * (a2[4] - 1));
    --a2[3];
    *a1 = (unsigned __int16 *)*((_DWORD *)v9 + 1);
    ExFreePoolWithTag(v9);
  }
  return 0;
}
