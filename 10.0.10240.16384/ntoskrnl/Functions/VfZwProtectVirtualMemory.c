// VfZwProtectVirtualMemory 
 
int __fastcall VfZwProtectVirtualMemory(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r0
  int v10; // r1
  int vars4; // [sp+24h] [bp+4h]

  v9 = VfCheckPageProtection(a4, vars4);
  if ( ViZwShouldCheck(v9, v10) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a5);
  }
  return pXdvZwProtectVirtualMemory(a1, a2, a3, a4);
}
