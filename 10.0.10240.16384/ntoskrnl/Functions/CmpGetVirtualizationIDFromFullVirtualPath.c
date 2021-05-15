// CmpGetVirtualizationIDFromFullVirtualPath 
 
int __fastcall CmpGetVirtualizationIDFromFullVirtualPath(_DWORD *a1, unsigned __int16 *a2)
{
  int v2; // r4
  int v3; // r3
  int v4; // r0
  _WORD *v5; // r2
  int result; // r0
  int v7; // r5
  __int16 v8; // r2
  unsigned int v9; // r4
  int v10; // r3
  int v11; // r2

  LOWORD(v2) = 0;
  *(_DWORD *)a2 = *a1;
  v3 = a1[1];
  v4 = 3;
  *((_DWORD *)a2 + 1) = v3;
  while ( 1 )
  {
    v5 = (_WORD *)*((_DWORD *)a2 + 1);
    if ( *v5 == 92 && !--v4 )
      break;
    *((_DWORD *)a2 + 1) = v5 + 1;
    v2 = (unsigned __int16)(v2 + 1);
    if ( 2 * v2 >= (unsigned int)*a2 )
      return -1073741811;
  }
  result = -1073741811;
  v7 = 0;
  *((_DWORD *)a2 + 1) += 2;
  v8 = *a2 - 2 * v2;
  v9 = (unsigned __int16)(v8 - 2);
  v10 = 0;
  a2[1] = 0;
  *a2 = 0;
  if ( v8 != 2 )
  {
    v11 = *((_DWORD *)a2 + 1);
    while ( *(_WORD *)(v11 + v10) != 92 )
    {
      ++v7;
      *a2 += 2;
      v10 = 2 * v7;
      if ( 2 * v7 >= v9 )
        return result;
    }
    result = 0;
  }
  return result;
}
