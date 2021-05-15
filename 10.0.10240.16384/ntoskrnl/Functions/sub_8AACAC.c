// sub_8AACAC 
 
int __fastcall sub_8AACAC(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // r0
  int v8; // [sp+10h] [bp-18h] BYREF
  int v9[5]; // [sp+14h] [bp-14h] BYREF

  if ( a1 )
    result = IoGetDevicePropertyData(a1);
  else
    result = PnpGetDeviceInterfacePropertyData(a2, a3, 0, a6, a5, a6, (int)v9, (int)&v8);
  if ( result >= 0 )
  {
    if ( v8 == a4 )
    {
      if ( v9[0] != a5 )
        result = -1073741820;
    }
    else
    {
      result = -1073741788;
    }
  }
  return result;
}
