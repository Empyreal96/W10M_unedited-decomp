// sub_509C28 
 
void sub_509C28()
{
  int v0; // r5
  int v1; // r8
  unsigned __int8 *v2; // r6
  unsigned int v3; // r4
  int v4; // r3
  unsigned int v5; // r2

  v2 = (unsigned __int8 *)(v0 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  if ( v3 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v4 = *(_DWORD *)(v0 + 12);
        __dmb(0xBu);
      }
      while ( (v4 & v1) != 0 );
      do
        v5 = __ldrex(v2);
      while ( __strex(v5 | 0x80, v2) );
      __dmb(0xBu);
    }
    while ( v5 >> 7 );
  }
  JUMPOUT(0x427E9A);
}
