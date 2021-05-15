// sub_7BF66C 
 
int sub_7BF66C()
{
  int v0; // r3
  int v1; // r2
  _DWORD *v2; // r4
  int v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r8
  int v7; // r9
  int v8; // r1
  int v9; // r5
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v16; // [sp+0h] [bp-38h] BYREF
  unsigned int v17[12]; // [sp+8h] [bp-30h] BYREF

  ExfAcquirePushLockExclusiveEx((_DWORD *)((char *)v2 + v4), v3, (unsigned int)v2 + v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v1 = v2[1482];
  if ( (v1 & 8) == 0 )
  {
    v9 = SmRegistrationCtxStart(v2 + 1567, v8, v1, 6268);
    if ( v9 < 0 )
      goto LABEL_6;
    v1 = v2[1482] | 8;
    v2[1482] = v1;
  }
  if ( (v1 & 2) == 0 )
  {
    v9 = SMKM_STORE_MGR<SM_TRAITS>::SmStorePrepare((int)v2);
    if ( v9 < 0 )
      goto LABEL_6;
    v1 = v2[1482] | 2;
    v2[1482] = v1;
  }
  if ( (v1 & 0x10) != 0
    || (v1 = v2[1482] ^ (v2[1482] ^ (16 * MmStoreChargeResidentAvailableForRead(1))) & 0x10,
        v2[1482] = v1,
        (v1 & 0x10) != 0) )
  {
    v0 = v2[1483];
    if ( v0 )
    {
      if ( v6 != v0 )
      {
        v9 = -1073741800;
        goto LABEL_6;
      }
    }
    else
    {
      v16 = (v6 & 0xFFFF000 | 0x10000300u) >> 8;
      v17[0] = v16 & 0xFFFF0 | v5;
      v17[1] = v16 & 0xFFFF0 | v7;
      v9 = SmFpPreAllocate((int)(v2 + 1571), v17, 2);
      if ( v9 < 0 )
        goto LABEL_6;
      v9 = SmFpPreAllocate((int)(v2 + 1587), &v16, 1);
      if ( v9 < 0 )
      {
        SmFpCleanup((int)(v2 + 1571));
        SmFpInitialize((int)(v2 + 1571));
        goto LABEL_6;
      }
      v2[1483] = v6;
      v1 = v2[1482];
    }
    if ( (v1 & 0x20) == 0 )
    {
      v9 = ExAllocatePrivateWorkerPool();
      if ( v9 < 0 )
        goto LABEL_6;
      v1 = v2[1482] | 0x20;
      v2[1482] = v1;
    }
    if ( (v1 & 1) == 0 )
    {
      v9 = MmStoreRegister();
      if ( v9 < 0 )
        goto LABEL_6;
      v2[1482] |= 1u;
    }
    v9 = 0;
  }
  else
  {
    v9 = -1073741670;
  }
LABEL_6:
  __dmb(0xBu);
  v10 = (_DWORD *)((char *)v2 + v4);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((_DWORD *)((char *)v2 + v4));
  v12 = KeAbPostRelease((unsigned int)v2 + v4);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return ((int (__fastcall *)(int))v17[11])(v9);
}
