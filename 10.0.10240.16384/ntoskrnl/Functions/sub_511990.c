// sub_511990 
 
void __fastcall sub_511990(int a1)
{
  char v1; // r4

  if ( (v1 & 4) == 0 && !KeGetCurrentIrql(a1) )
  {
    if ( MmDynamicPfn )
      JUMPOUT(0x42AAB0);
  }
  JUMPOUT(0x42AB0C);
}
