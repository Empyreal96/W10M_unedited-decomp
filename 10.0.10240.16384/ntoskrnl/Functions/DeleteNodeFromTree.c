// DeleteNodeFromTree 
 
int __fastcall DeleteNodeFromTree(int result, int a2)
{
  int *v2; // r6
  int v3; // r2
  int v4; // r7
  int *i; // r4
  int v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int *v10; // r2
  _BYTE *k; // r5
  int *j; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int **v17; // r3
  int **v18; // r3
  int *v19; // r3

  v2 = (int *)a2;
  v3 = *(_DWORD *)(a2 + 4);
  v4 = result;
  if ( v3 && (i = *(int **)(a2 + 8)) != 0 )
  {
    if ( *(char *)(a2 + 12) < 0 )
    {
      v19 = *(int **)(v3 + 8);
      for ( i = *(int **)(a2 + 4); v19; v19 = (int *)v19[2] )
        i = v19;
    }
    else
    {
      for ( j = (int *)i[1]; j; j = (int *)j[1] )
        i = j;
    }
  }
  else
  {
    i = (int *)a2;
  }
  v6 = i[1];
  v7 = -1;
  if ( v6 )
  {
    result = *i;
    if ( *(int **)(*i + 4) == i )
    {
      *(_DWORD *)(result + 4) = v6;
      *(_DWORD *)i[1] = *i;
      goto LABEL_7;
    }
    *(_DWORD *)(result + 8) = v6;
    v10 = (int *)i[1];
    v7 = 1;
  }
  else
  {
    v8 = *i;
    v9 = i[2];
    if ( *(int **)(*i + 4) == i )
    {
      *(_DWORD *)(v8 + 4) = v9;
    }
    else
    {
      *(_DWORD *)(v8 + 8) = v9;
      v7 = 1;
    }
    v10 = (int *)i[2];
    if ( !v10 )
      goto LABEL_7;
  }
  *v10 = *i;
LABEL_7:
  *(_BYTE *)(v4 + 12) = 0;
  for ( k = (_BYTE *)*i; ; k = *(_BYTE **)k )
  {
    if ( (char)k[12] == v7 )
    {
      k[12] = 0;
      goto LABEL_15;
    }
    if ( !k[12] )
      break;
    result = RebalanceNode(k);
    if ( result )
      goto LABEL_12;
    k = *(_BYTE **)k;
LABEL_15:
    v7 = -1;
    if ( *(_BYTE **)(*(_DWORD *)k + 8) == k )
      v7 = 1;
  }
  k[12] = -(char)v7;
  if ( *(_BYTE *)(v4 + 12) )
    --*(_DWORD *)(v4 + 28);
LABEL_12:
  if ( v2 != i )
  {
    result = *v2;
    v13 = v2[1];
    v14 = v2[2];
    v15 = v2[3];
    *i = *v2;
    i[1] = v13;
    i[2] = v14;
    i[3] = v15;
    v16 = *i;
    if ( *(int **)(*v2 + 4) == v2 )
      *(_DWORD *)(v16 + 4) = i;
    else
      *(_DWORD *)(v16 + 8) = i;
    v17 = (int **)i[1];
    if ( v17 )
      *v17 = i;
    v18 = (int **)i[2];
    if ( v18 )
      *v18 = i;
  }
  return result;
}
