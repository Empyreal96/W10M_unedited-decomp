// ExpFindCurrentThread 
 
_DWORD *__fastcall ExpFindCurrentThread(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r0
  _DWORD *result; // r0
  _DWORD *v9; // r4
  int v10; // r0
  _DWORD *v11; // r2

  v6 = *(_DWORD *)(a1 + 24);
  if ( v6 == a2 )
    return (_DWORD *)(a1 + 24);
  if ( v6 || a5 )
    v9 = 0;
  else
    v9 = (_DWORD *)(a1 + 24);
  v10 = *(_DWORD *)(a1 + 8);
  if ( !v10 )
  {
LABEL_12:
    if ( a4 )
    {
      if ( v9 )
      {
        result = v9;
        *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = ((int)v9 - *(_DWORD *)(a1 + 8)) >> 3;
        return result;
      }
      ExpExpandResourceOwnerTable(a1, a3);
    }
    return 0;
  }
  v11 = (_DWORD *)(v10 + 8 * *(_DWORD *)(v10 + 4));
  result = (_DWORD *)(v10 + 8);
  while ( *result != a2 )
  {
    if ( !v9 && !*result )
      v9 = result;
    result += 2;
    if ( result == v11 )
      goto LABEL_12;
  }
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = ((int)result - *(_DWORD *)(a1 + 8)) >> 3;
  return result;
}
