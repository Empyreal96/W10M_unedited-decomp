// BiGetFirmwareType 
 
int BiGetFirmwareType()
{
  int v0; // r3
  int v1; // r4
  int v3; // [sp+Ch] [bp-20h]

  v0 = (unsigned __int8)byte_64194E;
  __dmb(0xBu);
  if ( v0 )
    return dword_610340;
  v1 = 2;
  if ( ZwQuerySystemInformation() >= 0 )
  {
    v1 = v3;
    if ( v3 >= 3 )
      v1 = 0;
  }
  if ( !BiFirmwareVariablesSupported() )
    v1 = 3;
  dword_610340 = v1;
  __dmb(0xBu);
  byte_64194E = 1;
  return v1;
}
