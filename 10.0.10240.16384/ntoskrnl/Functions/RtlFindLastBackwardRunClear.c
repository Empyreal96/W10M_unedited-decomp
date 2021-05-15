// RtlFindLastBackwardRunClear 
 
int __fastcall RtlFindLastBackwardRunClear(unsigned int *a1, unsigned int a2, _DWORD *a3)
{
  _DWORD *v5; // r5
  _DWORD *v6; // r0
  unsigned int v7; // r4
  _DWORD *v8; // r0

  if ( *a1 <= a2 )
    return sub_524D9C();
  v5 = (_DWORD *)a1[1];
  v6 = &v5[a2 >> 5];
  if ( v6 != v5 && (*v6 | ~dword_40A280[(a2 & 0x1F) + 1]) == -1 )
  {
    a2 = a2 - (a2 & 0x1F) - 1;
    for ( --v6; v6 > v5 && *v6 == -1; --v6 )
      a2 -= 32;
  }
  for ( ; a2 != -1; --a2 )
  {
    if ( ((*(int *)(a1[1] + 4 * (a2 >> 5)) >> (a2 & 0x1F)) & 1) == 0 )
      break;
  }
  v7 = a2;
  if ( (dword_40A280[a2 & 0x1F] & *v6) == 0 )
  {
    v7 = a2 - (a2 & 0x1F) - 1;
    v8 = v6 - 1;
    while ( v8 > v5 )
    {
      if ( *v8-- )
        break;
      v7 -= 32;
    }
  }
  for ( ; v7 != -1; --v7 )
  {
    if ( ((*(int *)(a1[1] + 4 * (v7 >> 5)) >> (v7 & 0x1F)) & 1) != 0 )
      break;
  }
  *a3 = v7 + 1;
  return a2 - v7;
}
