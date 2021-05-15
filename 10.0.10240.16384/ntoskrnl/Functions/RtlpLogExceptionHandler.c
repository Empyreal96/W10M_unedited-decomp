// RtlpLogExceptionHandler 
 
_DWORD *__fastcall RtlpLogExceptionHandler(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // r4
  int v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1
  int v12; // r1

  if ( !RtlpExceptionLog2 )
    return 0;
  v9 = RtlpExceptionLogCount;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&RtlpExceptionLogCount);
  while ( v10 == v9 && __strex((v9 + 1) % 0x32u, (unsigned int *)&RtlpExceptionLogCount) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( v10 == v9 )
      break;
    v9 = v10;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&RtlpExceptionLogCount);
    while ( v11 == v10 && __strex((v10 + 1) % 0x32, (unsigned int *)&RtlpExceptionLogCount) );
    v10 = v11;
  }
  v12 = __mrc(15, 0, 13, 0, 3);
  v8 = (_DWORD *)(RtlpExceptionLog2 + 520 * v9);
  v8[126] = v12 & 0xFFFFFFC0;
  if ( v8 )
  {
    v8[124] = 2;
    v8[125] = -1;
    memmove((int)v8, a1, 0x50u);
    memmove((int)(v8 + 20), a2, 0x1A0u);
    v8[20] &= 0x20000Fu;
    v8[127] = a3;
    v8[128] = a4;
  }
  return v8;
}
