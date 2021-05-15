// _CmIsDeviceRegPropWritable 
 
int __fastcall CmIsDeviceRegPropWritable(int a1, _BYTE *a2)
{
  unsigned int v3; // r3
  int result; // r0

  v3 = a1 - 1;
  result = 0;
  if ( v3 > 0x24 || !*((_BYTE *)DevicePropertyRead + a1) )
    return -1073741264;
  *a2 = *((_BYTE *)DevicePropertyWrite + a1);
  return result;
}
