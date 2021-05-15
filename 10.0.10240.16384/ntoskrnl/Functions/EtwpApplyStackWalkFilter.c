// EtwpApplyStackWalkFilter 
 
BOOL __fastcall EtwpApplyStackWalkFilter(int a1, int a2, int a3, int a4)
{
  BOOL v4; // r4
  int v8; // r8
  __int64 v9; // r0
  __int64 v10; // r0

  v4 = 1;
  if ( a4 )
  {
    v8 = KfRaiseIrql(2);
    if ( *(_DWORD *)(*(_DWORD *)(a2 + 344) + 36 * a3 + 20) )
    {
      v9 = EtwpPerfectHashFunctionSearch(a1);
      if ( (unsigned __int8)*(_BYTE *)HIDWORD(v9) != (_DWORD)v9 )
        v4 = 0;
    }
    KfLowerIrql(v8);
  }
  else if ( *(_DWORD *)(*(_DWORD *)(a2 + 344) + 36 * a3 + 20) )
  {
    v10 = EtwpPerfectHashFunctionSearch(a1);
    v4 = (unsigned __int8)*(_BYTE *)HIDWORD(v10) == (_DWORD)v10;
  }
  return v4;
}
