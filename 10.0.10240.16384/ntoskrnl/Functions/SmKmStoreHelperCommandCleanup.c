// SmKmStoreHelperCommandCleanup 
 
_BYTE *__fastcall SmKmStoreHelperCommandCleanup(_BYTE *result, int a2, _DWORD *a3)
{
  int v5; // r6
  int v6[10]; // [sp+0h] [bp-28h] BYREF

  v5 = (int)result;
  if ( (int)a3[5] >= 0 )
  {
    result = memset(v6, 0, 24);
    if ( a2 == 2 )
    {
      v6[0] = a3[4];
      v6[1] = a3[1];
      result = (_BYTE *)SmKmStoreHelperCommandProcess(v5, 3, v6);
    }
    else if ( a2 != 3 && a2 == 4 )
    {
      SmKmUnlockMdl(a3[4], *(_DWORD *)(v5 + 68), v5);
      result = (_BYTE *)SmFpFree(*(_DWORD *)(v5 + 68), 2, v5, a3[4]);
    }
  }
  return result;
}
