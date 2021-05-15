// -StDeviceIoMarkFailed@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DEVICE_IO@1@J@Z 
 
_DWORD *__fastcall ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed(_DWORD *result, int a2)
{
  int v2; // r3

  result[3] |= 1u;
  v2 = result[1];
  if ( v2 )
    *(_DWORD *)(v2 + 4) = a2;
  else
    *result = a2;
  return result;
}
