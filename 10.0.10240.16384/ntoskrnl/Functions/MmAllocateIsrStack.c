// MmAllocateIsrStack 
 
int __fastcall MmAllocateIsrStack(int *a1, int a2)
{
  int v3; // r3
  int v4; // r0
  unsigned int v5; // r4
  int v7; // r4

  v3 = *a1;
  if ( *a1 )
  {
    v7 = v3 - 12288;
    if ( MmSetPageProtection(v3 - 12288, 12288, 4u) )
    {
      v5 = v7 - 4096;
      goto LABEL_4;
    }
  }
  else
  {
    v4 = MmAllocateIndependentPages(0x4000, a2);
    v5 = v4;
    if ( v4 )
    {
      *a1 = v4 + 0x4000;
LABEL_4:
      MiMarkBootGuardPage(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
      return 1;
    }
  }
  return 0;
}
