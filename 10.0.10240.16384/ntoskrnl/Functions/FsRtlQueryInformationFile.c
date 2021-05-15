// FsRtlQueryInformationFile 
 
int __fastcall FsRtlQueryInformationFile(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v9; // r3
  int v10; // r6
  int v11; // r0
  int v12; // r4
  int v13; // r3
  int v14; // r2
  int v16; // [sp+8h] [bp-38h]
  int v17; // [sp+Ch] [bp-34h]
  _BYTE v18[48]; // [sp+10h] [bp-30h] BYREF

  v17 = 0;
  KeInitializeEvent((int)v18, 0, 0);
  if ( (a1[11] & 0x800) != 0 )
  {
    v9 = -1073741808;
LABEL_3:
    v16 = v9;
    goto LABEL_10;
  }
  v10 = IoGetRelatedDeviceObject(a1);
  v11 = IoAllocateIrpEx(v10, *(_BYTE *)(v10 + 48), 0);
  v12 = v11;
  v17 = v11;
  if ( !v11 )
  {
    v9 = -1073741670;
    goto LABEL_3;
  }
  v13 = *(_DWORD *)(v11 + 96);
  *(_BYTE *)(v13 - 40) = 5;
  *(_BYTE *)(v13 - 39) = 4;
  *(_DWORD *)(v13 - 12) = a1;
  *(_DWORD *)(v11 + 12) = a2;
  *(_DWORD *)(v13 - 32) = a3;
  *(_DWORD *)(v13 - 28) = a4;
  *(_DWORD *)(v11 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v11 + 8) |= 4u;
  *(_BYTE *)(v11 + 32) = 0;
  v14 = *(_DWORD *)(v11 + 96);
  *(_DWORD *)(v14 - 8) = SmKmGenericCompletion;
  *(_DWORD *)(v14 - 4) = v18;
  *(_BYTE *)(v14 - 37) = 0;
  *(_BYTE *)(v14 - 37) = 64;
  *(_BYTE *)(v14 - 37) = -64;
  *(_BYTE *)(v14 - 37) = -32;
  if ( IofCallDriver(v10, v11) == 259 && FsRtlCancellableWaitForSingleObject((int)v18, 0, 0, 259) == -1073741749 )
  {
    IoCancelIrp(v12);
    KeWaitForSingleObject((unsigned int)v18, 0, 0, 0, 0);
  }
  v16 = *(_DWORD *)(v12 + 24);
  *a5 = *(_DWORD *)(v12 + 28);
LABEL_10:
  if ( v17 )
  {
    if ( *(_DWORD *)(v17 + 4) )
    {
      FsRtlpFreeMdlChain();
      *(_DWORD *)(v17 + 4) = 0;
    }
    IoFreeIrp(v17);
  }
  return v16;
}
