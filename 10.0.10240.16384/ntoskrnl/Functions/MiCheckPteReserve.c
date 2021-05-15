// MiCheckPteReserve 
 
unsigned int __fastcall MiCheckPteReserve(int a1, int a2)
{
  int v4; // r8
  unsigned int v5; // r10
  unsigned int i; // r6
  int v7; // r1
  unsigned int *v8; // r7
  unsigned int v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r3
  int v13; // r2
  unsigned int v14; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r5
  int v17; // r2
  int v18; // r2
  unsigned int result; // r0
  int v20; // r4
  int v21; // r2
  unsigned int v22; // r3

  if ( !a2 )
    KeBugCheckEx(218, 512, a1 << 10, 0, 0);
  v4 = 2 * ((a1 - dword_634D60) >> 2);
  v5 = v4 + 2 * a2 - 2;
  for ( i = v4; i < v5; i += 2 )
  {
    v7 = i & 0x1F;
    v8 = (unsigned int *)(dword_634804 + 4 * (i >> 5));
    if ( (((int)*v8 >> (i & 0x1F)) & 1) == 0 )
      KeBugCheckEx(218, 513, a1 << 10, (((i - v4) << 11) & 0xFFFFF000) + (a1 << 10), a2);
    LOBYTE(v9) = 1;
    if ( (unsigned int)(v7 + 1) > 0x20 )
    {
      if ( (i & 0x1F) != 0 )
      {
        __dmb(0xBu);
        do
          v11 = __ldrex(v8);
        while ( __strex(v11 & ~(((1 << (32 - v7)) - 1) << v7), v8) );
        __dmb(0xBu);
        v9 = v7 - 31;
        ++v8;
        if ( (unsigned int)(v7 - 31) >= 0x20 )
        {
          v12 = v9 >> 5;
          do
          {
            v9 -= 32;
            --v12;
            *v8++ = 0;
          }
          while ( v12 );
        }
        if ( !v9 )
          continue;
      }
      __dmb(0xBu);
      v13 = ~((1 << v9) - 1);
      do
        v14 = __ldrex(v8);
      while ( __strex(v14 & v13, v8) );
    }
    else
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(v8);
      while ( __strex(v10 & ~(1 << v7), v8) );
    }
    __dmb(0xBu);
  }
  LOBYTE(v15) = 2;
  v16 = (unsigned int *)(dword_634804 + 4 * (i >> 5));
  v17 = i & 0x1F;
  if ( (unsigned int)(v17 + 2) <= 0x20 )
  {
    __dmb(0xBu);
    v18 = ~(3 << v17);
    do
      result = __ldrex(v16);
    while ( __strex(result & v18, v16) );
LABEL_34:
    __dmb(0xBu);
    return result;
  }
  if ( (i & 0x1F) == 0 )
    goto LABEL_32;
  v20 = 32 - v17;
  __dmb(0xBu);
  v21 = ~(((1 << (32 - v17)) - 1) << v17);
  do
    result = __ldrex(v16);
  while ( __strex(result & v21, v16) );
  __dmb(0xBu);
  v15 = 2 - v20;
  ++v16;
  if ( (unsigned int)(2 - v20) >= 0x20 )
  {
    v22 = v15 >> 5;
    do
    {
      v15 -= 32;
      --v22;
      *v16++ = 0;
    }
    while ( v22 );
  }
  if ( v15 )
  {
LABEL_32:
    __dmb(0xBu);
    do
      result = __ldrex(v16);
    while ( __strex(result & ~((1 << v15) - 1), v16) );
    goto LABEL_34;
  }
  return result;
}
