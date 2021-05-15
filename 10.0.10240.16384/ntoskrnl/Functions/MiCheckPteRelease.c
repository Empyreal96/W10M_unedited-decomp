// MiCheckPteRelease 
 
unsigned int __fastcall MiCheckPteRelease(unsigned int a1, int a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r5
  int v5; // r0
  unsigned int i; // r1
  int v7; // r7
  unsigned int v8; // r8
  unsigned int j; // r1
  unsigned int v10; // r7
  int v11; // r1
  unsigned int *v12; // r6
  unsigned int v13; // r2
  unsigned int v14; // r0
  unsigned int v15; // r0
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r0
  unsigned int *v19; // r6
  unsigned int v20; // r2
  int v21; // r2
  unsigned int result; // r0
  unsigned int v23; // r3

  v3 = a1 << 10;
  if ( !a2 )
    KeBugCheckEx(218, 768, v3, 0, 0);
  if ( v3 < dword_63389C
    || *((_BYTE *)&MiState[2423] + ((int)(((a1 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 9 )
  {
    KeBugCheckEx(218, 769, v3, 0, 0);
  }
  v4 = 2 * ((int)(a1 - dword_634D60) >> 2);
  v5 = dword_634804;
  if ( ((*(int *)(dword_634804 + 4 * (v4 >> 5)) >> (v4 & 0x1F)) & 1) != 0 )
    KeBugCheckEx(218, 771, v3, a2, 0);
  if ( v4 && *(_DWORD *)(dword_634804 + 4 * ((v4 - 2) >> 5)) >> ((v4 - 2) & 0x1F) == 2 )
    KeBugCheckEx(218, 772, v3, a2, 0);
  for ( i = v4 + 1; ((*(_DWORD *)(dword_634804 + 4 * (i >> 5)) >> (i & 0x1F)) & 1) != 0; i += 2 )
    ;
  v7 = ((i - v4) >> 1) + 1;
  if ( v7 != a2 )
    KeBugCheckEx(218, 773, v3, a2, v7);
  v8 = v4 + 2 * v7;
  for ( j = v4; j < v8; j += 2 )
  {
    if ( ((*(_DWORD *)(dword_634804 + 4 * (j >> 5)) >> (j & 0x1F)) & 1) != 0 )
      KeBugCheckEx(218, 774, v3, (((j - v4) << 11) & 0xFFFFF000) + v3, v7);
  }
  v10 = v4 + 2 * a2 - 2;
  while ( 1 )
  {
    v11 = v4 & 0x1F;
    if ( v4 >= v10 )
      break;
    v12 = (unsigned int *)(v5 + 4 * (v4 >> 5));
    LOBYTE(v13) = 1;
    if ( (unsigned int)(v11 + 1) <= 0x20 )
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v12);
      while ( __strex(v14 | (1 << v11), v12) );
LABEL_34:
      __dmb(0xBu);
      goto LABEL_35;
    }
    if ( (v4 & 0x1F) == 0 )
      goto LABEL_32;
    __dmb(0xBu);
    do
      v15 = __ldrex(v12);
    while ( __strex(v15 | (((1 << (32 - v11)) - 1) << v11), v12) );
    __dmb(0xBu);
    v13 = v11 - 31;
    ++v12;
    if ( (unsigned int)(v11 - 31) >= 0x20 )
    {
      v16 = v13 >> 5;
      do
      {
        v13 -= 32;
        --v16;
        *v12++ = -1;
      }
      while ( v16 );
    }
    if ( v13 )
    {
LABEL_32:
      __dmb(0xBu);
      v17 = (1 << v13) - 1;
      do
        v18 = __ldrex(v12);
      while ( __strex(v18 | v17, v12) );
      goto LABEL_34;
    }
LABEL_35:
    v5 = dword_634804;
    v4 += 2;
  }
  v19 = (unsigned int *)(v5 + 4 * (v4 >> 5));
  LOBYTE(v20) = 2;
  if ( (unsigned int)(v11 + 2) <= 0x20 )
  {
    __dmb(0xBu);
    v21 = 3 << v11;
    goto LABEL_46;
  }
  if ( (v4 & 0x1F) == 0 )
    goto LABEL_45;
  __dmb(0xBu);
  do
    result = __ldrex(v19);
  while ( __strex(result | (((1 << (32 - v11)) - 1) << v11), v19) );
  __dmb(0xBu);
  v20 = v11 - 30;
  ++v19;
  if ( (unsigned int)(v11 - 30) >= 0x20 )
  {
    v23 = v20 >> 5;
    do
    {
      v20 -= 32;
      --v23;
      *v19++ = -1;
    }
    while ( v23 );
  }
  if ( v20 )
  {
LABEL_45:
    __dmb(0xBu);
    v21 = (1 << v20) - 1;
    do
LABEL_46:
      result = __ldrex(v19);
    while ( __strex(result | v21, v19) );
    __dmb(0xBu);
  }
  return result;
}
