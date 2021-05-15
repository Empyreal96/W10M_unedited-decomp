// VfZwCreateSection 
 
int __fastcall VfZwCreateSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v11; // r0
  int v12; // r1
  int vars4; // [sp+2Ch] [bp+4h]

  v11 = VfCheckPageProtection(a5, vars4);
  if ( ViZwShouldCheck(v11, v12) )
  {
    ViZwCheckVirtualAddress(a1);
    ViZwCheckObjectAttributes(a3);
    ViZwCheckVirtualAddress(a4);
  }
  return pXdvZwCreateSection(a1, a2, a3, a4, a5, a6, a7);
}
