// EtwpFindAndLockBufferForFlushing 
 
_DWORD *__fastcall EtwpFindAndLockBufferForFlushing(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned __int64 v4; // r4
  int v5; // r6
  _DWORD *result; // r0
  __int64 v7; // r2
  int v8; // r3
  unsigned int *v9; // r1
  unsigned int v10; // r2
  __int64 v11; // r2
  unsigned int v12; // r2

  v4 = __PAIR64__(a3, a4);
  __dmb(0xBu);
  v5 = a1 + 72;
  if ( *(_DWORD *)(a1 + 72) == a1 + 72 )
    goto LABEL_7;
  result = (_DWORD *)(*(_DWORD *)(a1 + 72) - 56);
  while ( result )
  {
    LODWORD(v7) = result[7];
    HIDWORD(v7) = result[6];
    if ( v7 == v4 )
    {
      __dmb(0xBu);
      v9 = result + 11;
      do
        v10 = __ldrex(v9);
      while ( !v10 && __strex(3u, v9) );
      __dmb(0xBu);
      if ( !v10 )
      {
        LODWORD(v11) = result[7];
        HIDWORD(v11) = result[6];
        if ( v11 == v4 )
          return result;
        __dmb(0xBu);
        do
          v12 = __ldrex(v9);
        while ( __strex(0, v9) );
        __dmb(0xBu);
      }
      return 0;
    }
    v8 = result[14];
    if ( v8 == v5 )
LABEL_7:
      result = 0;
    else
      result = (_DWORD *)(v8 - 56);
  }
  return result;
}
