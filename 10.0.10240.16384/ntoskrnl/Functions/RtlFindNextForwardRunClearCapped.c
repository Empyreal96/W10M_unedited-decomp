// RtlFindNextForwardRunClearCapped 
 
unsigned int __fastcall RtlFindNextForwardRunClearCapped(unsigned int *a1, unsigned int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v4; // r6
  unsigned int i; // lr
  unsigned int result; // r0
  unsigned int v9; // r2
  _DWORD *v10; // r4
  _DWORD *v11; // r1
  int v12; // r6
  unsigned int j; // r1
  _DWORD *v14; // r1

  v4 = *a1;
  i = a2;
  if ( *a1 <= a2 )
    return sub_548BBC();
  v9 = a1[1];
  v10 = (_DWORD *)(v9 + 4 * ((v4 - 1) >> 5));
  v11 = (_DWORD *)(v9 + 4 * (a2 >> 5));
  if ( v11 != v10 && (*v11 | dword_40A280[i & 0x1F]) == -1 )
  {
    ++v11;
    for ( i = i - (i & 0x1F) + 32; v11 < v10; i += 32 )
    {
      if ( *v11 != -1 )
        break;
      ++v11;
    }
  }
  for ( ; i < v4; ++i )
  {
    if ( ((*(int *)(a1[1] + 4 * (i >> 5)) >> (i & 0x1F)) & 1) == 0 )
      break;
  }
  result = 0;
  if ( v11 == v10 )
    goto LABEL_10;
  v12 = i & 0x1F;
  if ( (*v11 & ~dword_40A280[v12]) != 0 )
    goto LABEL_10;
  result = 32 - v12;
  if ( 32 - v12 < a3 )
  {
    v14 = v11 + 1;
    while ( v14 < v10 )
    {
      if ( *v14++ )
        break;
      result += 32;
      if ( result >= a3 )
        goto LABEL_14;
    }
LABEL_10:
    for ( j = result + i; j < *a1; ++result )
    {
      if ( ((*(int *)(a1[1] + 4 * (j >> 5)) >> (j & 0x1F)) & 1) != 0 )
        break;
      if ( result >= a3 )
        break;
      ++j;
    }
  }
LABEL_14:
  *a4 = i;
  if ( result > a3 )
    result = a3;
  return result;
}
