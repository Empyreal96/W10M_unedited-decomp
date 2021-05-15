// sub_532654 
 
void __fastcall sub_532654(int a1)
{
  int v1; // r6
  unsigned __int8 *v2; // r1
  int v3; // r3
  unsigned int v4; // r2

  v2 = (unsigned __int8 *)(v1 + 15);
  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *(_DWORD *)(v1 + 12);
      __dmb(0xBu);
    }
    while ( (v3 & a1) != 0 );
    do
      v4 = __ldrex(v2);
    while ( __strex(v4 | 0x80, v2) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      JUMPOUT(0x48B324);
  }
}
