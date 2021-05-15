// FsRtlpModifyThreadPriorities 
 
_DWORD *__fastcall FsRtlpModifyThreadPriorities(_DWORD *result, int a2, int a3)
{
  _DWORD *v4; // r4
  int v5; // r7
  _DWORD *v6; // r3
  int **i; // r5

  v4 = result;
  if ( a3 )
  {
    v5 = __mrc(15, 0, 13, 0, 3);
    result = (_DWORD *)result[3];
    if ( result )
    {
      v6 = v4 + 18;
    }
    else
    {
      if ( !a2 )
      {
LABEL_8:
        for ( i = (int **)v4[9]; i != v4 + 9; i = (int **)*i )
          result = FsRtlpDoBoost(i[5], v5 & 0xFFFFFFC0, v4 + 4, i + 6);
        return result;
      }
      result = *(_DWORD **)(a2 + 20);
      v6 = (_DWORD *)(a2 + 24);
    }
    if ( result )
      return FsRtlpDoBoost(result, v5 & 0xFFFFFFC0, v4 + 4, v6);
    goto LABEL_8;
  }
  if ( a2 )
  {
    if ( (*(_DWORD *)(a2 + 24) & 0x20) != 0 )
    {
      result = (_DWORD *)PsBoostThreadIoEx(*(_DWORD *)(a2 + 20), 1, 1);
      *(_DWORD *)(a2 + 24) &= 0xFFFFFFDF;
    }
  }
  else if ( (result[18] & 0x20) != 0 )
  {
    result = (_DWORD *)PsBoostThreadIoEx(result[3], 1, 1);
    v4[18] &= 0xFFFFFFDF;
  }
  return result;
}
