// sub_7EAB40 
 
void __fastcall sub_7EAB40(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  int v7; // r4
  int v8; // r7
  unsigned int v9; // r10

  if ( v7 == v8 )
  {
    ExFreePoolWithTag(v9);
    if ( !ExAllocatePoolWithQuotaTag(0x208u, a7, 1799976018) )
      JUMPOUT(0x7073BA);
    JUMPOUT(0x707332);
  }
  JUMPOUT(0x707394);
}
