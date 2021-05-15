// PnpRequestDeviceRemoval 
 
int __fastcall PnpRequestDeviceRemoval(int result, int a2, int a3)
{
  int v3; // r4
  int v6; // r0

  v3 = result;
  if ( result )
  {
    PnpAcquireDependencyRelationsLock(1, a2);
    v6 = PnpRequestDeviceRemovalWorker(v3, v3, a2, 2, 0);
    PnpReleaseDependencyRelationsLock(v6);
    result = PnpSetTargetDeviceRemove(*(_DWORD *)(v3 + 16), 1, 1, 0, 1, a3, 0, 0, 0, 0, 0, 0, 0);
  }
  return result;
}
