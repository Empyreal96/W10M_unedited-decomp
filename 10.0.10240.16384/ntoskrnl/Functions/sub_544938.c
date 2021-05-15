// sub_544938 
 
void __fastcall sub_544938(unsigned __int8 *a1)
{
  int v1; // r4
  int v2; // r3
  unsigned int v3; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v2 = *(_DWORD *)(v1 + 12);
      __dmb(0xBu);
    }
    while ( (v2 & 0x80000000) != 0 );
    do
      v3 = __ldrex(a1);
    while ( __strex(v3 | 0x80, a1) );
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      JUMPOUT(0x4BB9AC);
  }
}
