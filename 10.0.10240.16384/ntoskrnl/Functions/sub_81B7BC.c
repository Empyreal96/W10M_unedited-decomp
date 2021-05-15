// sub_81B7BC 
 
void __fastcall sub_81B7BC(_BYTE *a1, unsigned int a2, _WORD *a3)
{
  unsigned int v3; // r4
  _WORD *v4; // r5
  int v5; // r3
  int v6; // t1

  v3 = 0;
  if ( a2 )
  {
    v4 = a3;
    do
    {
      if ( *a1 == 42 || (v6 = *(_DWORD *)a1, a1 += 4, v5 = v6, v6 == 1061109567) )
        JUMPOUT(0x7BAA76);
      ++v3;
      *((_DWORD *)v4 + 1) = v5;
      v4 += 2;
    }
    while ( v3 < a2 );
  }
  *a3 = a2;
  JUMPOUT(0x7BAA7E);
}
