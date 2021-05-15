// -StDmRegionEvict@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_STDM_SEARCH_RESULTS@1@KKKK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmRegionEvict(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v6; // r3
  int v7; // r3
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r2
  int *v11; // r4
  int *v12; // r0
  int v13; // r1
  bool v14; // cf
  _DWORD v16[252]; // [sp+10h] [bp-448h] BYREF
  unsigned int v17; // [sp+410h] [bp-48h]
  int v18; // [sp+414h] [bp-44h]
  int v19; // [sp+418h] [bp-40h]
  _DWORD v20[14]; // [sp+420h] [bp-38h] BYREF

  v3 = a3;
  v4 = a2;
  v18 = a3;
  v19 = a2;
  memset(v20, 0, 24);
  v20[0] = v20[0] & 0xFFFFFFF8 | 1;
  v20[3] |= 1u;
  if ( (dword_636E9C & 0x10) != 0 )
  {
    v6 = *(_DWORD *)(a1 + 312);
    if ( v6 )
      v7 = *(unsigned __int8 *)(v6 + v3);
    else
      v7 = 0;
    SmEtwLogRegionOp(&unk_636E90, 3, a1, v3, 0, *(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v3) & 0x1FFF, v7);
  }
  do
  {
    v17 = 256;
    v8 = ST_STORE<SM_TRAITS>::StDmRegionGetKeys(a1, v4, v3);
    if ( v8 < 0 )
      break;
    v9 = v17;
    if ( !v17 )
      break;
    qsort((unsigned int)v16, v17, 4u, (int (__fastcall *)(unsigned int, _BYTE *))ST_STORE<SM_TRAITS>::StpKeyCompare);
    v10 = v16[0];
    v11 = v16;
    v12 = &v16[v9];
    v20[1] = v16[0];
    v13 = 0;
LABEL_9:
    if ( v10 != *v11 )
      goto LABEL_12;
    while ( 1 )
    {
      ++v11;
      ++v13;
      if ( v11 < v12 )
      {
        ++v10;
        goto LABEL_9;
      }
      if ( v11 != v12 )
        break;
LABEL_12:
      v20[2] = v13;
      v8 = ST_STORE<SM_TRAITS>::StDmPageRemove(a1, (int)v20);
      if ( v8 < 0 )
        return v8;
      v10 = *v11;
      v13 = 0;
      v12 = &v16[v9];
      v20[1] = *v11;
    }
    v3 = v18;
    v14 = v9 >= 0x100;
    v4 = v19;
  }
  while ( v14 );
  return v8;
}
