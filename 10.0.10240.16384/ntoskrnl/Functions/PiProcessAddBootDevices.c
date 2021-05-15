// PiProcessAddBootDevices 
 
int __fastcall PiProcessAddBootDevices(int a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v7; // [sp+0h] [bp-18h] BYREF
  int v8; // [sp+8h] [bp-10h] BYREF
  char v9; // [sp+Ch] [bp-Ch]

  v7 = 0;
  v2 = *(_DWORD **)(*(_DWORD *)(a1 + 176) + 20);
  if ( v2[43] == 770 )
  {
    v3 = v2[67];
    if ( (v3 & 0x6000) == 0 && (v3 & 2) == 0 && !v2[73] )
    {
      PiPnpRtlBeginOperation(&v7, a2, 770, 0);
      v8 = 0;
      v9 = PnPBootDriversInitialized;
      if ( PipCallDriverAddDevice((int)v2, (int)&v8) >= 0 )
        PoFxPrepareDevice((int)v2, 0, v4, v5);
      if ( v7 )
        PiPnpRtlEndOperation(v7);
    }
  }
  return 0;
}
