// PiInitFirmwareResources 
 
int __fastcall PiInitFirmwareResources(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 144) & 1) != 0 )
    result = sub_97081C();
  else
    result = 0;
  return result;
}
