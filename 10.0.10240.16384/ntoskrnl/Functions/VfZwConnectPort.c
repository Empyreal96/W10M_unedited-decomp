// VfZwConnectPort 
 
int __fastcall VfZwConnectPort(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v12; // r0
  int v13; // r3

  v12 = ViZwShouldCheck(a1, a2);
  v13 = a5;
  if ( v12 )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckUnicodeString(a2);
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a7);
    ViZwCheckVirtualAddress(a8);
    v13 = a5;
  }
  return pXdvZwConnectPort(a1, a2, a3, a4, v13, a6, a7, a8);
}
