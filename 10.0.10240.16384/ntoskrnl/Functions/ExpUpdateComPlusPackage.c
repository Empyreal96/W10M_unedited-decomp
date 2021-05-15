// ExpUpdateComPlusPackage 
 
int __fastcall ExpUpdateComPlusPackage(int a1, int a2)
{
  int v2; // r4

  v2 = ZwOpenKey();
  if ( v2 == -1073741772 )
    v2 = ZwCreateKey();
  if ( v2 >= 0 )
  {
    v2 = ZwSetValueKey();
    ZwClose();
  }
  return v2;
}
