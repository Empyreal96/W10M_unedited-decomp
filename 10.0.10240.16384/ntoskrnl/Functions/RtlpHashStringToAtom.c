// RtlpHashStringToAtom 
 
int __fastcall RtlpHashStringToAtom(int a1, unsigned __int16 *a2, int a3, int **a4, _DWORD *a5, int *a6, int *a7)
{
  unsigned __int16 *v9; // r5
  unsigned int v11; // r7
  _WORD *i; // r4
  unsigned int v13; // r0
  unsigned int v14; // t1
  unsigned int v15; // r8
  unsigned int v16; // r0
  int *v17; // r7
  int j; // r4
  int v19; // r0
  int result; // r0

  v9 = a2;
  if ( ((unsigned int)a2 & 0xFFFF0000) == 0 )
    return sub_7C0274();
  v11 = 0;
  for ( i = a2; *i; v11 += 3 * v13 + (v13 >> 1) )
  {
    v14 = (unsigned __int16)*i++;
    v13 = v14;
    if ( v14 >= 0x61 )
    {
      if ( v13 > 0x7A )
        v13 = RtlUpcaseUnicodeChar(v13);
      else
        v13 = (unsigned __int16)(v13 - 32);
    }
  }
  v15 = i - v9;
  if ( v15 > 0xFF )
  {
    v17 = 0;
    j = 0;
  }
  else
  {
    v16 = *(_DWORD *)(a1 + 20);
    if ( !v16 )
      __brkdiv0();
    v17 = (int *)(a1 + 4 * (v11 % v16 + 6));
    for ( j = *v17; j && (*(unsigned __int8 *)(j + 24) != v15 || wcsicmp(j + 26, v9)); j = *(_DWORD *)j )
      v17 = (int *)j;
  }
  if ( a4 )
    *a4 = v17;
  if ( !j )
  {
    if ( a5 )
      *a5 = 2 * v15;
    goto LABEL_21;
  }
  if ( !a6 )
  {
LABEL_21:
    result = 0;
    *a7 = j;
    return result;
  }
  v19 = RtlpLookupOrCreateLowBox(a1, j, a3);
  if ( v19 )
  {
    *a6 = v19;
    goto LABEL_21;
  }
  return -1073741801;
}
