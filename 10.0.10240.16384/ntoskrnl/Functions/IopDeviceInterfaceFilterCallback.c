// IopDeviceInterfaceFilterCallback 
 
int __fastcall IopDeviceInterfaceFilterCallback(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // r0
  char v6[40]; // [sp+8h] [bp-28h] BYREF

  result = 0;
  v6[0] = 0;
  if ( a3 == 3 && a4 )
  {
    if ( *a4 )
    {
      result = sub_7C73EC();
    }
    else if ( PiPnpRtlApplyMandatoryFilters(a1, a2, 3, 0, a4 + 1, v6) < 0 )
    {
      result = 0;
    }
    else
    {
      result = (unsigned __int8)v6[0];
    }
  }
  return result;
}
