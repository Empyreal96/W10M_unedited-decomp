// IopDoDeferredSetInterfaceState 
 
int __fastcall IopDoDeferredSetInterfaceState(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v2, v3);
  v4 = PpMarkDeviceStackExtensionFlag(*(_DWORD *)(a1 + 16), 16, 0);
  return sub_7C9588(v4);
}
