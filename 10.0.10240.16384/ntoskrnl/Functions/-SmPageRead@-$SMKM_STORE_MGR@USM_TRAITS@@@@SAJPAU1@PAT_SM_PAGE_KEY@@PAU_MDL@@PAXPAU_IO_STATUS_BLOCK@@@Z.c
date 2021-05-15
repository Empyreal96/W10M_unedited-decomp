// -SmPageRead@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAT_SM_PAGE_KEY@@PAU_MDL@@PAXPAU_IO_STATUS_BLOCK@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmPageRead(int a1, int a2, unsigned int a3, int a4, int *a5)
{
  unsigned int v5; // r5
  int v6; // r4
  char v7; // r6
  int *v8; // r10
  int v9; // r7
  int v10; // r9
  char v11; // r7
  int v12; // r4
  _DWORD *v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r4
  int v17; // r3
  _DWORD *v18; // r3
  int v20; // [sp+Ch] [bp-34h] BYREF
  int v21; // [sp+10h] [bp-30h] BYREF
  int v22; // [sp+14h] [bp-2Ch]
  _DWORD *v23; // [sp+18h] [bp-28h]
  int v24[9]; // [sp+1Ch] [bp-24h] BYREF

  v5 = a3;
  v20 = 0;
  v6 = a1;
  v7 = 0;
  v23 = (_DWORD *)a2;
  if ( (a3 & 3) != 0 )
  {
    if ( (a3 & 1) != 0 )
      v7 = 1;
    if ( (a3 & 2) != 0 )
      v7 |= 2u;
    v5 = a3 & 0xFFFFFFFC;
  }
  *a5 = 0;
  a5[1] = 0;
  *a5 = a4;
  v8 = a5;
  v21 = *(_DWORD *)(v5 + 20) >> 12;
  v22 = v21;
  v9 = SMKM_STORE_MGR<SM_TRAITS>::SmReadPickStore(a1, a2, &v21, &v20, v24);
  v10 = v20;
  if ( v9 >= 0 )
  {
    v11 = v21;
    a5[1] = v21;
    if ( (v7 & 2) != 0 && !*(_BYTE *)(v10 + 3516) )
    {
      v9 = -1073741791;
      goto LABEL_23;
    }
    if ( (*(_DWORD *)(v6 + 5888) & 0x10) != 0 )
    {
      v7 ^= (v7 ^ (8 * SmAcquireReleaseResAvailForRead(a5, v22, 0))) & 8;
      if ( (v7 & 8) == 0 )
      {
        v9 = -1073741670;
        goto LABEL_23;
      }
      v7 |= 4u;
    }
    if ( (v7 & 1) != 0 )
    {
      v12 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v6 + 5648));
      if ( v12 )
        goto LABEL_34;
      v12 = ExAllocatePoolWithTag(512, 56);
      if ( v12 )
        goto LABEL_34;
      v6 = a1;
      v7 &= 0xFEu;
    }
    v12 = SmFpAllocate(v6 + 5720, 1, a5, 0);
    if ( !v12 )
    {
      v9 = -1073741670;
LABEL_22:
      v6 = a1;
      goto LABEL_23;
    }
LABEL_34:
    memset((_BYTE *)v12, 0, 32);
    v17 = *(_DWORD *)v12;
    *(_DWORD *)(v12 + 8) = v5;
    *(_DWORD *)v12 = v17 & 0xFFFFFFF8 | 2;
    v18 = v23;
    *(_BYTE *)(v12 + 4) = v11;
    *(_DWORD *)(v12 + 12) = *v18;
    if ( (v24[0] & 1) != 0 )
      *(_DWORD *)(v12 + 4) |= 0x1000000u;
    if ( (v7 & 1) != 0 )
      *(_DWORD *)(v12 + 4) |= 0x4000000u;
    if ( SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxQueueWork(a5, a1, *(_WORD *)(v10 + 3512) & 0x1F, (int *)v12) >= 0 )
    {
      v12 = 0;
      v8 = 0;
      v10 = 0;
      v7 &= 0xFBu;
      v9 = 259;
    }
    else
    {
      v9 = -1073741670;
    }
    if ( v12 )
    {
      v6 = a1;
      SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource(a1);
      goto LABEL_23;
    }
    goto LABEL_22;
  }
LABEL_23:
  if ( v10 )
  {
    v13 = (_DWORD *)(v6 + 96 * (*(_DWORD *)(v10 + 3512) & 0x1F) + 4);
    __pld(v13);
    v14 = *v13 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 - 2, v13) );
    if ( v15 != v14 )
      ExfReleaseRundownProtection((unsigned __int8 *)v13);
  }
  if ( (v7 & 4) != 0 )
    SmAcquireReleaseResAvailForRead(v8, v22, 1);
  if ( v8 )
  {
    *a5 = 0;
    a5[1] = 0;
    *a5 = v9;
  }
  return v9;
}
