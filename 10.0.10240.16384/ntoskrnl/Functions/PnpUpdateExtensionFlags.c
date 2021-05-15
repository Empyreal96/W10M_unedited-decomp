// PnpUpdateExtensionFlags 
 
int __fastcall PnpUpdateExtensionFlags(int *a1, int a2, int a3, int a4)
{
  int result; // r0

  for ( result = *a1; result; result = *(_DWORD *)(result + 16) )
  {
    if ( !a4 )
      return sub_5201E8();
    *(_DWORD *)(*(_DWORD *)(result + 176) + 16) |= 4u;
  }
  return result;
}
