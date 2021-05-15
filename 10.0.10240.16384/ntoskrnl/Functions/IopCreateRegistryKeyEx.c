// IopCreateRegistryKeyEx 
 
int __fastcall IopCreateRegistryKeyEx(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int result; // r0
  int v8; // [sp+18h] [bp-50h]
  int v9; // [sp+24h] [bp-44h]

  *a1 = 0;
  result = ZwCreateKey();
  if ( result == -1073741772 )
    return sub_7CB7C0();
  if ( result >= 0 )
  {
    *a1 = v9;
    if ( a6 )
      *a6 = v8;
  }
  return result;
}
