// sub_96AB3C 
 
void __fastcall sub_96AB3C(int a1, int a2, unsigned int a3)
{
  int v3; // r4

  *(_DWORD *)(v3 + 3140) = a3;
  if ( a3 > 0x7F )
    *(_DWORD *)(v3 + 3140) = 127;
  JUMPOUT(0x9558CC);
}
