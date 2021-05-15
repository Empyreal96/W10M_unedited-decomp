// PpMarkDeviceStackExtensionFlag 
 
int __fastcall PpMarkDeviceStackExtensionFlag(int a1, int a2, int a3)
{
  int v6; // r0

  v6 = KeAcquireQueuedSpinLock(10);
  while ( a1 )
  {
    if ( a3 )
      *(_DWORD *)(*(_DWORD *)(a1 + 176) + 16) |= a2;
    else
      *(_DWORD *)(*(_DWORD *)(a1 + 176) + 16) &= ~a2;
    a1 = *(_DWORD *)(a1 + 16);
  }
  return KeReleaseQueuedSpinLock(10, v6);
}
