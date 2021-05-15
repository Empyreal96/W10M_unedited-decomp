// sub_80E9A0 
 
void __fastcall sub_80E9A0(int a1, int a2, unsigned int *a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r3

  v3 = *a3;
  v4 = *a3 & 0x7F;
  if ( v4 > 0x64 || !v4 || (v3 & 0xFFFFFF80) != 0 )
  {
    if ( !a2 )
      JUMPOUT(0x79806E);
    *a3 = v3 & 0xFFFFFF80 | 0x64;
  }
  JUMPOUT(0x798050);
}
