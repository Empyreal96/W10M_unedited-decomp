// KiSelectReadyThreadEx 
 
int __fastcall KiSelectReadyThreadEx(_DWORD *a1, int a2, int a3)
{
  int v5; // r2
  int v6; // r0
  int v7; // r2
  int v8; // r5
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int result; // r0

  if ( !a2 )
  {
    result = KiSelectReadyThread(1, a1);
    if ( result )
      return result;
    result = KiSelectLowestRankedThread((int)a1);
    if ( a3 || result )
      return result;
    v11 = 0;
    return KiSelectReadyThread(v11, a1);
  }
  if ( *(_BYTE *)(a2 + 123) == 31 )
    return 0;
  v5 = *(_DWORD *)(a2 + 68);
  if ( !v5
    || (v6 = a1[588] + v5) == 0
    || (a1 == (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408) || a2 != a1[1] ? (v7 = 1) : (v7 = 0),
        (v8 = *(char *)(a2 + 123), v8 >= 16)
     || (*(_DWORD *)(a2 + 80) & 0x100) != 0
     || v7 && (*(_DWORD *)(a2 + 308) || *(_BYTE *)(a2 + 134) == 1)) )
  {
LABEL_17:
    v11 = *(char *)(a2 + 123) + 1;
    return KiSelectReadyThread(v11, a1);
  }
  v9 = v6;
  while ( 1 )
  {
    v10 = *(unsigned __int8 *)(v9 + 92);
    if ( (v10 & 2) != 0 )
      return KiChooseLowestRankedThread(a1, a2, v8 + 1, v10);
    v9 = *(_DWORD *)(v9 + 236);
    if ( !v9 )
    {
      while ( 1 )
      {
        v10 = *(_DWORD *)(v6 + 96);
        if ( v10 )
          return KiChooseLowestRankedThread(a1, a2, v8 + 1, v10);
        v6 = *(_DWORD *)(v6 + 236);
        if ( !v6 )
          goto LABEL_17;
      }
    }
  }
}
