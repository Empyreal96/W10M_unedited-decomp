// -SmpPageEvict@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@PAT_SM_PAGE_KEY@@KPAX@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmpPageEvict(int a1, int *a2, int a3)
{
  int *v4; // r6
  int v5; // r0
  int v6; // r8
  int v7; // r4
  int v8; // r0
  int *v9; // r5
  int v10; // r2
  _DWORD *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  _DWORD *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  int v18[2]; // [sp+8h] [bp-28h] BYREF
  int v19[8]; // [sp+10h] [bp-20h] BYREF

  v18[0] = a3;
  v4 = 0;
  v5 = SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictInitiate(a1, a2, (int)v18, (int)v19);
  v6 = v5;
  if ( v5 != 32 )
  {
    v7 = SmGlobals[24 * (v5 & 0x1F)];
    v18[1] = dword_636C80 & 1;
    v8 = SmFpAllocate(&unk_636B98, 0, 0, 0);
    v9 = (int *)v8;
    v10 = v18[0];
    if ( v8 )
    {
      *(_DWORD *)v8 = 0;
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)v8 = 0;
      v8 = SmFpAllocate(&unk_636B98, 1, v8, 0);
      v4 = (int *)v8;
      if ( v8 )
      {
        memset((_BYTE *)v8, 0, 32);
        *v4 = *v4 & 0xFFFFFFF8 | 1;
        v4[1] = *a2;
        v4[2] = v18[0];
        v8 = SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxQueueWork(v9, (int)SmGlobals, v6, v4);
        v10 = v18[0];
        if ( v8 >= 0 )
        {
          v7 = 0;
          v4 = 0;
          v9 = 0;
        }
      }
      else
      {
        v10 = v18[0];
      }
    }
    if ( v7 )
    {
      SMKM_STORE_MGR<SM_TRAITS>::SmFeSetEvictFailed(v8, a2, v10, v6);
      v11 = &SmGlobals[24 * (*(_DWORD *)(v7 + 3512) & 0x1F) + 1];
      __pld(v11);
      v12 = *v11 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v13 = __ldrex(v11);
      while ( v13 == v12 && __strex(v12 - 2, v11) );
      if ( v13 != v12 )
        ExfReleaseRundownProtection((unsigned __int8 *)v11);
    }
    v14 = (_DWORD *)((char *)&unk_636208 + 4 * v6);
    __pld(v14);
    v15 = *v14 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
    if ( v4 )
      SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource((int)SmGlobals, v4, (int)v9);
    if ( v9 )
      SmFpFree(&unk_636B98, 0, v9, v9);
  }
  return v19[0];
}
