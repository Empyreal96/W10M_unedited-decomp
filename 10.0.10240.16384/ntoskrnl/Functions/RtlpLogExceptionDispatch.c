// RtlpLogExceptionDispatch 
 
int __fastcall RtlpLogExceptionDispatch(int result, int a2)
{
  int v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r1
  int v6; // r1
  _DWORD *v7; // r4

  if ( RtlpExceptionLog2 )
  {
    v3 = RtlpExceptionLogCount;
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&RtlpExceptionLogCount);
    while ( v4 == v3 && __strex((v3 + 1) % 0x32u, (unsigned int *)&RtlpExceptionLogCount) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( v4 == v3 )
        break;
      v3 = v4;
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&RtlpExceptionLogCount);
      while ( v5 == v4 && __strex((v4 + 1) % 0x32, (unsigned int *)&RtlpExceptionLogCount) );
      v4 = v5;
    }
    v6 = __mrc(15, 0, 13, 0, 3);
    v7 = (_DWORD *)(RtlpExceptionLog2 + 520 * v3);
    v7[126] = v6 & 0xFFFFFFC0;
    if ( v7 )
    {
      v7[124] = 1;
      memmove((int)v7, result, 0x50u);
      result = memmove((int)(v7 + 20), a2, 0x1A0u);
      v7[20] &= 0x20000Fu;
    }
  }
  return result;
}
