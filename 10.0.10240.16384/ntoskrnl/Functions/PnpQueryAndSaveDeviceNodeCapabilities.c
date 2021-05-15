// PnpQueryAndSaveDeviceNodeCapabilities 
 
int __fastcall PnpQueryAndSaveDeviceNodeCapabilities(_DWORD *a1)
{
  int result; // r0
  _BYTE v3[72]; // [sp-4h] [bp-48h] BYREF

  result = PpIrpQueryCapabilities(a1[4], v3);
  if ( result >= 0 )
    result = PnpSaveDeviceCapabilities(a1, (int)v3);
  return result;
}
