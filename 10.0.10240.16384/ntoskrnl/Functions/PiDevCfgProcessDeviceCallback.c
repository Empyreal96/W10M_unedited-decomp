// PiDevCfgProcessDeviceCallback 
 
int __fastcall PiDevCfgProcessDeviceCallback(int a1)
{
  int v2; // r3
  int *v4; // r0
  int v5; // [sp+28h] [bp-48h] BYREF
  int v6; // [sp+2Ch] [bp-44h] BYREF
  int v7; // [sp+30h] [bp-40h] BYREF
  int v8[3]; // [sp+34h] [bp-3Ch] BYREF
  int v9; // [sp+40h] [bp-30h] BYREF
  char v10[32]; // [sp+44h] [bp-2Ch] BYREF

  v9 = 0;
  memset(v10, 0, sizeof(v10));
  v5 = 0;
  v6 = 0;
  v8[1] = 0;
  v8[0] = 1;
  v7 = 0;
  if ( *(_DWORD *)(a1 + 24) && CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 16, 0, 983103, 0, (int)&v6, 0) >= 0 )
  {
    v7 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v6, 11, (int)v8, (int)&v5, (int)&v7) >= 0
      && v8[0] == 4
      && v7 == 4 )
    {
      v2 = v5;
    }
    else
    {
      v2 = 0;
      v5 = 0;
    }
    if ( (v2 & 0x40000) != 0 )
    {
      if ( PiDevCfgInitDeviceContext(*(_DWORD *)(a1 + 24), v6, (int)&v9) >= 0 )
        return sub_8162EC();
    }
    else if ( (v2 & 0x20) != 0 )
    {
      v4 = *(int **)(a1 + 16);
      if ( (*(_DWORD *)(a1 + 268) & 0x6000) != 0 )
      {
        PnpRequestDeviceAction(v4, 1, 1, 0, 0, 0);
        PnpRequestDeviceAction(*(int **)(a1 + 16), 16, 1, 0, 0, 0);
      }
      else
      {
        PnpSetTargetDeviceRemove((int)v4, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0);
      }
    }
  }
  PiDevCfgFreeDeviceContext(&v9);
  if ( v6 )
    ZwClose();
  return 0;
}
