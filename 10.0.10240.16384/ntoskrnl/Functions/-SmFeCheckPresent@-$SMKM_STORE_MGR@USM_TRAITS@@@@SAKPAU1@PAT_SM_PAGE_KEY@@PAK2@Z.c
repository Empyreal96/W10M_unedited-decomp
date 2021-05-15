// -SmFeCheckPresent@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@PAT_SM_PAGE_KEY@@PAK2@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeCheckPresent(int a1, unsigned int *a2, int *a3, int *a4)
{
  unsigned int v8; // r7
  int v9; // r3
  unsigned int v10; // r4
  int v11; // r8
  int v12; // r5
  int v13; // r0
  unsigned __int16 *v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v20; // [sp+0h] [bp-88h]
  _DWORD v21[2]; // [sp+8h] [bp-80h] BYREF
  int v22[6]; // [sp+10h] [bp-78h] BYREF
  char v23; // [sp+28h] [bp-60h] BYREF

  memset(v22, 0, sizeof(v22));
  v22[3] = 0;
  v8 = *a2;
  v22[4] = 8;
  v22[5] |= 1u;
  v9 = *a3;
  v22[0] = (int)&v23;
  v10 = 0;
  v11 = 0;
  v20 = v9;
  v12 = 32;
  v13 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSearchKey(
          (unsigned __int16 **)(a1 + 3196),
          v8,
          (int)v22,
          v9);
  B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
    v13,
    v21,
    v22);
  v14 = (unsigned __int16 *)v21[0];
  v15 = v21[1];
  while ( v14 )
  {
    v15 += 8;
    if ( v15 >= (unsigned int)&v14[4 * *v14 + 4] )
    {
      v16 = *((_DWORD *)v14 + 1);
      if ( !v16 )
      {
        v17 = 0;
        goto LABEL_8;
      }
      v14 = (unsigned __int16 *)*((_DWORD *)v14 + 1);
      v15 = v16 + 8;
    }
    v17 = v15;
LABEL_8:
    if ( !v17 )
      break;
    if ( v8 < *(_DWORD *)v17 )
      break;
    if ( (*(_BYTE *)(v17 + 7) & 1) != 0 )
      break;
    v18 = *(unsigned __int8 *)(v17 + 6);
    if ( v18 != 3 && v18 != 1 )
      break;
    if ( v18 == 1 )
      v11 = 1;
    if ( v10++ )
    {
      if ( v12 != *(unsigned __int16 *)(v17 + 4) )
        break;
    }
    else
    {
      v12 = *(unsigned __int16 *)(v17 + 4);
    }
    if ( v10 >= v20 )
      break;
    ++v8;
  }
  if ( !v10 )
    return 32;
  *a3 = v10;
  *a4 = v11;
  return v12;
}
