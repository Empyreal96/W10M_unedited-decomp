// sub_53BC54 
 
void sub_53BC54()
{
  int v0; // r7
  unsigned int v1; // r9
  unsigned int v2; // lr
  unsigned int v3; // r1
  unsigned int *v4; // r7
  int v5; // r2
  int v6; // r2
  unsigned int v7; // r0
  int v8; // r4
  int v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r0

  LOBYTE(v3) = 1;
  v4 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(v0 + 6408) + 4) + 4 * (v1 >> 5));
  v5 = v1 & 0x1F;
  if ( (unsigned int)(v5 + 1) > 0x20 )
  {
    if ( (v1 & 0x1F) != 0 )
    {
      v8 = 32 - v5;
      __dmb(0xBu);
      v9 = ((1 << (32 - v5)) - 1) << v5;
      do
        v10 = __ldrex(v4);
      while ( __strex(v10 | v9, v4) );
      __dmb(0xBu);
      v3 = 1 - v8;
      ++v4;
      if ( (unsigned int)(1 - v8) >= 0x20 )
      {
        v11 = v3 >> 5;
        do
        {
          v3 -= 32;
          --v11;
          *v4++ = v2;
        }
        while ( v11 );
      }
      if ( !v3 )
LABEL_15:
        JUMPOUT(0x49DDAE);
    }
    __dmb(0xBu);
    do
      v12 = __ldrex(v4);
    while ( __strex(v12 | ((1 << v3) - 1), v4) );
  }
  else
  {
    __dmb(0xBu);
    v6 = 1 << v5;
    do
      v7 = __ldrex(v4);
    while ( __strex(v7 | v6, v4) );
  }
  __dmb(0xBu);
  goto LABEL_15;
}
