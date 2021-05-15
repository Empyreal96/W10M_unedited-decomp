// PnpGetDeviceResourcesFromRegistry 
 
int __fastcall PnpGetDeviceResourcesFromRegistry(int a1, int a2, char a3, int *a4, _DWORD *a5)
{
  int v5; // r4
  int v9; // r0
  int v10; // r2
  int v12; // r2
  __int16 *v13; // r1
  int v14; // r2
  int v15; // r2
  unsigned int v16; // r5
  int v17; // r1
  int v18; // r0
  int v19; // r2
  int v20; // [sp+10h] [bp-28h] BYREF
  unsigned int v21[9]; // [sp+14h] [bp-24h] BYREF

  v5 = 0;
  *a4 = 0;
  *a5 = 0;
  if ( a2 )
  {
    if ( a1 )
      v12 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    else
      v12 = 0;
    v5 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v12 + 24), 20, 0, 131097, 0, (int)&v20, 0);
    if ( v5 < 0 )
      return v5;
    if ( (a3 & 1) != 0 )
    {
      v13 = L"OverrideConfigVector";
    }
    else
    {
      if ( (a3 & 2) == 0 )
        goto LABEL_25;
      v13 = L"BasicConfigVector";
    }
    v5 = IopGetRegistryValue(v20, (unsigned __int16 *)v13, 0, (int *)v21);
    if ( v5 >= 0 )
    {
      v16 = v21[0];
      if ( *(_DWORD *)(v21[0] + 4) == 10 )
      {
        v17 = *(_DWORD *)(v21[0] + 12);
        if ( v17 )
        {
          v18 = ExAllocatePoolWithTag(1, v17, 1970499664);
          *a4 = v18;
          if ( v18 )
          {
            *a5 = *(_DWORD *)(v16 + 12);
            memmove(*a4, *(_DWORD *)(v16 + 8) + v16, *(_DWORD *)(v16 + 12));
            v19 = *a4;
            if ( *(_DWORD *)(*a4 + 4) == -1 )
            {
              *(_DWORD *)(v19 + 8) = 0;
              *(_DWORD *)(v19 + 4) = PnpDefaultInterfaceType;
            }
          }
          else
          {
            v5 = -1073741584;
          }
        }
      }
      ExFreePoolWithTag(v16);
    }
    goto LABEL_25;
  }
  if ( (a3 & 1) == 0
    || (!a1 ? (v15 = 0) : (v15 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20)),
        v5 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v15 + 24), 19, 0, 131097, 0, (int)&v20, 0),
        v5 < 0) )
  {
    v9 = 0;
    v20 = 0;
    if ( (a3 & 2) == 0 )
      goto LABEL_24;
    if ( a1 )
      v14 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    else
      v14 = 0;
    v5 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v14 + 24), 20, 0, 131097, 0, (int)&v20, 0);
    if ( v5 < 0 )
      return v5;
    v5 = PnpReadDeviceConfiguration(v20, 2, a4, a5);
    v9 = v20;
    if ( v5 < 0 )
    {
LABEL_24:
      if ( (a3 & 4) != 0 )
      {
        if ( !v9 )
        {
          if ( a1 )
            v10 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
          else
            v10 = 0;
          v5 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v10 + 24), 20, 0, 131097, 0, (int)&v20, 0);
          if ( v5 < 0 )
            return v5;
          v9 = v20;
        }
        v5 = PnpReadDeviceConfiguration(v9, 4, a4, a5);
        v9 = v20;
      }
      if ( !v9 )
        return v5;
    }
LABEL_25:
    ZwClose();
    return v5;
  }
  return sub_7E13A8();
}
