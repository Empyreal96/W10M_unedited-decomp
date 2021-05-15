// CmpAddKeyHashToEntry 
 
_DWORD *__fastcall CmpAddKeyHashToEntry(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  _DWORD *result; // r0

  v3 = *(_DWORD **)(a2 + 8);
  v4 = v3;
  if ( !v3 || a3 )
  {
LABEL_5:
    a1[1] = v3;
    *(_DWORD *)(a2 + 8) = a1;
    result = 0;
  }
  else
  {
    while ( *a1 != *v4 || a1[3] != v4[3] || a1[2] != v4[2] )
    {
      v4 = (_DWORD *)v4[1];
      if ( !v4 )
        goto LABEL_5;
    }
    result = v4 - 3;
  }
  return result;
}
