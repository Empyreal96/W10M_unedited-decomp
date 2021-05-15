// sub_96ACDC 
 
void __fastcall sub_96ACDC(int a1, int a2, void *a3)
{
  int v3; // r10

  if ( a3 == &unk_61004C )
    MEMORY[0xFFFF9264] = a2;
  else
    MEMORY[0xFFFF9264] = v3;
  JUMPOUT(0x955BB8);
}
