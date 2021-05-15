// FsRtlInitializeTunnels 
 
int FsRtlInitializeTunnels()
{
  unsigned int v1; // r2
  unsigned int v2; // r3
  __int16 v3; // [sp+10h] [bp-10h] BYREF
  __int16 v4; // [sp+12h] [bp-Eh]
  const __int16 *v5; // [sp+14h] [bp-Ch]

  if ( (_BYTE)dword_681280 )
    return sub_96E618();
  v5 = L"MaximumTunnelEntries";
  v3 = 40;
  v4 = 42;
  FsRtlGetTunnelParameterValue((int)&v3, &TunnelMaxEntries);
  v5 = L"MaximumTunnelEntryAgeInSeconds";
  v3 = 60;
  v4 = 62;
  FsRtlGetTunnelParameterValue((int)&v3, &TunnelMaxAge);
  if ( TunnelMaxAge )
  {
    v1 = TunnelMaxEntries;
  }
  else
  {
    v1 = 0;
    TunnelMaxEntries = 0;
  }
  TunnelMaxAge *= (_DWORD)dword_989680;
  if ( v1 > 0xFFFF )
  {
    v2 = 256;
  }
  else
  {
    v2 = (unsigned __int16)v1 >> 4;
    if ( v1 && !v2 )
      v2 = (unsigned __int16)(v1 + 1);
  }
  if ( v2 > 0x100 )
    LOWORD(v2) = 256;
  return ExInitializePagedLookasideList((int)&TunnelLookasideList, 0, 0, 0, 136, 1282307412, v2);
}
