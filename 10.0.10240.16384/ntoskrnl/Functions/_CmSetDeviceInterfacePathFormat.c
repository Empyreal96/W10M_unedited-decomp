// _CmSetDeviceInterfacePathFormat 
 
int __fastcall CmSetDeviceInterfacePathFormat(int a1, int a2, int a3)
{
  int result; // r0
  const __int16 *v6; // r2

  result = CmValidateDeviceInterfaceName(a1, (unsigned __int16 *)a2);
  if ( result >= 0 )
  {
    if ( a3 )
      v6 = L"\\??\\";
    else
      v6 = L"\\\\?\\";
    *(_DWORD *)a2 = *(_DWORD *)v6;
    *(_DWORD *)(a2 + 4) = *((_DWORD *)v6 + 1);
  }
  return result;
}
