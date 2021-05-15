// -SmAsyncReadQueueInsert@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU_SM_ASYNC_READ_QUEUE@1@PAU_SM_ASYNC_DIRECT_READ_CTX@1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmAsyncReadQueueInsert(int a1, int a2, unsigned int a3, int a4)
{
  int *v4; // r6
  __int64 v5; // r3
  int v6; // r5
  unsigned int *v7; // r4
  int v8; // r8
  unsigned int v9; // r2
  int *v10; // r2
  int *v11; // r3
  int result; // r0
  int *v13; // r0
  bool v14; // zf
  int *v15; // [sp+0h] [bp-28h] BYREF
  int *v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v17 = a4;
  v16 = (int *)&v15;
  v4 = (int *)a2;
  v15 = 0;
  v5 = *(_QWORD *)(a2 + 16);
  v6 = a1 + 16 * a3;
  *(_DWORD *)(a2 + 16) = v5 & 0xFFFFFFF8 | a3 & 7;
  *(_DWORD *)(a2 + 20) = HIDWORD(v5) & 0xFFFFFFFC | (a3 >> 3) & 3;
  v7 = (unsigned int *)(a1 + 512);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v7);
  }
  else
  {
    do
      v9 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(v7);
  }
  if ( *(_DWORD *)(v6 + 8) || *(_DWORD *)(v6 + 12) )
  {
    *v4 = **(_DWORD **)(v6 + 4) + 1;
    **(_DWORD **)(v6 + 4) = v4;
    *(_DWORD *)(v6 + 4) = v4;
    if ( *v4 >= (unsigned int)KeNumberProcessors_0 && v4 != (int *)v6 )
    {
      v11 = *(int **)v6;
      *(_DWORD *)(v6 + 4) = v6;
      v15 = v11;
      v16 = v4;
      *(_DWORD *)v6 = 0;
    }
    v4 = v16;
  }
  else
  {
    v10 = v16;
    *v4 = *v16 + 1;
    *v10 = (int)v4;
    v16 = v4;
  }
  *(_DWORD *)(v6 + 8) += *v4;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  result = KfLowerIrql(v8);
  while ( v16 != (int *)&v15 )
  {
    v13 = v15;
    v14 = v15 == v16;
    v15 = (int *)*v15;
    if ( v14 )
    {
      v16 = (int *)&v15;
      v15 = 0;
    }
    else
    {
      --*v16;
    }
    v13[2] = (int)SMKM_STORE_MGR<SM_TRAITS>::SmAsyncReadQueueWorker;
    v13[3] = (int)v13;
    *v13 = 0;
    result = ExQueueWorkItemToPrivatePool();
  }
  return result;
}
