// _CmIsDeviceInContainer 
 
int __fastcall CmIsDeviceInContainer(int *a1, int a2, int a3, int a4, unsigned __int16 *a5, _BYTE *a6, _BYTE *a7)
{
  int v9; // r4
  int v10; // r0
  unsigned int v12[9]; // [sp+14h] [bp-24h] BYREF

  *a6 = 0;
  *a7 = 0;
  v9 = PnpCtxRegOpenKey(a1, a2, a3, 0);
  if ( v9 >= 0 )
  {
    v9 = PnpCtxRegOpenKey(a1, 0, (int)L"BaseContainers", 0);
    if ( v9 >= 0 )
    {
      v10 = PnpCtxRegOpenKey(a1, 0, a4, 0);
      v9 = v10;
      if ( v10 >= 0 )
      {
        *a6 = 1;
        v9 = PnpCtxRegQueryValue(v10, 0, a5, 0, 0, v12);
        if ( v9 >= 0 )
          *a7 = 1;
      }
    }
  }
  if ( v9 == -1073741772 || v9 == -1073741444 )
    v9 = 0;
  return v9;
}
