// MdlInvariantPostDriverCompletion 
 
_BYTE *__fastcall MdlInvariantPostDriverCompletion(_BYTE *result, int a2)
{
  _DWORD *v2; // lr
  _BYTE *v3; // r7
  int v4; // r8
  _DWORD *v5; // r2
  int v6; // r4
  int *v7; // r6
  int v8; // r0
  int v9; // t1
  _DWORD *v10; // r2
  _DWORD *v11; // r4
  int v12; // r1
  int *v13; // r6
  int v14; // r5
  int v15; // t1

  v2 = *(_DWORD **)(a2 + 4);
  v3 = result;
  if ( !*v2 )
  {
    v4 = *(char *)(a2 + 35);
    if ( v4 >= *(char *)(a2 + 34) - 1 )
    {
      v5 = (_DWORD *)*((_DWORD *)result + 33);
      if ( v5 )
      {
        v6 = 0;
        if ( *v5 )
        {
          v7 = (int *)v5[1];
          while ( 1 )
          {
            v9 = *v7;
            v7 += 8;
            v8 = v9;
            if ( v9 )
            {
              if ( v8 == *(_DWORD *)(a2 + 4) )
                break;
            }
            if ( (unsigned int)++v6 >= *v5 )
              goto LABEL_9;
          }
          result = (_BYTE *)(v5[1] + 32 * v6);
        }
        else
        {
LABEL_9:
          result = 0;
        }
        if ( result )
          goto LABEL_22;
      }
    }
    v10 = (_DWORD *)*((_DWORD *)v3 + 33);
    if ( v10 )
    {
      v11 = (_DWORD *)v10[2];
      if ( v11 )
      {
        v12 = 0;
        if ( *v10 )
        {
          v13 = (int *)v10[1];
          while ( 1 )
          {
            v15 = *v13;
            v13 += 8;
            v14 = v15;
            if ( v15 )
            {
              if ( v14 == *(_DWORD *)(*((_DWORD *)v3 + 33) + 8) )
                break;
            }
            if ( (unsigned int)++v12 >= *v10 )
              goto LABEL_18;
          }
          result = (_BYTE *)(v10[1] + 32 * v12);
        }
        else
        {
LABEL_18:
          result = 0;
        }
        if ( result && ((char)result[24] == v4 + 1 || v11 != v2) )
LABEL_22:
          result = memset(result, 0, 32);
      }
    }
  }
  return result;
}
