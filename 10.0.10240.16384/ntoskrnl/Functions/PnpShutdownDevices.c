// PnpShutdownDevices 
 
int PnpShutdownDevices()
{
  int v0; // r6
  _BYTE *v1; // r5
  _DWORD *v2; // r4
  unsigned int v3; // r2
  int v4; // r3
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3
  int v8; // r1
  unsigned int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  _DWORD *v13; // r3
  unsigned int *v14; // r2
  unsigned int v15; // r4
  unsigned int v16; // r4
  _BYTE *v18; // [sp+20h] [bp-D8h] BYREF
  __int16 v19[2]; // [sp+28h] [bp-D0h] BYREF
  char *v20; // [sp+2Ch] [bp-CCh]
  char v21[8]; // [sp+30h] [bp-C8h] BYREF
  char v22; // [sp+38h] [bp-C0h] BYREF

  KeSetEvent((int)&PnpShutdownEvent, 0, 0);
  v0 = 0;
  if ( !PnpTearDownPnpStacksOnShutdown && (PopShutdownCleanly & 0x20) == 0 )
    return v0;
  v1 = PnpCreateDeviceEventEntry(333);
  if ( !v1 )
    return -1073741670;
  KeWaitForSingleObject((unsigned int)&PnpEventQueueEmpty, 0, 0, 0, 0);
  KeWaitForSingleObject((unsigned int)&PnpEnumerationLock, 0, 0, 0, 0);
  v19[0] = 0;
  v2 = (_DWORD *)IopRootDeviceNode;
  v19[1] = 160;
  v20 = &v22;
  PipSetDevNodeUserFlags(IopRootDeviceNode, 16);
  while ( 2 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v3 + 308);
    ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
    v2 = (_DWORD *)v2[1];
    while ( v2 )
    {
      v4 = v2[68];
      if ( (v4 & 0x20) != 0 )
      {
        if ( v2 == (_DWORD *)IopRootDeviceNode )
        {
          v2 = 0;
          break;
        }
LABEL_23:
        v13 = (_DWORD *)*v2;
        if ( *v2 )
          goto LABEL_25;
        v2 = (_DWORD *)v2[2];
        PipSetDevNodeUserFlags((int)v2, 32);
      }
      else
      {
        if ( (v4 & 0x10) == 0 )
          break;
        v13 = (_DWORD *)v2[1];
        if ( !v13 )
        {
          PipSetDevNodeUserFlags((int)v2, 32);
          goto LABEL_23;
        }
LABEL_25:
        v2 = v13;
      }
    }
    v5 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(_WORD *)(v6 + 0x134) + 1;
    *(_WORD *)(v6 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v5);
    if ( v2 )
    {
      PnpInitializeTargetDeviceRemoveEvent((int)v1, 333, v2[4], 0, 1, 0, 0, 46, 0, 0, (int)v21, (int)v19);
      v18 = v1;
      v0 = PnpProcessQueryRemoveAndEject((int *)&v18, v8);
      v9 = (unsigned int)v18;
      if ( v18 != v1 )
      {
        __dmb(0xBu);
        v10 = (unsigned int *)(v9 + 32);
        do
        {
          v11 = __ldrex(v10);
          v12 = v11 - 1;
        }
        while ( __strex(v12, v10) );
        __dmb(0xBu);
        if ( !v12 )
          ExFreePoolWithTag(v9);
      }
      continue;
    }
    break;
  }
  __dmb(0xBu);
  v14 = (unsigned int *)(v1 + 32);
  do
  {
    v15 = __ldrex(v14);
    v16 = v15 - 1;
  }
  while ( __strex(v16, v14) );
  __dmb(0xBu);
  if ( !v16 )
    ExFreePoolWithTag((unsigned int)v1);
  return v0;
}
