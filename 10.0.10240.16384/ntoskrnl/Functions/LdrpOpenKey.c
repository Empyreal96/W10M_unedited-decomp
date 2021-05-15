// LdrpOpenKey 
 
int __fastcall LdrpOpenKey(int a1, int a2, int a3, _DWORD *a4)
{
  *a4 = 0;
  return ZwOpenKey();
}
