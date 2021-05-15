// sub_5452BC 
 
void __fastcall sub_5452BC(int a1, unsigned __int8 *a2)
{
  int v2; // r5
  int v3; // r10
  int v4; // r3
  unsigned int v5; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v4 = *(_DWORD *)(v2 + 12);
      __dmb(0xBu);
    }
    while ( (v4 & v3) != 0 );
    do
      v5 = __ldrex(a2);
    while ( __strex(v5 | 0x80, a2) );
    __dmb(0xBu);
    if ( !(v5 >> 7) )
      JUMPOUT(0x4BDA1C);
  }
}
