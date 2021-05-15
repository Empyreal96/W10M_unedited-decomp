// PiDcHandleInterfaceEvent 
 
int __fastcall PiDcHandleInterfaceEvent(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // [sp+20h] [bp-78h] BYREF
  int v5; // [sp+24h] [bp-74h] BYREF
  char v6[16]; // [sp+28h] [bp-70h] BYREF
  char v7[96]; // [sp+38h] [bp-60h] BYREF

  v2 = *(_DWORD *)(a1 + 4);
  result = 0;
  if ( (v2 & 1) != 0 )
  {
    result = PnpGetObjectProperty(
               PiPnpRtlCtx,
               *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12),
               3,
               0,
               0,
               (int)DEVPKEY_Device_ContainerId,
               (int)&v5,
               (int)v6,
               16,
               (int)&v4,
               0);
    if ( result >= 0 && v5 == 13 && v4 == 16 )
    {
      result = PnpStringFromGuid((int)v6, (int)v7);
      if ( result >= 0 )
        result = PiDcContainerRequiresConfiguration(v7);
    }
  }
  return result;
}
