// sub_52153C 
 
void __fastcall sub_52153C(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v5; // r5
  unsigned int i; // r3
  _DWORD *v7; // r2

  if ( v4 <= a4 >> 1 )
  {
    v7 = (_DWORD *)(a1 + 4);
    if ( v4 )
    {
      do
      {
        v7 = (_DWORD *)*v7;
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    for ( i = a4 - v4; i; --i )
      a3 = *(_DWORD *)(a3 + 4);
  }
  JUMPOUT(0x455090);
}
