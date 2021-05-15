// PiQueryAndAllocateBootResources 
 
int __fastcall PiQueryAndAllocateBootResources(_DWORD *a1)
{
  int v2; // r3
  unsigned int v3; // r4
  int v4; // r0
  int v5; // r6
  unsigned __int8 v6; // r8
  int v8; // r2
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  int v13; // r3
  int v14; // [sp+10h] [bp-30h] BYREF
  int v15; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v16; // [sp+18h] [bp-28h] BYREF
  __int16 v17; // [sp+20h] [bp-20h]
  __int16 v18; // [sp+22h] [bp-1Eh]
  const __int16 *v19; // [sp+24h] [bp-1Ch]

  v2 = a1[90];
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v15 = 0;
  v16 = 0;
  v6 = 0;
  v14 = 0;
  if ( !v2 )
  {
    v5 = IopQueryDeviceResources(a1[4], 0, &v16, &v15);
    v4 = v14;
    if ( v5 < 0 )
      return sub_7C9C50(v14);
    v3 = v16;
  }
  v8 = a1[67] & 0x2000;
  if ( !v8 || a1[69] != 9 )
  {
    if ( !v8 || (v13 = a1[69], v13 != 3) && v13 != 19 )
    {
      if ( v3 )
        v6 = 1;
      if ( CmOpenDeviceRegKey(PiPnpRtlCtx, a1[6], 20, 0, 983103, v6, (int)&v14, 0) >= 0 )
      {
        v4 = v14;
      }
      else
      {
        v4 = 0;
        v14 = 0;
      }
      if ( v4 && !a1[90] )
      {
        v18 = 22;
        v17 = 20;
        v19 = L"BootConfig";
        v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v9 + 308);
        ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
        if ( v3 )
          ZwSetValueKey();
        else
          ZwDeleteValueKey();
        v10 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
        *(_WORD *)(v11 + 308) = v12;
        if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
          KiCheckForKernelApcDelivery(v10);
        if ( !v3 )
          goto LABEL_26;
        v5 = IopAllocateBootResourcesRoutine(4, a1[4], v3);
        if ( v5 >= 0 )
          PipSetDevNodeFlags(a1, 64);
        v4 = v14;
      }
    }
  }
  if ( v3 )
  {
    ExFreePoolWithTag(v3);
LABEL_26:
    v4 = v14;
  }
  if ( v4 )
    ZwClose();
  return v5;
}
