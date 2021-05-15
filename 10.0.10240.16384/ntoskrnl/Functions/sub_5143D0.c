// sub_5143D0 
 
void __fastcall sub_5143D0(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r7
  unsigned int v4; // r8
  int v5; // lr
  unsigned int *v6; // lr
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r2
  unsigned int v10; // r0
  int v11; // r4
  int v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // r3
  int v15; // r2
  unsigned int v16; // r0

  if ( v4 < a3 )
    JUMPOUT(0x430F7C);
  v6 = (unsigned int *)(*(_DWORD *)(v5 + 8724) + 4 * (v3 >> 15));
  v7 = (v3 >> 10) & 0x1F;
  LOBYTE(v8) = 1;
  if ( (unsigned int)(v7 + 1) > 0x20 )
  {
    if ( v7 )
    {
      v11 = 32 - v7;
      __dmb(0xBu);
      v12 = ~(((1 << (32 - v7)) - 1) << v7);
      do
        v13 = __ldrex(v6);
      while ( __strex(v13 & v12, v6) );
      __dmb(0xBu);
      v8 = 1 - v11;
      ++v6;
      if ( (unsigned int)(1 - v11) >= 0x20 )
      {
        v14 = v8 >> 5;
        do
        {
          v8 -= 32;
          *v6++ = 0;
          --v14;
        }
        while ( v14 );
      }
      if ( !v8 )
      {
LABEL_16:
        MiFreeLargePageMemory(v3);
        JUMPOUT(0x43100C);
      }
    }
    __dmb(0xBu);
    v15 = ~((1 << v8) - 1);
    do
      v16 = __ldrex(v6);
    while ( __strex(v16 & v15, v6) );
  }
  else
  {
    __dmb(0xBu);
    v9 = ~(1 << v7);
    do
      v10 = __ldrex(v6);
    while ( __strex(v10 & v9, v6) );
  }
  __dmb(0xBu);
  goto LABEL_16;
}
