// PnpGetDeviceInstanceRegistryValue 
 
int __fastcall PnpGetDeviceInstanceRegistryValue(int a1, int a2, int a3, int a4, int *a5)
{
  int v6; // r2
  int v7; // r3
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v13; // [sp+10h] [bp-8h] BYREF

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v6, v7);
  v8 = CmOpenDeviceRegKey(PiPnpRtlCtx, a1, 17, 0, 131097, 0, (int)&v13, 0);
  v9 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  if ( v8 >= 0 )
  {
    v8 = IopGetRegistryValue(v13, L"DeviceAddressCache", 26, a5);
    ZwClose();
  }
  return v8;
}
