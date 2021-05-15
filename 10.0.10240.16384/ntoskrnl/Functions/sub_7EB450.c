// sub_7EB450 
 
void __fastcall sub_7EB450(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r6

  do
  {
    *(_BYTE *)(v4 + v3) = *(_BYTE *)(v3 + a3);
    ++v3;
  }
  while ( v3 < a2 );
  JUMPOUT(0x765004);
}
