// PiDevCfgGetDriverPackageId 
 
int __fastcall PiDevCfgGetDriverPackageId(int a1, int a2)
{
  int v4; // r4
  int v6; // [sp+10h] [bp-30h] BYREF
  int v7[10]; // [sp+18h] [bp-28h] BYREF

  v6 = 0;
  v4 = PnpOpenObjectRegKey(PiPnpRtlCtx, a1, 8, 131097, 0, (int)&v6, 0, 0);
  if ( v4 >= 0 )
  {
    memset(v7, 0, 24);
    v7[0] = (int)DEVPKEY_DriverInfFile_ActiveDriverPackage;
    v7[1] = 18;
    v7[2] = a2;
    v7[4] = 6;
    v4 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, a1, 8, v6, v7, 1);
    if ( v4 >= 0 && v7[5] < 0 )
      v4 = v7[5];
  }
  if ( v6 )
    ZwClose();
  return v4;
}
