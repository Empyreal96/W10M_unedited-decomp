// IopInvalidateVolumesForDevice 
 
int __fastcall IopInvalidateVolumesForDevice(int a1, int a2)
{
  int v2; // r5
  int v3; // r4
  int v4; // r8
  unsigned int v5; // r2
  int v6; // r0
  unsigned int v7; // r10
  int v8; // r3
  int *v9; // r5
  int *i; // r6
  int j; // r9
  int v12; // r0
  int v13; // r3
  int v14; // r0
  int v15; // r0
  __int16 v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v21; // [sp+18h] [bp-50h]
  int v22; // [sp+1Ch] [bp-4Ch] BYREF
  int v23; // [sp+20h] [bp-48h]
  int v24; // [sp+24h] [bp-44h]
  int v25; // [sp+28h] [bp-40h]
  int v26; // [sp+2Ch] [bp-3Ch]
  int v27; // [sp+30h] [bp-38h]
  int v28; // [sp+34h] [bp-34h]
  _DWORD _38[16]; // [sp+38h] [bp-30h] BYREF

  _38[15] = a2;
  v2 = a1;
  v21 = a1;
  _38[14] = a1;
  v3 = 0;
  v4 = a1;
  v25 = a1;
  while ( v4 )
  {
    if ( *(_DWORD *)(v4 + 36) )
    {
      v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v5 + 308);
      KeWaitForSingleObject(v4 + 156, 0, 0, 0, 0);
      v22 = 0;
      v23 = 0;
      v6 = IoCreateStreamFileObjectLite(0, v4);
      v24 = v6;
      v23 = v6;
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v4 + 36);
      v3 = ObOpenObjectByPointer(v6, 512, 0, 0, (int)IoFileObjectType, 0, &v22);
      v26 = v3;
      if ( v3 >= 0 )
      {
        v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v7 + 308);
        ExAcquireResourceSharedLite((int)&IopDatabaseResource, 1);
        v8 = *(_DWORD *)(v2 + 44);
        if ( v8 == 7 || v8 == 36 )
        {
          v9 = &IopDiskFileSystemQueueHead;
        }
        else if ( v8 == 2 )
        {
          v9 = &IopCdRomFileSystemQueueHead;
        }
        else
        {
          v9 = &IopTapeFileSystemQueueHead;
        }
        KeInitializeEvent((int)_38, 0, 0);
        v3 = 0;
        for ( i = (int *)*v9; i != v9 && (int *)*i != v9; i = (int *)*i )
        {
          for ( j = (int)(i - 13); *(_DWORD *)(j + 16); j = *(_DWORD *)(j + 16) )
            ;
          KeResetEvent((int)_38);
          v12 = IoBuildDeviceIoControlRequest(589908, j, (int)&v22, 4, 0, 0);
          if ( !v12 )
          {
            v3 = -1073741670;
            break;
          }
          v13 = *(_DWORD *)(v12 + 96);
          *(_BYTE *)(v13 - 40) = 13;
          *(_BYTE *)(v13 - 39) = 0;
          v14 = IofCallDriver(j, v12);
          if ( v14 == 259 )
          {
            KeWaitForSingleObject((unsigned int)_38, 0, 0, 0, 0);
            v14 = v27;
          }
          else
          {
            v27 = v14;
            v28 = 0;
          }
          if ( v14 == -1073741808 || v14 == -1073741822 )
            v14 = 0;
          if ( v3 >= 0 && v14 < 0 )
            v3 = v14;
        }
        v15 = ExReleaseResourceLite((int)&IopDatabaseResource);
        v16 = *(_WORD *)(v7 + 308) + 1;
        *(_WORD *)(v7 + 308) = v16;
        if ( !v16 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
          KiCheckForKernelApcDelivery(v15);
        if ( v24 )
        {
          ObfDereferenceObject(v24);
          if ( v22 )
            ZwClose();
        }
      }
      v17 = KeSetEvent(v4 + 156, 0, 0);
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x134) + 1;
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(v17);
      v2 = v21;
    }
    v4 = *(_DWORD *)(v4 + 16);
    v25 = v4;
  }
  return v3;
}
