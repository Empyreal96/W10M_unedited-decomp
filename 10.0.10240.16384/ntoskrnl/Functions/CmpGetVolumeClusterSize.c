// CmpGetVolumeClusterSize 
 
int __fastcall CmpGetVolumeClusterSize(int a1, int *a2)
{
  int v4; // r4
  int v5; // r0
  int v6; // r8
  int v8; // r0
  int v9; // r6
  int v10; // r5
  _DWORD *v11; // r0
  int v12; // r7
  int v13; // r2
  int v14; // r2
  int v15; // r4
  unsigned int v16; // r2
  int v17; // r2
  int v18; // [sp+8h] [bp-70h] BYREF
  int v19; // [sp+Ch] [bp-6Ch] BYREF
  int v20; // [sp+10h] [bp-68h] BYREF
  int v21; // [sp+20h] [bp-58h] BYREF
  int v22[21]; // [sp+24h] [bp-54h] BYREF

  v18 = 0;
  memset(v22, 0, 24);
  v22[0] = 0;
  v21 = 6;
  v4 = ObReferenceObjectByHandle(a1, 0, *(_DWORD *)CmIoFileObjectType, 0, &v20);
  if ( v4 >= 0 )
  {
    v5 = CmpCreateEvent(0, &v19, &v18);
    v6 = v20;
    if ( v5 < 0 )
      return sub_7F3E64();
    v8 = IoGetAttachedDeviceReference(*(_DWORD *)(v20 + 4));
    v9 = v8;
    v10 = v18;
    if ( v8 )
    {
      v11 = (_DWORD *)IoAllocateIrp(*(_BYTE *)(v8 + 48), 0);
      v12 = (int)v11;
      if ( !v11 )
      {
LABEL_28:
        v4 = ZwQueryVolumeInformationFile();
        if ( v4 < 0 )
          goto LABEL_19;
        v16 = v22[12];
LABEL_14:
        if ( v16 > 0x1000 )
          v16 = 4096;
        v4 = 0;
        if ( v16 < 0x200 )
        {
          v17 = 1;
        }
        else
        {
          v17 = v16 >> 9;
          if ( ((v17 - 1) & v17) != 0 )
          {
            v4 = -1073741288;
            goto LABEL_19;
          }
        }
        *a2 = v17;
LABEL_19:
        if ( v9 )
          ObfDereferenceObject(v9);
        ObfDereferenceObject(v6);
        if ( v10 )
        {
          ObfDereferenceObject(v10);
          ZwClose();
        }
        return v4;
      }
      v13 = v11[24];
      *(_BYTE *)(v13 - 40) = 14;
      *(_DWORD *)(v13 - 16) = v9;
      *(_DWORD *)(v13 - 24) = 2954240;
      *(_DWORD *)(v13 - 32) = 28;
      *(_DWORD *)(v13 - 28) = 12;
      v11[3] = &v21;
      v11[15] = &v21;
      v11[2] = 80;
      v14 = v11[24];
      v11[6] = -1073741637;
      *(_DWORD *)(v14 - 8) = CmpGetVolumeClusterSizeCompletion;
      *(_DWORD *)(v14 - 4) = v10;
      *(_BYTE *)(v14 - 37) = -32;
      v15 = IofCallDriver(v9, (int)v11);
      if ( v15 == 259 )
      {
        KeWaitForSingleObject(v10, 0, 0, 0, 0);
        v15 = *(_DWORD *)(v12 + 24);
      }
      IoFreeIrp(v12);
    }
    else
    {
      v15 = -1073741811;
    }
    v16 = 0;
    if ( v15 >= 0 )
    {
      if ( v22[0] < 0x18u || !v22[4] || (v16 = v22[4], ((v22[4] - 1) & v22[4]) != 0) )
        v15 = -1073741288;
      if ( v15 >= 0 )
        goto LABEL_14;
    }
    goto LABEL_28;
  }
  return v4;
}
