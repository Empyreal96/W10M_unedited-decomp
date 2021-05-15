// KiSetProcessorIdle 
 
int __fastcall KiSetProcessorIdle(int a1, int a2, char a3)
{
  int v4; // r3
  int v5; // r5
  int v6; // r3
  int v7; // r2
  int v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r2
  int v11; // r2
  int v12; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r2
  int v15; // r4
  unsigned int *v16; // r2
  int result; // r0
  int v18; // r3
  int v19; // r2
  unsigned __int8 *v20; // r3
  unsigned int v21; // r2
  int v22; // r4
  unsigned int *v23; // r2
  int v24; // r2
  int v25; // r0
  unsigned __int8 *v26; // r3
  unsigned int v27; // r2

  v4 = *(unsigned __int8 *)(a1 + 19);
  v5 = *(_DWORD *)(a1 + 2360);
  if ( !a2 )
  {
    *(_BYTE *)(a1 + 1755) = 0;
    if ( (v4 & 1) != 0 )
      __fastfail(0x21u);
    v6 = v4 + 1;
    *(_BYTE *)(a1 + 19) = v6;
    if ( v6 == 1 )
    {
      v7 = *(unsigned __int8 *)(a1 + 1053);
      __dmb(0xBu);
      v8 = 1 << (v7 & 7);
      v9 = (unsigned __int8 *)(v5 + (v7 >> 3));
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & ~(_BYTE)v8, v9) );
      __dmb(0xBu);
    }
    v11 = *(unsigned __int8 *)(a1 + 1053);
    __dmb(0xBu);
    v12 = 1 << (v11 & 7);
    v13 = (unsigned __int8 *)(v5 + (v11 >> 3) + 8);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 & ~(_BYTE)v12, v13) );
    __dmb(0xBu);
    v15 = ~*(_DWORD *)(a1 + 3468);
    __dmb(0xBu);
    v16 = (unsigned int *)(v5 + 4);
    do
      result = __ldrex(v16);
    while ( __strex(result & v15, v16) );
    goto LABEL_11;
  }
  *(_BYTE *)(a1 + 1755) = a3;
  if ( (v4 & 1) == 0 )
    sub_50A87C();
  v18 = v4 - 1;
  *(_BYTE *)(a1 + 19) = v18;
  if ( !v18 )
  {
    v24 = *(unsigned __int8 *)(a1 + 1053);
    __dmb(0xBu);
    v25 = 1 << (v24 & 7);
    v26 = (unsigned __int8 *)(v5 + (v24 >> 3));
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 | v25, v26) );
    __dmb(0xBu);
  }
  v19 = *(unsigned __int8 *)(a1 + 1053);
  __dmb(0xBu);
  result = 1 << (v19 & 7);
  v20 = (unsigned __int8 *)(v5 + (v19 >> 3) + 8);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 | result, v20) );
  __dmb(0xBu);
  v22 = *(_DWORD *)(a1 + 3468);
  if ( (*(_DWORD *)(v5 + 8) & v22) == v22 )
  {
    __dmb(0xBu);
    v23 = (unsigned int *)(v5 + 4);
    do
      result = __ldrex(v23);
    while ( __strex(result | v22, v23) );
LABEL_11:
    __dmb(0xBu);
  }
  return result;
}
