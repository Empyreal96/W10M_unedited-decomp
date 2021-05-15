// RtlInterlockedSetClearRun 
 
int __fastcall RtlInterlockedSetClearRun(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r6
  unsigned int *v5; // r5
  unsigned int v7; // r1
  int v8; // r4
  unsigned int v9; // r0
  int result; // r0
  unsigned int v11; // r8
  int v12; // r10
  unsigned int v13; // r9
  unsigned int v14; // r7
  int v15; // r8
  unsigned int v16; // r9
  unsigned int v17; // r2
  unsigned int v18; // r5
  unsigned int *v19; // r7
  unsigned int v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r0

  v3 = a3;
  v4 = a2 & 0x1F;
  v5 = (unsigned int *)((*(_DWORD *)(a1 + 4) + (a2 >> 3)) & 0xFFFFFFFC);
  if ( v4 + a3 <= 0x20 )
  {
    v7 = *v5;
    if ( a3 == 32 )
      v8 = -1;
    else
      v8 = ((1 << a3) - 1) << v4;
    if ( (v8 & v7) == 0 )
    {
      while ( 1 )
      {
        __dmb(0xBu);
        do
          v9 = __ldrex(v5);
        while ( v9 == v7 && __strex(v8 | v7, v5) );
        __dmb(0xBu);
        if ( v9 == v7 )
          break;
        v7 = v9;
        if ( (v9 & v8) != 0 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  if ( (a2 & 0x1F) != 0 )
  {
    v11 = *v5;
    v12 = ((1 << (32 - v4)) - 1) << v4;
    if ( (v12 & *v5) != 0 )
      return 0;
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v13 = __ldrex(v5);
      while ( v13 == v11 && __strex(v12 | v11, v5) );
      __dmb(0xBu);
      if ( v13 == v11 )
        break;
      v11 = v13;
      if ( (v13 & v12) != 0 )
        return 0;
    }
    v3 = a3 - (32 - v4);
    ++v5;
  }
  if ( v3 >= 0x20 )
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v17 = __ldrex(v5);
      while ( !v17 && __strex(0xFFFFFFFF, v5) );
      __dmb(0xBu);
      if ( v17 )
        break;
      v3 -= 32;
      ++v5;
      if ( v3 < 0x20 )
        goto LABEL_18;
    }
    result = sub_54CD74();
  }
  else
  {
LABEL_18:
    if ( !v3 )
      return 1;
    v14 = *v5;
    v15 = (1 << v3) - 1;
    if ( (v15 & *v5) == 0 )
    {
      do
      {
        __dmb(0xBu);
        do
          v16 = __ldrex(v5);
        while ( v16 == v14 && __strex(v15 | v14, v5) );
        __dmb(0xBu);
        if ( v16 == v14 )
          return 1;
        v14 = v16;
      }
      while ( (v16 & v15) == 0 );
    }
    v18 = a3 - v3;
    v19 = (unsigned int *)(*(_DWORD *)(a1 + 4) + 4 * (a2 >> 5));
    if ( v4 + a3 - v3 <= 0x20 )
      JUMPOUT(0x54CDF4);
    if ( (a2 & 0x1F) != 0 )
    {
      __dmb(0xBu);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 & ~(((1 << (32 - v4)) - 1) << v4), v19) );
      __dmb(0xBu);
      v18 -= 32 - v4;
      ++v19;
    }
    if ( v18 >= 0x20 )
    {
      v21 = v18 >> 5;
      do
      {
        v18 -= 32;
        --v21;
        *v19++ = 0;
      }
      while ( v21 );
    }
    if ( !v18 )
      return 0;
    __dmb(0xBu);
    do
      v22 = __ldrex(v19);
    while ( __strex(v22 & ~((1 << v18) - 1), v19) );
    __dmb(0xBu);
    result = 0;
  }
  return result;
}
