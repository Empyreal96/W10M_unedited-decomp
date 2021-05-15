// VfZwAlpcAcceptConnectPort 
 
int __fastcall VfZwAlpcAcceptConnectPort(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int8 a9)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a7);
    ViZwCheckVirtualAddress(a8);
    ((void (__fastcall *)(int))ViZwCheckObjectAttributes)(a4);
  }
  return pXdvZwAlpcAcceptConnectPort(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
