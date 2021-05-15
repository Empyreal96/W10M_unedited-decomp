// VfZwMapViewOfSection 
 
int __fastcall VfZwMapViewOfSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v14; // r0
  int v15; // r1
  int vars4; // [sp+3Ch] [bp+4h]

  v14 = VfCheckPageProtection(a10, vars4);
  if ( ViZwShouldCheck(v14, v15) )
  {
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a6);
    ViZwCheckVirtualAddress(a7);
  }
  return pXdvZwMapViewOfSection(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
