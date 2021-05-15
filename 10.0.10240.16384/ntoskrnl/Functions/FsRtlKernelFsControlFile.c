// FsRtlKernelFsControlFile 
 
int __fastcall FsRtlKernelFsControlFile(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, unsigned int *a7)
{
  unsigned int v7; // r6
  char v9; // r4
  unsigned int v11; // r10
  int v12; // r3
  _DWORD *v13; // r0
  int v14; // r4
  int v15; // r3
  bool v16; // zf
  int v17; // r5
  unsigned int v18; // r10
  int v19; // r0
  int v20; // r0
  int v21; // r2
  unsigned int v22; // r1
  int v25; // [sp+Ch] [bp-44h]
  int v26; // [sp+10h] [bp-40h]
  int v27; // [sp+14h] [bp-3Ch]
  _DWORD _20[18]; // [sp+20h] [bp-30h] BYREF

  _20[14] = a1;
  _20[15] = a2;
  v7 = a4;
  _20[17] = a4;
  _20[16] = a3;
  v9 = a2;
  v27 = 0;
  KeInitializeEvent((int)_20, 0, 0);
  v11 = v9 & 3;
  if ( (a1[11] & 0x800) != 0 )
  {
    v12 = -1073741808;
LABEL_3:
    v26 = v12;
    goto LABEL_36;
  }
  v25 = IoGetRelatedDeviceObject(a1);
  v13 = (_DWORD *)IoAllocateIrpEx(v25, *(_BYTE *)(v25 + 48), 0);
  v14 = (int)v13;
  v27 = (int)v13;
  if ( !v13 )
  {
LABEL_5:
    v12 = -1073741670;
    goto LABEL_3;
  }
  v15 = v13[24];
  *(_BYTE *)(v15 - 40) = 13;
  *(_BYTE *)(v15 - 39) = 4;
  *(_DWORD *)(v15 - 12) = a1;
  *(_DWORD *)(v15 - 32) = a6;
  *(_DWORD *)(v15 - 28) = v7;
  *(_DWORD *)(v15 - 24) = a2;
  if ( !v11 )
  {
    if ( v7 || a6 )
    {
      v17 = a5;
      if ( v7 < a6 )
      {
        v13[3] = a5;
        memmove(a5, a3, v7);
      }
      else
      {
        v13[3] = a3;
      }
      *(_DWORD *)(v14 + 8) = 16;
      *(_DWORD *)(v14 + 60) = a5;
      v18 = a4;
      if ( a5 )
      {
        *(_DWORD *)(v14 + 8) |= 0x40u;
        v20 = v25;
        goto LABEL_27;
      }
      goto LABEL_26;
    }
    v13[2] = 0;
    v13[15] = 0;
    v17 = a5;
    goto LABEL_17;
  }
  if ( v11 > 2 )
  {
    v16 = v11 == 3;
    v17 = a5;
    v18 = a4;
    if ( v16 )
    {
      v13[15] = a5;
      *(_DWORD *)(v15 - 20) = a3;
    }
    goto LABEL_26;
  }
  if ( a3 )
  {
    v13[3] = a3;
    v13[2] = 16;
  }
  else
  {
    v13[2] = 0;
  }
  v17 = a5;
  if ( !a5 )
  {
LABEL_17:
    v18 = a4;
LABEL_26:
    v20 = v25;
    goto LABEL_27;
  }
  v19 = IoAllocateMdl(a5, a6, 0, 0, 0);
  *(_DWORD *)(v14 + 4) = v19;
  if ( !v19 )
    goto LABEL_5;
  MmProbeAndLockPages(v19);
  v18 = a4;
  v20 = v25;
LABEL_27:
  *(_DWORD *)(v14 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v14 + 8) |= 4u;
  *(_BYTE *)(v14 + 32) = 0;
  v21 = *(_DWORD *)(v14 + 96);
  *(_DWORD *)(v21 - 8) = SmKmGenericCompletion;
  *(_DWORD *)(v21 - 4) = _20;
  *(_BYTE *)(v21 - 37) = 0;
  *(_BYTE *)(v21 - 37) = 64;
  *(_BYTE *)(v21 - 37) = -64;
  *(_BYTE *)(v21 - 37) = -32;
  if ( IofCallDriver(v20, v14) == 259 && FsRtlCancellableWaitForSingleObject(_20, 0, 0) == -1073741749 )
  {
    IoCancelIrp(v14);
    KeWaitForSingleObject((unsigned int)_20, 0, 0, 0, 0);
  }
  v26 = *(_DWORD *)(v14 + 24);
  v22 = *(_DWORD *)(v14 + 28);
  *a7 = v22;
  if ( v26 >= 0 && v22 && v18 >= a6 )
  {
    if ( v22 >= a6 )
      v22 = a6;
    memmove(v17, a3, v22);
  }
LABEL_36:
  if ( v27 )
  {
    if ( *(_DWORD *)(v27 + 4) )
    {
      FsRtlpFreeMdlChain();
      *(_DWORD *)(v27 + 4) = 0;
    }
    IoFreeIrp(v27);
  }
  return v26;
}
