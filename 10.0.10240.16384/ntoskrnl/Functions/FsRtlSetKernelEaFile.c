// FsRtlSetKernelEaFile 
 
int __fastcall FsRtlSetKernelEaFile(_DWORD *a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r6
  int v8; // r0
  int v9; // r4
  int v10; // r3
  int v11; // r2
  int v13; // [sp+8h] [bp-30h]
  int v14; // [sp+Ch] [bp-2Ch]
  _BYTE v15[40]; // [sp+10h] [bp-28h] BYREF

  v14 = 0;
  KeInitializeEvent((int)v15, 0, 0);
  if ( (a1[11] & 0x800) != 0 )
  {
    v6 = -1073741808;
  }
  else
  {
    v7 = IoGetRelatedDeviceObject(a1);
    v8 = IoAllocateIrpEx(v7, *(_BYTE *)(v7 + 48), 0);
    v9 = v8;
    v14 = v8;
    if ( v8 )
    {
      v10 = *(_DWORD *)(v8 + 96);
      *(_BYTE *)(v10 - 40) = 8;
      *(_BYTE *)(v10 - 39) = 4;
      *(_DWORD *)(v10 - 12) = a1;
      *(_DWORD *)(v8 + 60) = a2;
      *(_DWORD *)(v10 - 32) = a3;
      *(_DWORD *)(v8 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v8 + 8) = 4;
      *(_BYTE *)(v8 + 32) = 0;
      v11 = *(_DWORD *)(v8 + 96);
      *(_DWORD *)(v11 - 8) = SmKmGenericCompletion;
      *(_DWORD *)(v11 - 4) = v15;
      *(_BYTE *)(v11 - 37) = 0;
      *(_BYTE *)(v11 - 37) = 64;
      *(_BYTE *)(v11 - 37) = -64;
      *(_BYTE *)(v11 - 37) = -32;
      if ( IofCallDriver(v7, v8) == 259 && FsRtlCancellableWaitForSingleObject(v15, 0, 0) == -1073741749 )
      {
        IoCancelIrp(v9);
        KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
      }
      v6 = *(_DWORD *)(v9 + 24);
    }
    else
    {
      v6 = -1073741670;
    }
  }
  v13 = v6;
  if ( v14 )
  {
    if ( *(_DWORD *)(v14 + 4) )
    {
      FsRtlpFreeMdlChain();
      *(_DWORD *)(v14 + 4) = 0;
    }
    IoFreeIrp(v14);
  }
  return v13;
}
