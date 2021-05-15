// sub_7C54F0 
 
void __fastcall sub_7C54F0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r6

  if ( (*(_BYTE *)(a5 & 0xFFFFFFF8) & 0x7F) != v5 )
  {
    ObfDereferenceObject(a5 & 0xFFFFFFF8);
    JUMPOUT(0x6C2B06);
  }
  JUMPOUT(0x6C2AFA);
}
