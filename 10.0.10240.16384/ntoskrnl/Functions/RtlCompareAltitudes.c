// RtlCompareAltitudes 
 
int __fastcall RtlCompareAltitudes(unsigned __int16 *a1, unsigned __int16 *a2)
{
  _WORD *v2; // r10
  _WORD *v3; // r9
  unsigned int v4; // r7
  unsigned int v5; // r2
  unsigned int i; // lr
  unsigned int v7; // r1
  unsigned int j; // r5
  unsigned int v9; // r6
  unsigned int v11; // r2
  bool v12; // cc
  unsigned int k; // r2
  unsigned int v14; // r3
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r4
  unsigned __int16 l; // r3
  unsigned __int16 m; // r3
  _WORD *v20; // r5
  int v21; // r1
  _WORD *v22; // r6
  int v23; // r3

  v2 = (_WORD *)*((_DWORD *)a1 + 1);
  v3 = (_WORD *)*((_DWORD *)a2 + 1);
  v4 = *a1 >> 1;
  v5 = 0;
  for ( i = *a2 >> 1; v5 < v4; v5 = (unsigned __int16)(v5 + 1) )
  {
    if ( v2[v5] == 46 )
      break;
  }
  v7 = 0;
  for ( j = v5; v7 < i; v7 = (unsigned __int16)(v7 + 1) )
  {
    if ( v3[v7] == 46 )
      break;
  }
  v9 = v7;
  if ( v5 && *v2 == 48 )
    return sub_551C8C(0);
  LOWORD(v11) = 0;
  if ( v7 )
  {
    do
    {
      if ( *v3 != 48 )
        break;
      v11 = (unsigned __int16)(v11 + 1);
      v9 = (unsigned __int16)(v9 - 1);
      i = (unsigned __int16)(i - 1);
      ++v3;
    }
    while ( v11 < v7 );
  }
  v12 = j > v9;
  if ( j != v9 )
  {
LABEL_13:
    if ( !v12 )
      return -1;
    return 1;
  }
  for ( k = 0; k < j; k = (unsigned __int16)(k + 1) )
  {
    v14 = (unsigned __int16)v3[k];
    v15 = (unsigned __int16)v2[k];
    v12 = v15 > v14;
    if ( v15 != v14 )
      goto LABEL_13;
  }
  v16 = (__int16)(v4 - j - 1);
  if ( v16 < 0 )
    v16 = 0;
  v17 = (__int16)(i - v9 - 1);
  if ( v17 < 0 )
    v17 = 0;
  if ( v4 )
  {
    for ( l = v4 - 1; l > j && v2[l] == 48; --l )
      v16 = (__int16)(v16 - 1);
  }
  if ( i )
  {
    for ( m = i - 1; m > v9 && v3[m] == 48; --m )
      v17 = (__int16)(v17 - 1);
  }
  v20 = &v2[j + 1];
  v21 = 0;
  v22 = &v3[v9 + 1];
  if ( v16 > 0 )
  {
    v23 = 0;
    while ( v23 < v17 )
    {
      if ( v20[v23] != v22[v23] )
      {
        v12 = (unsigned __int16)v20[v21] > (unsigned int)(unsigned __int16)v22[v21];
        goto LABEL_13;
      }
      v21 = (unsigned __int16)(v21 + 1);
      v23 = v21;
      if ( v21 >= v16 )
        break;
    }
  }
  if ( v16 != v17 )
  {
    if ( v16 <= v17 )
      return -1;
    return 1;
  }
  return 0;
}
