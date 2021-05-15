// PnpGetServiceStartType 
 
int __fastcall PnpGetServiceStartType(int a1, int a2, _DWORD *a3)
{
  int v6; // r4
  unsigned int v7; // [sp+8h] [bp-28h] BYREF
  int v8; // [sp+Ch] [bp-24h] BYREF
  int v9; // [sp+10h] [bp-20h]

  *a3 = 4;
  v9 = 0;
  if ( ExIsManufacturingModeEnabled() )
    return sub_7CB4DC();
  v7 = 4;
  v6 = PnpCtxRegQueryValue(0, a2, L"Start", &v8, (int)a3, &v7);
  if ( v6 >= 0 && v8 != 4 )
  {
    v6 = -1073741772;
    *a3 = 4;
  }
  if ( v9 )
    ZwClose();
  return v6;
}
