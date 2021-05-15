// sub_51D37C 
 
void __fastcall sub_51D37C(int a1, int a2, int a3)
{
  unsigned int v3; // r6
  unsigned int v4; // r7
  unsigned int v5; // r2

  if ( a3 != *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + a1 + 12) )
  {
    v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + a1 + 1728) + 16;
    if ( v4 <= v5 && v3 >= v5 - KeKernelStackSize )
      JUMPOUT(0x44A2DC);
    JUMPOUT(0x44A2D0);
  }
  JUMPOUT(0x44A2BC);
}
