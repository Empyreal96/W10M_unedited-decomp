// KGetUnlockSetting 
 
int __fastcall KGetUnlockSetting(int a1, int a2, _DWORD *a3)
{
  int v4; // r4

  v4 = ZwOpenKey();
  if ( v4 >= 0 )
  {
    v4 = ZwQueryValueKey();
    if ( v4 >= 0 )
      return sub_7E9D18();
    ZwClose();
  }
  if ( v4 == -1073741772 )
  {
    *a3 = 0xFFFF;
    v4 = 0;
  }
  return v4;
}
