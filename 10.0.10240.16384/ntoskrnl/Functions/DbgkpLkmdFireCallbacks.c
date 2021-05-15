// DbgkpLkmdFireCallbacks 
 
_DWORD *__fastcall DbgkpLkmdFireCallbacks(int a1, int a2, int a3)
{
  int v4; // r8
  int v7; // r4
  BOOL v8; // r3
  _DWORD *v9; // r5
  int v10; // r6
  _DWORD *result; // r0
  unsigned int v12; // r7
  int v13; // r3
  int (__fastcall *v14)(int (__fastcall *)(int), int (*)(), int, int); // r4
  int v15; // r0

  v4 = 1;
  if ( (a2 & 1) != 0 )
  {
    v7 = PsGetProcessSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v8 = v7 == PsGetProcessSessionIdEx(a3) && v7 != -1;
    v4 = v8;
  }
  v9 = &unk_641668;
  v10 = 8;
  do
  {
    result = (_DWORD *)ExReferenceCallBackBlock(v9);
    v12 = (unsigned int)result;
    if ( result )
    {
      v13 = v9[1];
      if ( (v13 & a2) != 0 && ((v13 & 4) == 0 || v4) )
      {
        v14 = (int (__fastcall *)(int (__fastcall *)(int), int (*)(), int, int))KeReadStateSemaphore((int)result);
        (*(void (__fastcall **)(int))(a1 + 172))(a1 + 128);
        v15 = ExGetCallBackBlockContext(v12);
        if ( v14(DbgkpLkmdSnapData, DbgkpLkmdIsMemoryBlockPresentFromCallback, a1, v15) < 0 )
          (*(void (__fastcall **)(int))(a1 + 176))(a1 + 128);
      }
      result = ExDereferenceCallBackBlock(v9, v12);
    }
    v9 += 2;
    --v10;
  }
  while ( v10 );
  return result;
}
