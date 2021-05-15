// CmpGetToken 
 
char **__fastcall CmpGetToken(char **result, unsigned int a2, int a3)
{
  char **v4; // r2
  char *v6; // r4
  int v7; // r3
  int v8; // r3
  int v9; // r3
  char *v10; // r8
  _BYTE *v11; // r0
  _BYTE *v12; // r10
  int v13; // r3
  int v14; // r3
  char *v15; // r5
  int v16; // r3
  int v17; // r3
  char *v18; // r5
  char **v19; // [sp+4h] [bp-24h]

  v4 = result;
  v19 = result;
  *(_BYTE *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 4) = 0;
  while ( 1 )
  {
    v6 = *v4;
    if ( (unsigned int)*v4 >= a2 )
      break;
    do
    {
      v7 = *v6;
      if ( v7 == 10 )
        break;
      result = (char **)isspace((unsigned __int8)v7);
      if ( !result )
        break;
      ++v6;
    }
    while ( (unsigned int)v6 < a2 );
    if ( (unsigned int)v6 >= a2 )
      goto LABEL_58;
    v8 = *v6;
    if ( v8 == 59 || v8 == 35 )
    {
      do
      {
        if ( *v6 == 10 )
          break;
        ++v6;
      }
      while ( (unsigned int)v6 < a2 );
    }
    if ( (unsigned int)v6 >= a2 )
    {
LABEL_58:
      v4 = v19;
      break;
    }
    v9 = *v6;
    switch ( v9 )
    {
      case 10:
        ++v6;
        v13 = 1;
        break;
      case 44:
        ++v6;
        v13 = 6;
        break;
      case 92:
        v15 = ++v6;
        if ( (unsigned int)v6 < a2 )
        {
          do
          {
            v16 = *v15;
            if ( v16 == 10 )
              break;
            result = (char **)isspace((unsigned __int8)v16);
            if ( !result )
              break;
            ++v15;
          }
          while ( (unsigned int)v15 < a2 );
        }
        v17 = *v15;
        if ( v17 != 59 && v17 != 35 )
          goto LABEL_38;
        v15 = ++v6;
        if ( (unsigned int)v6 < a2 )
        {
          do
          {
            if ( *v15 == 10 )
              break;
            ++v15;
          }
          while ( (unsigned int)v15 < a2 );
LABEL_38:
          if ( (unsigned int)v15 < a2 )
          {
            if ( *v15 == 10 )
            {
              v6 = v15 + 1;
              v14 = 0;
              goto LABEL_29;
            }
LABEL_18:
            v10 = v6;
            if ( (unsigned int)v6 >= a2 )
              goto LABEL_60;
            do
            {
              result = (char **)strchr(StringTerminators, *v6);
              if ( result )
                break;
              ++v6;
            }
            while ( (unsigned int)v6 < a2 );
            if ( v6 == v10 )
            {
LABEL_60:
              ++v6;
              *(_DWORD *)a3 = 7;
            }
            else
            {
              if ( v6 - v10 + 1 < (unsigned int)(v6 - v10) )
                return (char **)sub_96C020();
              v11 = (_BYTE *)ExAllocatePoolWithTag(1, v6 - v10 + 1, 1768967491);
              v12 = v11;
              if ( !v11 )
                return (char **)sub_96C020();
              result = (char **)strncpy_s(v11, v6 - v10 + 1, v10, v6 - v10);
              *(_DWORD *)a3 = 4;
              *(_DWORD *)(a3 + 4) = v12;
              *(_BYTE *)(a3 + 8) = 1;
              v12[v6 - v10] = 0;
            }
            goto LABEL_28;
          }
        }
LABEL_57:
        *(_DWORD *)a3 = 7;
        goto LABEL_28;
      case 61:
        ++v6;
        v13 = 5;
        break;
      case 34:
        v18 = ++v6;
        if ( (unsigned int)v6 >= a2 )
          goto LABEL_57;
        do
        {
          result = (char **)strchr((_BYTE *)&StringTerminators[1] + 2, *v6);
          if ( result )
            break;
          ++v6;
        }
        while ( (unsigned int)v6 < a2 );
        if ( (unsigned int)v6 >= a2 || *v6 != 34 )
          goto LABEL_57;
        *v6++ = 0;
        v13 = 4;
        *(_DWORD *)(a3 + 4) = v18;
        break;
      case 91:
        ++v6;
        v13 = 2;
        break;
      case 26:
        goto LABEL_58;
      case 93:
        ++v6;
        v13 = 3;
        break;
      default:
        goto LABEL_18;
    }
    *(_DWORD *)a3 = v13;
LABEL_28:
    v14 = 1;
LABEL_29:
    v4 = v19;
    *v19 = v6;
    if ( v14 )
      return result;
  }
  *v4 = v6;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  return result;
}
