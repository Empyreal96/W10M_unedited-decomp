// KiInSwapProcesses 
 
int __fastcall KiInSwapProcesses(_DWORD *a1)
{
  _DWORD *v2; // r4
  unsigned int *v3; // r9
  unsigned int v4; // r1
  int v5; // r7
  unsigned int v6; // r2
  _DWORD *v7; // r0
  _DWORD *v8; // r2
  int result; // r0
  __int64 v10; // kr00_8
  unsigned int v11; // r1
  unsigned int v12; // r1

  while ( 1 )
  {
    v2 = a1 - 21;
    a1 = (_DWORD *)*a1;
    __dmb(0xBu);
    v3 = v2 + 29;
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 ^ 6, v3) );
    __dmb(0xBu);
    MmInSwapProcess(v2);
    v5 = KfRaiseIrql(2);
    do
      v6 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v6 | 0x80, (unsigned __int8 *)v2) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v6 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*v2 & 0x80) != 0 );
      do
        v6 = __ldrex((unsigned __int8 *)v2);
      while ( __strex(v6 | 0x80, (unsigned __int8 *)v2) );
    }
    v7 = (_DWORD *)v2[19];
    v8 = v2 + 19;
    if ( v7 == v2 + 19 )
      break;
    v10 = *(_QWORD *)v8;
    if ( *(_DWORD **)(*v8 + 4) != v8 || *(_DWORD **)HIDWORD(v10) != v8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v10) = v10;
    *(_DWORD *)(v10 + 4) = HIDWORD(v10);
    *v8 = v8;
    v2[20] = v2 + 19;
    __dmb(0xBu);
    do
      v11 = __ldrex(v3);
    while ( __strex(v11 ^ 4, v3) );
    __dmb(0xBu);
    do
      v12 = __ldrex(v2);
    while ( __strex(v12 & 0xFFFFFF7F, v2) );
    if ( v7 )
      result = KiReadyOutSwappedThreads(v7, v5);
    else
      result = KfLowerIrql(v5);
    if ( !a1 )
      return result;
  }
  return sub_516054();
}
