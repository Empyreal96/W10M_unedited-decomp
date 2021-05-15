// sub_50A21C 
 
void sub_50A21C()
{
  int v0; // r6
  unsigned __int8 *v1; // r3
  unsigned int v2; // r2
  int v3; // r3
  unsigned int *v4; // r2
  unsigned int v5; // r5
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r2
  unsigned int v9; // r1

  v1 = (unsigned __int8 *)(v0 + 82);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0xFB, v1) );
  v3 = *(_DWORD *)(v0 + 116);
  __dmb(0xBu);
  v4 = (unsigned int *)(v3 + 116);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + 8, v4) );
  __dmb(0xBu);
  if ( (v5 & 7) != 0 )
  {
    v6 = *(_DWORD *)(v0 + 116);
    do
      v7 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v7 | 0x80, (unsigned __int8 *)v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v6 & 0x80) != 0 );
        do
          v8 = __ldrex((unsigned __int8 *)v6);
        while ( __strex(v8 | 0x80, (unsigned __int8 *)v6) );
        __dmb(0xBu);
      }
      while ( v8 >> 7 );
    }
    if ( (*(_DWORD *)(v6 + 116) & 7) != 0 )
    {
      KiRequestProcessInSwap(v0, (unsigned int *)v6);
      JUMPOUT(0x435348);
    }
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)v6);
    while ( __strex(v9 & 0xFFFFFF7F, (unsigned int *)v6) );
  }
  JUMPOUT(0x435340);
}
