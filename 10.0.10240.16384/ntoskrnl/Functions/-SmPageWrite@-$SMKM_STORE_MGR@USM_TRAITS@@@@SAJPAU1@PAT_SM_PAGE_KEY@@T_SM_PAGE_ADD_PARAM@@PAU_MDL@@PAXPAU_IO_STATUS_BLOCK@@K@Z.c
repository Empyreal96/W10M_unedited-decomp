// -SmPageWrite@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAT_SM_PAGE_KEY@@T_SM_PAGE_ADD_PARAM@@PAU_MDL@@PAXPAU_IO_STATUS_BLOCK@@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmPageWrite(int a1, unsigned int *a2, unsigned int a3, int a4, int a5, int *a6, int a7)
{
  unsigned int *v8; // r5
  unsigned int v9; // r2
  int *v11; // r10
  int v12; // r4
  unsigned int v13; // r6
  unsigned int v14; // r4
  unsigned int *v15; // r5
  unsigned int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r4
  unsigned int v19; // r1
  int v20; // r5
  int *v21; // r0
  int *v22; // r6
  int v23; // r2
  int v24; // r3
  int v25; // r2
  __int16 v26; // r3
  int v27; // r9
  _DWORD *v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int v33; // [sp+Ch] [bp-34h]
  int var30[16]; // [sp+10h] [bp-30h] BYREF
  unsigned int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  var30[14] = a1;
  var30[15] = (int)a2;
  varg_r3 = a4;
  var30[2] = 0;
  var30[1] = (int)var30;
  varg_r2 = a3;
  *a6 = 0;
  a6[1] = 0;
  *a6 = a5;
  var30[3] = 0;
  var30[0] = 0;
  v8 = a2;
  v9 = a3 & 0x3F;
  v33 = *(_DWORD *)(a4 + 20);
  v11 = a6;
  if ( v9 == 32 )
  {
    v12 = SMKM_STORE_MGR<SM_TRAITS>::SmPickStoreForWrite();
    goto LABEL_19;
  }
  if ( v9 >= 0x20 )
  {
    v12 = 0;
    goto LABEL_19;
  }
  v13 = v9 | (32 * (*(_WORD *)(a1 + 96 * v9 + 12) & 0x7FF));
  v14 = a1 + 96 * (v13 & 0x1F);
  v15 = (unsigned int *)(v14 + 4);
  __pld((void *)(v14 + 4));
  v16 = *(_DWORD *)(v14 + 4) & 0xFFFFFFFE;
  do
    v17 = __ldrex(v15);
  while ( v17 == v16 && __strex(v16 + 2, v15) );
  __dmb(0xBu);
  if ( v17 != v16 && !ExfAcquireRundownProtection((_DWORD *)(v14 + 4)) )
    goto LABEL_17;
  if ( (*(_WORD *)(v14 + 12) & 0x7FF) != v13 >> 5 )
  {
    __pld(v15);
    v18 = *v15 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v19 = __ldrex(v15);
    while ( v19 == v18 && __strex(v18 - 2, v15) );
    if ( v19 != v18 )
      ExfReleaseRundownProtection((unsigned __int8 *)v15);
LABEL_17:
    v12 = 0;
    goto LABEL_18;
  }
  v12 = *(_DWORD *)v14;
LABEL_18:
  v8 = a2;
LABEL_19:
  if ( v12 )
  {
    v21 = (int *)ExAllocatePoolWithTag(512, 32);
    v22 = v21;
    if ( v21 )
    {
      memset(v21, 0, 32);
      v23 = v22[1];
      v24 = *v22;
      v22[2] = a4;
      *v22 = v24 & 0xFFFFFFF8;
      v22[3] = *v8;
      v25 = v23 & 0xFFFFFFF8 | (varg_r2 >> 8) & 7;
      v22[1] = v25;
      v26 = varg_r2;
      if ( (varg_r2 & 0x800) != 0 )
      {
        v22[1] = v25 | 0x40000000;
        v26 = varg_r2;
      }
      if ( (v26 & 0x1000) != 0 )
        v22[1] |= 0x40000000u;
      v27 = *(_DWORD *)(v12 + 3512);
      v20 = SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxPrepareToQueue((int)a6, a1, v25, v22, (int)var30);
      if ( v20 >= 0 )
      {
        v22 = 0;
        v20 = SMKM_STORE_MGR<SM_TRAITS>::SmFeAddInitiate(
                a1,
                a2,
                (unsigned __int16 *)(v33 >> 12),
                v27 & 0x1F,
                (int)var30,
                a7);
        if ( v20 >= 0 )
        {
          v12 = 0;
          v11 = 0;
          v20 = 259;
        }
      }
    }
    else
    {
      v20 = -1073741670;
    }
    if ( v12 )
    {
      v28 = (_DWORD *)(a1 + 96 * (*(_DWORD *)(v12 + 3512) & 0x1F) + 4);
      __pld(v28);
      v29 = *v28 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v30 = __ldrex(v28);
      while ( v30 == v29 && __strex(v29 - 2, v28) );
      if ( v30 != v29 )
        ExfReleaseRundownProtection((unsigned __int8 *)v28);
    }
    if ( v22 )
      ExFreePoolWithTag(v22);
  }
  else
  {
    v20 = -1073741811;
  }
  SMKM_STORE_MGR<SM_TRAITS>::SmQueueContextCleanup(a1, var30);
  if ( v11 )
  {
    *a6 = 0;
    a6[1] = 0;
    *a6 = v20;
  }
  return v20;
}
