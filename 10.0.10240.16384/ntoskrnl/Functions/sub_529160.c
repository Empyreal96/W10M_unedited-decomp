// sub_529160 
 
void __fastcall sub_529160(unsigned int *a1, unsigned int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r4
  unsigned int v4; // r2

  while ( 1 )
  {
    v3 = v2;
    *(_DWORD *)(a2 + 16) = v2;
    __dmb(0xBu);
    do
      v4 = __ldrex(a1);
    while ( v4 == v2 && __strex(a2, a1) );
    v2 = v4;
    __dmb(0xBu);
    if ( v4 == v3 )
      JUMPOUT(0x464AD6);
  }
}
