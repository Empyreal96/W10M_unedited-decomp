// -SmIoCtxQueueWork@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU_SM_IO_CONTEXT@1@PAU1@KPAX@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxQueueWork(int *a1, int a2, __int16 a3, int *a4)
{
  int *v8; // r9
  int *v9; // r5
  int *v10; // r3
  int v11; // r3
  int v12; // r4
  void (__fastcall *v13)(int, int *, int); // r4
  int v14; // r3
  _DWORD *v15; // r7
  int v16; // r4
  int v17; // r2
  int *v18; // r0
  bool v19; // zf
  int v20; // r0
  int v21; // r3
  int *v22; // r4
  _DWORD *v23; // r1
  int v25[2]; // [sp+8h] [bp-40h] BYREF
  __int16 v26; // [sp+10h] [bp-38h]
  _DWORD v27[12]; // [sp+18h] [bp-30h] BYREF

  v27[0] = 0;
  v27[1] = v27;
  v27[2] = 0;
  v27[3] = 0;
  v8 = 0;
  if ( ((unsigned __int8)a4 & 1) != 0 )
  {
    v9 = (int *)((unsigned int)a4 & 0xFFFFFFFE);
    if ( ((unsigned int)a4 & 0xFFFFFFFE) == *(_DWORD *)(((unsigned int)a4 & 0xFFFFFFFE) + 4) )
      v10 = 0;
    else
      v10 = (int *)(*v9 & 0xFFFFFFF8);
    v11 = *v10;
  }
  else
  {
    v8 = a4;
    v12 = SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxPrepareToQueue((int)a1, a2, a3, a4, (int)v27);
    if ( v12 < 0 )
      goto LABEL_32;
    v11 = *a4;
    v9 = v27;
  }
  if ( (v11 & 7) != 2 )
    goto LABEL_25;
  v13 = *(void (__fastcall **)(int, int *, int))(a2 + 5892);
  if ( v13 )
  {
    v25[0] = *a1;
    v14 = v8[3];
    v26 = a3;
    v25[1] = v14;
    v13(a2, v25, 5);
  }
  v15 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v16 = *(_DWORD *)(96 * (a3 & 0x1F) + a2);
  if ( (*(_BYTE *)(v16 + 3517) & 4) == 0 || (v8[1] & 0x4000000) == 0 )
    goto LABEL_25;
  v17 = (v15[240] >> 9) & 7;
  if ( (*(_DWORD *)(v15[84] + 192) & 0x100000) != 0 )
    v17 = 0;
  if ( v17 >= 2 )
    goto LABEL_20;
  if ( v15 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v15[250] )
    v17 = 2;
  if ( v17 >= 2 )
  {
LABEL_20:
    v18 = (int *)v9[1];
    if ( v18 != v9 )
    {
      v19 = *v9 == (_DWORD)v18;
      *v9 = *(_DWORD *)*v9 & 0xFFFFFFF8;
      if ( v19 )
      {
        *v9 = 0;
        v9[1] = (int)v9;
      }
      else
      {
        *v18 = *v18 & 7 | (8 * ((unsigned int)*v18 >> 3) - 8);
      }
    }
    memset((_BYTE *)v8 + 32, 0, 24);
    v8[12] = v16;
    v8[13] = a2 + 5128;
    v20 = KeQueryPriorityThread((int)v15);
    SMKM_STORE_MGR<SM_TRAITS>::SmAsyncReadQueueInsert(a2 + 5128, (int)(v8 + 8), v20, v21);
  }
  else
  {
LABEL_25:
    v22 = (int *)v9[1];
    if ( v22 == v9 )
    {
      v23 = 0;
    }
    else
    {
      v23 = (_DWORD *)*v9;
      v19 = *v9 == (_DWORD)v22;
      *v9 = *(_DWORD *)*v9 & 0xFFFFFFF8;
      if ( v19 )
      {
        *v9 = 0;
        v9[1] = (int)v9;
      }
      else
      {
        *v22 = *v22 & 7 | (8 * ((unsigned int)*v22 >> 3) - 8);
      }
    }
    SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(*(_DWORD *)(96 * (a3 & 0x1F) + a2), v23, 0);
  }
  v9[2] = 0;
  v12 = 0;
LABEL_32:
  SMKM_STORE_MGR<SM_TRAITS>::SmQueueContextCleanup(a2, v27);
  return v12;
}
