// IoShutdownSystem 
 
_DWORD *__fastcall IoShutdownSystem(int a1)
{
  _DWORD *result; // r0
  unsigned int j; // r5
  int v4; // r7
  int v5; // r0
  unsigned int i; // r5
  int v7; // r7
  int v8; // r0
  int v9; // [sp+Ch] [bp-2Ch]
  char v10[8]; // [sp+10h] [bp-28h] BYREF
  char v11[32]; // [sp+18h] [bp-20h] BYREF

  if ( VfIsVerifierEnabled() )
    VfNotifyVerifierOfEvent(1);
  result = (_DWORD *)KeInitializeEvent((int)v11, 0, 0);
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      IopShutdownFileSystems = 1;
      ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, 1, (int)&IopShutdownFileSystems);
      IopShutdownBaseFileSystems(&IopDiskFileSystemQueueHead);
      IopShutdownBaseFileSystems(&IopCdRomFileSystemQueueHead);
      IopShutdownBaseFileSystems(&IopTapeFileSystemQueueHead);
      result = IopInterlockedRemoveHeadList(&IopNotifyLastChanceShutdownQueueHead);
      for ( i = (unsigned int)result; result; i = (unsigned int)result )
      {
        v7 = IoGetAttachedDeviceReference(*(_DWORD *)(i + 8));
        v8 = ((int (__fastcall *)(int, int, _DWORD, _DWORD, _DWORD, char *, char *, int))IoBuildSynchronousFsdRequest)(
               16,
               v7,
               0,
               0,
               0,
               v11,
               v10,
               v9);
        if ( v8 && IofCallDriver(v7, v8) == 259 )
          KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
        ObfDereferenceObject(v7);
        ObfDereferenceObject(*(_DWORD *)(i + 8));
        ExFreePoolWithTag(i);
        KeResetEvent((int)v11);
        result = IopInterlockedRemoveHeadList(&IopNotifyLastChanceShutdownQueueHead);
      }
    }
  }
  else
  {
    PnpShutdownDevices(result);
    result = IopInterlockedRemoveHeadList(&IopNotifyShutdownQueueHead);
    for ( j = (unsigned int)result; result; j = (unsigned int)result )
    {
      v4 = IoGetAttachedDeviceReference(*(_DWORD *)(j + 8));
      v5 = ((int (__fastcall *)(int, int, _DWORD, _DWORD, _DWORD, char *, char *, int))IoBuildSynchronousFsdRequest)(
             16,
             v4,
             0,
             0,
             0,
             v11,
             v10,
             v9);
      if ( v5 && IofCallDriver(v4, v5) == 259 )
        KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
      ObfDereferenceObject(v4);
      ObfDereferenceObject(*(_DWORD *)(j + 8));
      ExFreePoolWithTag(j);
      KeResetEvent((int)v11);
      result = IopInterlockedRemoveHeadList(&IopNotifyShutdownQueueHead);
    }
    if ( (MmVerifierData & 0x10) != 0 )
      result = (_DWORD *)IovUnloadDrivers();
  }
  return result;
}
