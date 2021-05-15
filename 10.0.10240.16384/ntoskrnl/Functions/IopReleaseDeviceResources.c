// IopReleaseDeviceResources 
 
int __fastcall IopReleaseDeviceResources(_DWORD *a1, int a2)
{
  int result; // r0
  int v5; // r4
  unsigned __int8 v6; // r8
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r1
  void (__fastcall *v12)(int, int, int); // r3
  int v13; // [sp+10h] [bp-30h] BYREF
  int v14; // [sp+14h] [bp-2Ch] BYREF
  int v15; // [sp+18h] [bp-28h] BYREF
  __int16 v16; // [sp+20h] [bp-20h]
  __int16 v17; // [sp+22h] [bp-1Eh]
  const __int16 *v18; // [sp+24h] [bp-1Ch]

  if ( !a1[71] && (a1[67] & 0x80) == 0 )
    return 0;
  v5 = 0;
  v14 = 0;
  v15 = 0;
  v6 = 0;
  if ( a2 && (a1[67] & 1) == 0 )
  {
    if ( IopQueryDeviceResources(a1[4], 0, &v15, &v14) < 0 )
      return sub_7E0D84();
    v5 = v15;
  }
  result = IopLegacyResourceAllocation(-1, PnpDriverObject, a1[4]);
  if ( result >= 0 )
  {
    PnpRequestDeviceAction(0, 0, 0, 0, 0, 0);
    if ( a2 && (a1[67] & 1) == 0 )
    {
      v13 = 0;
      if ( v5 )
        v6 = 1;
      if ( CmOpenDeviceRegKey(PiPnpRtlCtx, a1[6], 20, 0, 983103, v6, (int)&v13, 0) >= 0 )
      {
        v17 = 22;
        v16 = 20;
        v18 = L"BootConfig";
        v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v7 + 308);
        ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
        if ( v5 )
          ZwSetValueKey();
        else
          ZwDeleteValueKey();
        v8 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
        *(_WORD *)(v9 + 308) = v10;
        if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
          KiCheckForKernelApcDelivery(v8);
        ZwClose();
      }
      if ( v5 )
      {
        PipSetDevNodeFlags((int)a1, 64);
        v11 = a1[4];
        v12 = (void (__fastcall *)(int, int, int))IopAllocateBootResourcesRoutine;
        a1[90] = v5;
        v12(4, v11, v5);
      }
    }
    return 0;
  }
  return result;
}
