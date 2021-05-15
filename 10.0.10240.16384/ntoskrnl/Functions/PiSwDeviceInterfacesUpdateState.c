// PiSwDeviceInterfacesUpdateState 
 
int __fastcall PiSwDeviceInterfacesUpdateState(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 100) == a1 + 100 )
    result = 0;
  else
    result = sub_7E0A00();
  return result;
}
