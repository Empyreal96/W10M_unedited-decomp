// sub_53D9B0 
 
void sub_53D9B0()
{
  int v0; // r4
  int v1; // r8
  unsigned __int8 *v2; // r1
  int v3; // r3
  unsigned int v4; // r2

  v2 = (unsigned __int8 *)(v0 + 15);
  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *(_DWORD *)(v0 + 12);
      __dmb(0xBu);
    }
    while ( (v3 & v1) != 0 );
    do
      v4 = __ldrex(v2);
    while ( __strex(v4 | 0x80, v2) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      JUMPOUT(0x4A41AC);
  }
}
