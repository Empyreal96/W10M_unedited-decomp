// IoSetHardErrorOrVerifyDevice 
 
int __fastcall IoSetHardErrorOrVerifyDevice(int result, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(result + 80);
  if ( v2 )
    *(_DWORD *)(v2 + 920) = a2;
  return result;
}
