// EtwpApplyExeFilter 
 
int __fastcall EtwpApplyExeFilter(int a1, _WORD *a2)
{
  unsigned __int16 *v3; // r2
  unsigned int v4; // r3
  unsigned __int16 *v5; // r2
  unsigned __int16 *v6; // r4
  int v7; // r7
  unsigned int v8; // r5
  _WORD *v9; // r2

  v3 = *(unsigned __int16 **)(*(_DWORD *)(a1 + 40) + 380);
  v4 = *v3;
  v5 = (unsigned __int16 *)*((_DWORD *)v3 + 1);
  v6 = &v5[v4 >> 1];
  while ( v6 != v5 )
  {
    if ( *--v6 == 92 )
    {
      ++v6;
      break;
    }
  }
  v7 = (v4 >> 1) - (v6 - v5);
  v8 = 0;
  if ( !*a2 )
    return 0;
  while ( 1 )
  {
    v9 = &a2[4 * v8];
    if ( (unsigned __int16)v9[2] == v7 && !wcsnicmp(*((_DWORD *)v9 + 2), v6, v7) )
      break;
    v8 = (unsigned __int16)(v8 + 1);
    if ( v8 >= (unsigned __int16)*a2 )
      return 0;
  }
  return 1;
}
