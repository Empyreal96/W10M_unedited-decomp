// sub_538274 
 
void __fastcall sub_538274(int a1)
{
  int v1; // r9
  unsigned __int8 *v2; // r1
  int v3; // r3
  unsigned int v4; // r2

  v2 = (unsigned __int8 *)(a1 + 15);
  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *(_DWORD *)(a1 + 12);
      __dmb(0xBu);
    }
    while ( (v3 & v1) != 0 );
    do
      v4 = __ldrex(v2);
    while ( __strex(v4 | 0x80, v2) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      JUMPOUT(0x496212);
  }
}
