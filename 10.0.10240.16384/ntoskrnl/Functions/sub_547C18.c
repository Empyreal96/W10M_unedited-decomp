// sub_547C18 
 
void __fastcall sub_547C18(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int *v3; // r7
  unsigned int *v4; // r8
  int v5; // r9
  unsigned int v6; // r2
  unsigned int v7; // r3

  if ( v5 != *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + a2 + 12) )
  {
    v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + a2 + 1728) + 16;
    v7 = v6 - KeKernelStackSize;
    if ( v6 - KeKernelStackSize <= v2 && v2 < v6 )
    {
      *v4 = v6;
      *v3 = v7;
      JUMPOUT(0x4C5DD8);
    }
  }
  JUMPOUT(0x4C5E32);
}
