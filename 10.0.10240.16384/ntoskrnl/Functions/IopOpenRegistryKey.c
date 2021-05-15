// IopOpenRegistryKey 
 
int __fastcall IopOpenRegistryKey(int a1, int a2, int a3, int a4, char a5)
{
  int result; // r0

  if ( a5 )
    result = sub_7EF5A4(a1, a4);
  else
    result = ZwOpenKey();
  return result;
}
