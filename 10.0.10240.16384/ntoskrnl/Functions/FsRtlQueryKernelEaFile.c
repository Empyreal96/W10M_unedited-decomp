// FsRtlQueryKernelEaFile 
 
int __fastcall FsRtlQueryKernelEaFile(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, char a8, _DWORD *a9)
{
  int v13; // r3
  int v14; // r6
  int v15; // r0
  int v16; // r4
  int v17; // r2
  int v18; // r2
  int v20; // [sp+8h] [bp-38h]
  int v21; // [sp+Ch] [bp-34h]
  _BYTE v22[48]; // [sp+10h] [bp-30h] BYREF

  v21 = 0;
  KeInitializeEvent((int)v22, 0, 0);
  if ( (a1[11] & 0x800) != 0 )
  {
    v13 = -1073741808;
LABEL_3:
    v20 = v13;
    goto LABEL_17;
  }
  v14 = IoGetRelatedDeviceObject(a1);
  v15 = IoAllocateIrpEx(v14, *(_BYTE *)(v14 + 48), 0);
  v16 = v15;
  v21 = v15;
  if ( !v15 )
  {
    v13 = -1073741670;
    goto LABEL_3;
  }
  v17 = *(_DWORD *)(v15 + 96);
  *(_BYTE *)(v17 - 40) = 7;
  *(_DWORD *)(v17 - 12) = a1;
  *(_DWORD *)(v15 + 60) = a2;
  *(_DWORD *)(v17 - 32) = a3;
  *(_DWORD *)(v17 - 28) = a5;
  *(_DWORD *)(v17 - 24) = a6;
  if ( a7 )
  {
    *(_DWORD *)(v17 - 20) = *a7;
    *(_BYTE *)(v17 - 38) |= 4u;
  }
  else
  {
    *(_DWORD *)(v17 - 20) = 0;
  }
  if ( a8 )
    *(_BYTE *)(v17 - 38) |= 1u;
  if ( a4 )
    *(_BYTE *)(v17 - 38) |= 2u;
  *(_DWORD *)(v15 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v15 + 8) = 4;
  *(_BYTE *)(v15 + 32) = 0;
  v18 = *(_DWORD *)(v15 + 96);
  *(_DWORD *)(v18 - 8) = SmKmGenericCompletion;
  *(_DWORD *)(v18 - 4) = v22;
  *(_BYTE *)(v18 - 37) = 0;
  *(_BYTE *)(v18 - 37) = 64;
  *(_BYTE *)(v18 - 37) = -64;
  *(_BYTE *)(v18 - 37) = -32;
  if ( IofCallDriver(v14, v15) == 259 && FsRtlCancellableWaitForSingleObject(v22, 0, 0) == -1073741749 )
  {
    IoCancelIrp(v16);
    KeWaitForSingleObject((unsigned int)v22, 0, 0, 0, 0);
  }
  v20 = *(_DWORD *)(v16 + 24);
  *a9 = *(_DWORD *)(v16 + 28);
LABEL_17:
  if ( v21 )
  {
    if ( *(_DWORD *)(v21 + 4) )
    {
      FsRtlpFreeMdlChain();
      *(_DWORD *)(v21 + 4) = 0;
    }
    IoFreeIrp(v21);
  }
  return v20;
}
