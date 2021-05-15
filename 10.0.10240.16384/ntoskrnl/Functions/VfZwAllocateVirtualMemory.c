// VfZwAllocateVirtualMemory 
 
int __fastcall VfZwAllocateVirtualMemory(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v10; // r0
  int v11; // r1
  int vars4; // [sp+24h] [bp+4h]

  v10 = VfCheckPageProtection(a6, vars4);
  if ( ViZwShouldCheck(v10, v11) )
  {
    ViZwCheckVirtualAddress(a2);
    ViZwCheckVirtualAddress(a4);
  }
  return pXdvZwAllocateVirtualMemory(a1, a2, a3, a4);
}
