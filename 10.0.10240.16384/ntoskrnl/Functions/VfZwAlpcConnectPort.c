// VfZwAlpcConnectPort 
 
int __fastcall VfZwAlpcConnectPort(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v15; // r0
  int v16; // r3
  int v17; // r2
  int v18; // r1

  v15 = ViZwShouldCheck(a1, a2);
  v16 = a8;
  v17 = a7;
  v18 = a6;
  if ( v15 )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a7);
    ViZwCheckVirtualAddress(a8);
    ViZwCheckVirtualAddress(a9);
    ViZwCheckVirtualAddress(a10);
    ViZwCheckVirtualAddress(a11);
    ViZwCheckObjectAttributes(a3);
    ViZwCheckUnicodeString(a2);
    v16 = a8;
    v17 = a7;
    v18 = a6;
  }
  return pXdvZwAlpcConnectPort(a1, a2, a3, a4, a5, v18, v17, v16, a9, a10, a11);
}
