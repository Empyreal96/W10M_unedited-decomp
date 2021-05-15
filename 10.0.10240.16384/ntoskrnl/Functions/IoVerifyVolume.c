// IoVerifyVolume 
 
int __fastcall IoVerifyVolume(_DWORD *a1, int a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r7
  int v7; // r3
  int v8; // r6
  int v9; // r0
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r3
  int v15; // r8
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20; // [sp+8h] [bp-40h] BYREF
  int v21; // [sp+Ch] [bp-3Ch] BYREF
  int v22[2]; // [sp+10h] [bp-38h] BYREF
  char var30[52]; // [sp+18h] [bp-30h] BYREF
  int vars4; // [sp+4Ch] [bp+4h]

  v22[0] = 0;
  v22[1] = 0;
  v4 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
  KeWaitForSingleObject((unsigned int)(a1 + 39), 0, 0, 0, 0);
  if ( !IopReferenceVerifyVpb((int)a1, &v21, &v20) )
  {
    v5 = 0;
LABEL_15:
    if ( IopCreateVpb((int)a1) < 0 || (PoVolumeDevice((int)a1), v20 = 0, IopMountVolume(a1, a2, 1, 0, &v20) < 0) )
    {
      a1[7] &= 0xFFFFFFFD;
    }
    else if ( v20 )
    {
      IopDecrementVpbRefCount(v20, 1);
    }
LABEL_20:
    v16 = KeSetEvent((int)(a1 + 39), 0, 0);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
    return v5;
  }
  KeInitializeEvent((int)var30, 0, 0);
  v6 = v20;
  v7 = *(_DWORD *)(v20 + 16);
  v8 = v20;
  while ( v7 )
  {
    v8 = v7;
    v7 = *(_DWORD *)(v7 + 16);
  }
  v9 = pIoAllocateIrp(v8, *(char *)(v8 + 48), 0, vars4);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 66;
    *(_DWORD *)(v9 + 44) = var30;
    *(_DWORD *)(v9 + 40) = v22;
    *(_BYTE *)(v9 + 32) = 0;
    *(_DWORD *)(v9 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_DWORD *)(v9 + 96);
    v15 = v21;
    *(_BYTE *)(v14 - 40) = 13;
    *(_BYTE *)(v14 - 38) = a2 != 0;
    *(_BYTE *)(v14 - 39) = 2;
    *(_DWORD *)(v14 - 32) = v15;
    *(_DWORD *)(v14 - 28) = v6;
    IopQueueThreadIrp(v9);
    v5 = IofCallDriver(v8, v10);
    if ( v5 == 259 )
    {
      KeWaitForSingleObject((unsigned int)var30, 0, 0, 0, 0);
      v5 = v22[0];
    }
    IopDereferenceVpbAndFree(v15);
    if ( v5 != -1073741806 )
      goto LABEL_20;
    goto LABEL_15;
  }
  v11 = KeSetEvent((int)(a1 + 39), 0, 0);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return -1073741670;
}
