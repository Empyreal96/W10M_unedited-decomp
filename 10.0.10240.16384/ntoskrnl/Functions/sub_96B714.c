// sub_96B714 
 
void __fastcall sub_96B714(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r0
  int v5; // r1

  v4 = 0;
  if ( v3 >= *(_DWORD *)(a3 + 12) )
  {
    v5 = a3;
    do
    {
      v5 += 12;
      ++v4;
    }
    while ( v3 >= *(_DWORD *)(v5 + 12) );
  }
  if ( *(_BYTE *)(a3 + 12 * v4 + 10) == 1 )
    JUMPOUT(0x957122);
  JUMPOUT(0x957124);
}
