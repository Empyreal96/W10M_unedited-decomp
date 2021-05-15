// AslPathClean 
 
int __fastcall AslPathClean(unsigned __int16 *a1, int a2, unsigned int a3)
{
  unsigned int v6; // r8
  char *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r2
  unsigned int i; // r1
  unsigned __int16 *v12; // r5
  int v13; // r3
  _WORD *v14; // r0
  int v15; // r3
  int v16; // t1
  unsigned int v17; // r0
  unsigned int v18; // r0
  int v19; // r3
  int v20; // r3
  unsigned __int16 *v21; // r1
  int v22; // t1
  unsigned __int16 *v23; // r1
  int v24; // t1

  v6 = wcslen(a1);
  if ( a3 < v6 + 1 )
    return -1073741789;
  v8 = (char *)wcschr(a1, 58);
  if ( v8 )
    goto LABEL_9;
  if ( !wcsncmp(a1, L"\\??\\", 4) )
  {
    v9 = 4;
    goto LABEL_11;
  }
  if ( !wcsncmp(a1, L"\\\\", 2) )
  {
    v9 = 2;
    goto LABEL_11;
  }
  v8 = (char *)wcschr(a1, 92);
  if ( v8 )
LABEL_9:
    v9 = ((unsigned int)(v8 - (char *)a1) >> 1) + 1;
  else
    v9 = 1;
LABEL_11:
  memmove(a2, (int)a1, 2 * v9);
  v10 = v9;
  for ( i = v9; i < v6; ++i )
  {
    v12 = &a1[i];
    v13 = *v12;
    if ( v13 == 92 || v13 == 47 )
    {
      if ( !v10 || *(_WORD *)(a2 + 2 * v10 - 2) != 92 )
        *(_WORD *)(a2 + 2 * v10++) = 92;
      continue;
    }
    if ( v13 != 46 )
    {
      if ( i < v6 )
      {
        v14 = (_WORD *)(a2 + 2 * v10);
        do
        {
          v16 = *v12++;
          v15 = v16;
          if ( v16 == 92 )
            break;
          if ( v15 == 47 )
            break;
          ++i;
          ++v10;
          *v14++ = v15;
        }
        while ( i < v6 );
        if ( i < v6 && v10 >= 2 )
        {
          v17 = a2 + 2 * v10;
          if ( *(_WORD *)(v17 - 2) == 46 && *(_WORD *)(v17 - 4) != 46 )
            --v10;
        }
      }
      --i;
      continue;
    }
    v18 = i + 1;
    if ( i + 1 == v6 )
      break;
    v19 = v12[1];
    if ( v19 != 92 && v19 != 47 )
    {
      if ( v19 != 46 )
        continue;
      if ( i + 2 != v6 )
      {
        v20 = v12[2];
        if ( v20 != 92 && v20 != 47 )
          continue;
      }
      if ( v10 < v9 )
        goto LABEL_42;
      v21 = (unsigned __int16 *)(a2 + 2 * v10);
      do
      {
        v22 = *v21--;
        v21[1] = 0;
        if ( v22 == 92 )
          break;
        --v10;
      }
      while ( v10 >= v9 );
      if ( v10 < v9 )
        goto LABEL_42;
      v23 = (unsigned __int16 *)(a2 + 2 * v10);
      do
      {
        v24 = *v23--;
        v23[1] = 0;
        if ( v24 == 92 )
          break;
        --v10;
      }
      while ( v10 >= v9 );
      if ( v10 < v9 )
LABEL_42:
        ++v10;
    }
    i = v18;
  }
  *(_WORD *)(a2 + 2 * v10) = 0;
  return 0;
}
