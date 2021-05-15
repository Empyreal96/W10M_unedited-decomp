// sub_7C5110 
 
void __fastcall sub_7C5110(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r5
  int v6; // r6

  while ( 1 )
  {
    if ( (v5[6] & 1) == 0 )
    {
      if ( AuthzBasepEqualUnicodeString((int)(v5 + 2), v6) )
        JUMPOUT(0x6C15CC);
      a3 = a5;
    }
    v5 = (_DWORD *)*v5;
    if ( v5 == (_DWORD *)(a3 + 16) )
      JUMPOUT(0x6C15DE);
  }
}
