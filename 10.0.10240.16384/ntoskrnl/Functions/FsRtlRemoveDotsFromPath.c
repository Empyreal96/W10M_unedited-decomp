// FsRtlRemoveDotsFromPath 
 
int __fastcall FsRtlRemoveDotsFromPath(_WORD *a1, unsigned int a2, _WORD *a3)
{
  unsigned int v3; // r7
  int v4; // r4
  bool v6; // cc
  unsigned int v8; // r2
  _WORD *v9; // r1
  _WORD *v10; // r1
  __int16 v11; // r3
  int v12; // r3
  __int16 i; // r3

  v3 = a2 >> 1;
  v4 = 0;
  if ( a2 >> 1 == 3 )
  {
    if ( *a1 != 92 || a1[1] != 46 )
    {
LABEL_11:
      if ( *a1 != 46 || a1[1] != 46 || a1[2] != 92 )
        goto LABEL_15;
      return -1073741192;
    }
    if ( a1[2] == 46 )
      return -1073741192;
  }
  v6 = v3 > 2;
  if ( v3 != 2 )
  {
LABEL_9:
    if ( !v6 )
      goto LABEL_15;
    goto LABEL_11;
  }
  if ( *a1 == 46 )
  {
    if ( a1[1] == 46 )
      return -1073741192;
    v6 = 0;
    goto LABEL_9;
  }
LABEL_15:
  v8 = 0;
  if ( v3 )
  {
    while ( v8 )
    {
      if ( (int)v8 < (int)(v3 - 1) )
      {
        v9 = &a1[v8];
        if ( *v9 == 92 && v9[1] == 92 )
          goto LABEL_44;
      }
      v10 = &a1[v8];
      if ( *v10 != 46 )
        break;
      if ( v8 == v3 - 1 )
      {
        if ( *(v10 - 1) != 92 )
          goto LABEL_23;
        if ( v4 > 1 )
        {
          v11 = v4 - 1;
LABEL_43:
          v4 = v11;
          goto LABEL_44;
        }
      }
      else
      {
        v12 = (unsigned __int16)v10[1];
        if ( v12 == 92 )
        {
          if ( *(v10 - 1) != 92 )
            goto LABEL_23;
        }
        else
        {
          if ( v12 != 46 || *(v10 - 1) != 92 || v8 != v3 - 2 && v10[2] != 92 )
          {
LABEL_23:
            a1[v4] = 46;
LABEL_42:
            v11 = v4 + 1;
            goto LABEL_43;
          }
          for ( i = v4 - 2; ; --i )
          {
            v4 = i;
            if ( i <= 0 || a1[i] == 92 )
              break;
          }
          if ( i < 0 || a1[i] != 92 )
            return -1073741192;
          if ( !i )
            v4 = v8 == v3 - 2;
        }
        LOWORD(v8) = v8 + 1;
      }
LABEL_44:
      v8 = (unsigned __int16)(v8 + 1);
      if ( v8 >= v3 )
        goto LABEL_45;
    }
    a1[v4] = a1[v8];
    goto LABEL_42;
  }
LABEL_45:
  for ( *a3 = 2 * v4; v4 < (int)v3; v4 = (__int16)(v4 + 1) )
    a1[v4] = 0;
  return 0;
}
