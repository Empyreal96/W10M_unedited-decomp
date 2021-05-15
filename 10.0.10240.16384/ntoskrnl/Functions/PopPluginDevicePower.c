// PopPluginDevicePower 
 
int __fastcall PopPluginDevicePower(int a1, int a2, int a3)
{
  int result; // r0

  result = PopPepDevicePoweredOn(*(_DWORD *)(a1 + 32));
  if ( result )
  {
    if ( !a3 )
      sub_53FB20();
  }
  return result;
}
