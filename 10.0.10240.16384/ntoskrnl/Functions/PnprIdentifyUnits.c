// PnprIdentifyUnits 
 
int __fastcall PnprIdentifyUnits(int a1, int a2, _DWORD *a3, int a4)
{
  int v8; // r4
  int v9; // r3
  int v10; // r2
  int v11; // r2
  int v12; // r2
  int v14[8]; // [sp+8h] [bp-58h] BYREF
  int v15[14]; // [sp+28h] [bp-38h] BYREF

  memset(v14, 0, 28);
  memset(v15, 0, 28);
  v8 = PnpQueryInterface(a2, (int)&GUID_PARTITION_UNIT_INTERFACE_STANDARD, 1, 0x1Cu, 0, (int)v14);
  if ( v8 < 0 )
  {
    v9 = PnprContext;
    v10 = *(_DWORD *)(PnprContext + 608);
    if ( !v10 )
      v10 = 1304;
LABEL_4:
    *(_DWORD *)(v9 + 608) = v10;
    v11 = *(_DWORD *)(v9 + 612);
    if ( !v11 )
      v11 = 3;
LABEL_6:
    *(_DWORD *)(v9 + 612) = v11;
    goto LABEL_26;
  }
  v8 = PnpQueryInterface(a1, (int)&GUID_PARTITION_UNIT_INTERFACE_STANDARD, 1, 0x1Cu, 0, (int)v15);
  if ( v8 < 0 )
  {
    v9 = PnprContext;
    v10 = *(_DWORD *)(PnprContext + 608);
    if ( !v10 )
      v10 = 1316;
    goto LABEL_4;
  }
  if ( v15[4] && v14[4] && v14[6] )
  {
    v8 = ((int (__fastcall *)(int, _DWORD *))v15[4])(v15[1], a3);
    if ( v8 < 0 )
    {
      v9 = PnprContext;
      v10 = *(_DWORD *)(PnprContext + 608);
      if ( !v10 )
        v10 = 1336;
      goto LABEL_4;
    }
    v8 = ((int (__fastcall *)(int, int))v14[4])(v14[1], a4);
    if ( v8 < 0 )
    {
      v9 = PnprContext;
      v10 = *(_DWORD *)(PnprContext + 608);
      if ( !v10 )
        v10 = 1344;
      goto LABEL_4;
    }
    if ( !((int (__fastcall *)(int, int, _DWORD, _DWORD))v14[6])(v14[1], v14[6], *a3, a3[1]) )
    {
      v8 = -1073741811;
      v9 = PnprContext;
      v12 = *(_DWORD *)(PnprContext + 608);
      if ( !v12 )
        v12 = 1357;
      *(_DWORD *)(PnprContext + 608) = v12;
      v11 = *(_DWORD *)(v9 + 612);
      if ( !v11 )
        v11 = 4;
      goto LABEL_6;
    }
    v8 = 0;
  }
  else
  {
    v8 = -1073741811;
  }
LABEL_26:
  if ( v14[1] )
    ((void (*)(void))v14[3])();
  if ( v15[1] )
    ((void (*)(void))v15[3])();
  return v8;
}
