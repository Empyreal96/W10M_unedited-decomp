// IopOpenRegistryKeyEx 
 
int __fastcall IopOpenRegistryKeyEx(_DWORD *a1)
{
  *a1 = 0;
  return ZwOpenKey();
}
