// PiCMConvertDeviceKeyType 
 
int __fastcall PiCMConvertDeviceKeyType(__int16 a1, int *a2)
{
  int v3; // r3
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r3

  *a2 = 0;
  v3 = (unsigned __int8)a1;
  result = 0;
  if ( v3 == 18 )
  {
    v5 = 18;
  }
  else
  {
    if ( v3 != 17 )
      return sub_7EF38C(0);
    v5 = 17;
  }
  *a2 = v5;
  v6 = a1 & 0xFF00;
  if ( (a1 & 0xFF00) != 0 )
  {
    if ( v6 == 256 )
    {
      v7 = *a2 | 0x100;
    }
    else
    {
      if ( v6 != 512 )
        JUMPOUT(0x7EF39A);
      v7 = *a2 | 0x200;
    }
    *a2 = v7;
  }
  return result;
}
