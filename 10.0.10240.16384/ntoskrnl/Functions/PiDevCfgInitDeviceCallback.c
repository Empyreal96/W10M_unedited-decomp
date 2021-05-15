// PiDevCfgInitDeviceCallback 
 
int __fastcall PiDevCfgInitDeviceCallback(int a1, int a2, _BYTE *a3)
{
  char v5; // r3
  int v7; // [sp+10h] [bp-50h] BYREF
  int v8; // [sp+14h] [bp-4Ch] BYREF
  int v9; // [sp+18h] [bp-48h] BYREF
  int v10; // [sp+1Ch] [bp-44h] BYREF
  int v11; // [sp+20h] [bp-40h] BYREF
  int v12; // [sp+28h] [bp-38h] BYREF
  char v13[32]; // [sp+2Ch] [bp-34h] BYREF

  v12 = 0;
  memset(v13, 0, sizeof(v13));
  v7 = 0;
  v8 = 0;
  v11 = 0;
  v10 = 1;
  v9 = 0;
  if ( PnpOpenObjectRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 20), 983103, 0, (int)&v8, 0, 0) >= 0 )
  {
    v9 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 12), v8, 11, (int)&v10, (int)&v7, (int)&v9) >= 0
      && v10 == 4
      && v9 == 4 )
    {
      v5 = v7;
    }
    else
    {
      v5 = 0;
      v7 = 0;
    }
    if ( (v5 & 0x20) == 0 )
    {
      if ( PiDevCfgInitDeviceContext(*(_DWORD *)(a1 + 12), v8, (int)&v12) < 0 )
        goto LABEL_13;
      if ( PiDevCfgCheckDeviceNeedsUpdate((int)&v12, &v11) >= 0 && v11 )
      {
        v7 |= v11;
        PiDevCfgSetDeviceRegProp(PiPnpRtlCtx, &v12, 11, 4, (int)&v7, 4);
      }
    }
    *a3 = 0;
  }
LABEL_13:
  PiDevCfgFreeDeviceContext(&v12);
  if ( v8 )
    ZwClose();
  return 0;
}
