// sub_530E5C 
 
void __fastcall sub_530E5C(unsigned int a1)
{
  unsigned int v1; // r6
  unsigned int v2; // r8
  unsigned __int64 *v3; // r9
  unsigned int v4; // lr
  unsigned int v5; // r1
  unsigned int v6; // r10
  unsigned __int64 v7; // r2

  while ( 1 )
  {
    v5 = v1;
    v6 = a1;
    do
      v7 = __ldrexd(v3);
    while ( v7 == __PAIR64__(a1, v1) && __strexd(__PAIR64__(v2, v4), v3) );
    a1 = HIDWORD(v7);
    v1 = v7;
    if ( v7 == __PAIR64__(v6, v5) )
      JUMPOUT(0x487ADE);
  }
}
