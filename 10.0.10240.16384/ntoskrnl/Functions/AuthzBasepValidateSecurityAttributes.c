// AuthzBasepValidateSecurityAttributes 
 
int __fastcall AuthzBasepValidateSecurityAttributes(unsigned __int16 *a1, _DWORD *a2)
{
  int v3; // r3
  int result; // r0
  unsigned int v6; // r7
  int v7; // lr
  int v8; // r2
  int v9; // r2
  int v10; // r3
  int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r5
  unsigned __int16 *v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r5
  _QWORD *v17; // r2
  unsigned int v18; // r1
  int v19; // r4
  int *v20; // r2
  int v21; // t1
  unsigned int v22; // r4
  unsigned int v23; // r5
  int v24; // r2
  int i; // [sp+0h] [bp-20h]

  v3 = *a1;
  result = 0;
  if ( v3 == 1 )
  {
    if ( *a2 == 1 )
      return sub_52AE74();
    if ( !a1[1] )
    {
      v6 = *((_DWORD *)a1 + 1);
      if ( v6 )
      {
        if ( *((_DWORD *)a1 + 2) )
        {
          v7 = 0;
          v8 = *((_DWORD *)a1 + 2);
          for ( i = v8; ; v8 = i )
          {
            v9 = v8 + 24 * v7;
            if ( !*(_WORD *)v9 )
              return -1073741811;
            if ( !*(_WORD *)(v9 + 2) )
              return -1073741811;
            if ( !*(_DWORD *)(v9 + 4) )
              return -1073741811;
            if ( *(_WORD *)(v9 + 10) )
              return -1073741811;
            if ( (*(_DWORD *)(v9 + 12) & 0xFF80) != 0 )
              return -1073741811;
            if ( v7 )
            {
              v11 = a2[v7];
              if ( v11 == 1 || v11 == 2 && !*(_DWORD *)(v9 + 16) )
                return -1073741811;
            }
            v10 = *(unsigned __int16 *)(v9 + 8);
            if ( !*(_WORD *)(v9 + 8) )
              goto LABEL_44;
            if ( *(unsigned __int16 *)(v9 + 8) > 2u )
            {
              switch ( v10 )
              {
                case 3:
                  v12 = *(_DWORD *)(v9 + 16);
                  if ( v12 && !*(_DWORD *)(v9 + 20) )
                    return -1073741811;
                  v13 = 0;
                  if ( v12 )
                  {
                    v14 = *(unsigned __int16 **)(v9 + 20);
                    while ( *v14 && v14[1] && *v14 <= (unsigned int)v14[1] && *((_DWORD *)v14 + 1) )
                    {
                      ++v13;
                      v14 += 4;
                      if ( v13 >= v12 )
                        goto LABEL_18;
                    }
LABEL_44:
                    result = -1073741811;
                    break;
                  }
                  break;
                case 6:
                  v15 = *(_DWORD *)(v9 + 16);
                  if ( v15 && !*(_DWORD *)(v9 + 20) )
                    return -1073741811;
                  v16 = 0;
                  if ( v15 )
                  {
                    v17 = *(_QWORD **)(v9 + 20);
                    while ( !*v17 || *v17 == 1i64 )
                    {
                      ++v16;
                      ++v17;
                      if ( v16 >= v15 )
                        goto LABEL_18;
                    }
                    goto LABEL_44;
                  }
                  break;
                case 4:
                  v22 = *(_DWORD *)(v9 + 16);
                  if ( v22 && !*(_DWORD *)(v9 + 20) )
                    return -1073741811;
                  v23 = 0;
                  if ( v22 )
                  {
                    v24 = *(_DWORD *)(v9 + 20);
                    while ( *(_WORD *)(v24 + 8)
                         && *(_WORD *)(v24 + 10)
                         && *(unsigned __int16 *)(v24 + 8) <= (unsigned int)*(unsigned __int16 *)(v24 + 10)
                         && *(_DWORD *)(v24 + 12) )
                    {
                      ++v23;
                      v24 += 16;
                      if ( v23 >= v22 )
                        goto LABEL_18;
                    }
                    goto LABEL_44;
                  }
                  break;
                case 5:
                case 16:
                  v18 = *(_DWORD *)(v9 + 16);
                  if ( v18 && !*(_DWORD *)(v9 + 20) )
                    return -1073741811;
                  v19 = 0;
                  if ( v18 )
                  {
                    v20 = *(int **)(v9 + 20);
                    while ( v20[1] )
                    {
                      v21 = *v20;
                      v20 += 2;
                      if ( !v21 )
                        break;
                      if ( ++v19 >= v18 )
                        goto LABEL_18;
                    }
                    goto LABEL_44;
                  }
                  break;
                default:
                  goto LABEL_44;
              }
            }
            else if ( *(_DWORD *)(v9 + 16) && !*(_DWORD *)(v9 + 20) )
            {
              goto LABEL_44;
            }
LABEL_18:
            if ( result >= 0 && ++v7 < v6 )
              continue;
            return result;
          }
        }
      }
    }
  }
  return -1073741811;
}
