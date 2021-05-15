// sub_52734C 
 
void __fastcall sub_52734C(int a1, int a2, int a3, int a4, int a5, int a6, char a7)
{
  int v7; // r5
  int v8; // r10
  unsigned int i; // r1

  for ( i = a2 + 4; (i & 0xFFF) == 0; --a3 )
  {
    if ( !a3 )
      break;
    i = (v7 & (i >> 10)) - v8;
  }
  if ( i <= *((_DWORD *)&a7 + 2 * a3 + 1) )
    JUMPOUT(0x4D7896);
  JUMPOUT(0x4D78DC);
}
