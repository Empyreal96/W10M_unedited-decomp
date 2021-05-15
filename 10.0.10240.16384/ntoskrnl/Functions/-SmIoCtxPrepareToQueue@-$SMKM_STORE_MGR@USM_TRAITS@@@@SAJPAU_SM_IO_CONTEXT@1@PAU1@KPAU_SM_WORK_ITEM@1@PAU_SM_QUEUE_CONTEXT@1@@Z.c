// -SmIoCtxPrepareToQueue@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU_SM_IO_CONTEXT@1@PAU1@KPAU_SM_WORK_ITEM@1@PAU_SM_QUEUE_CONTEXT@1@@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxPrepareToQueue(int a1, int a2, int a3, int *a4, int a5)
{
  unsigned int *v5; // r4 OVERLAPPED
  int v6; // r3
  unsigned int *v7; // r7
  int v9; // r5
  int v10; // r6
  int v12; // r7
  int *v13; // r1
  unsigned int v14; // r3
  unsigned int v16; // [sp+8h] [bp-28h] BYREF
  unsigned int *v17; // [sp+Ch] [bp-24h]

  v5 = (unsigned int *)a4;
  v16 = 0;
  v6 = *a4;
  v7 = &v16;
  v9 = 0;
  v10 = 0;
  v5[6] = a1;
  v17 = &v16;
  if ( (v6 & 7) != 0 && (v6 & 7) != 2 )
    goto LABEL_8;
  v10 = v5[2];
  if ( (*(_DWORD *)(a2 + 5888) & 2) == 0 )
    goto LABEL_8;
  v9 = SmFpAllocate(a2 + 5720, 4, a1, v10);
  if ( v9 )
  {
    v7 = v17;
LABEL_8:
    *v5 = *v5 & 7 | (8 * ((*v7 >> 3) + 1));
    *v7 = *v7 & 7 | (unsigned int)v5;
    v17 = v5;
    if ( v5 == &v16 )
    {
      v13 = (int *)v16;
    }
    else
    {
      v14 = v16;
      *(_QWORD *)a5 = *(_QWORD *)(&v5 - 1);
      v5 = &v16;
      v13 = 0;
      v16 = 0;
      v17 = &v16;
    }
    if ( v9 )
      *(_DWORD *)(a5 + 8) = v10;
    *(_DWORD *)(a5 + 12) = a1;
    v12 = 0;
    goto LABEL_14;
  }
  v12 = -1073741670;
  while ( 1 )
  {
    v13 = (int *)v16;
    v5 = v17;
LABEL_14:
    if ( v5 == &v16 )
      break;
    v16 = *v13 & 0xFFFFFFF8;
    if ( v13 == (int *)v5 )
    {
      v17 = &v16;
      v16 = 0;
    }
    else
    {
      *v5 = *v5 & 7 | (8 * (*v5 >> 3) - 8);
    }
    SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource(a2);
  }
  return v12;
}
