// sub_8AAA38 
 
int __fastcall sub_8AAA38(int a1, int a2)
{
  int result; // r0

  sub_8AA934(a2);
  result = sub_8AAB70(0, a1, DEVPKEY_Device_InstanceId, 18, a2);
  if ( result >= 0 )
  {
    result = PnpGetDeviceInstancePropertyData(*(_DWORD *)(a2 + 8));
    *(_BYTE *)(a2 + 30) = 3;
    *(_BYTE *)(a2 + 29) = 16;
    *(_BYTE *)(a2 + 28) = 0;
    *(_DWORD *)(a2 + 32) = 0;
  }
  return result;
}
