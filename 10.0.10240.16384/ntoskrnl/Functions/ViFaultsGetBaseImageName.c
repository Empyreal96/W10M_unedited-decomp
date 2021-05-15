// ViFaultsGetBaseImageName 
 
_DWORD *__fastcall ViFaultsGetBaseImageName(_DWORD *result, int a2)
{
  unsigned int v2; // r4
  _WORD *i; // r2
  _WORD *v4; // r2
  __int16 v5; // r3

  v2 = *(unsigned __int16 *)result;
  if ( *(_WORD *)result )
  {
    result = (_DWORD *)result[1];
    for ( i = (_WORD *)result + (v2 >> 1) - 1; i >= (_WORD *)result && *i != 92; --i )
      ;
    v4 = i + 1;
    v5 = v2 - (_WORD)v4 + (_WORD)result;
    *(_WORD *)a2 = v5;
    *(_WORD *)(a2 + 2) = v5;
    *(_DWORD *)(a2 + 4) = v4;
  }
  else
  {
    *(_DWORD *)a2 = *result;
    *(_DWORD *)(a2 + 4) = result[1];
  }
  return result;
}
