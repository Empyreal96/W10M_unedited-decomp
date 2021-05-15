// RtlCharToInteger 
 
int __fastcall RtlCharToInteger(char *a1, unsigned int a2, int *a3)
{
  int v4; // r6
  char *v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r3
  char *v9; // r0
  int v10; // t1
  int v12; // r4
  unsigned int v13; // r5
  int v14; // t1

  v4 = *a1;
  if ( v4 > 32 )
  {
LABEL_6:
    v5 = a1 + 1;
  }
  else
  {
    while ( *++a1 )
    {
      v4 = *a1;
      if ( v4 > 32 )
        goto LABEL_6;
    }
    v5 = a1 - 1;
  }
  v6 = v4;
  if ( v4 == 45 || v4 == 43 )
    v6 = *v5++;
  if ( a2 )
  {
    switch ( a2 )
    {
      case 2u:
        v7 = 1;
        break;
      case 8u:
        v7 = 3;
        break;
      case 0xAu:
        v7 = 0;
        break;
      case 0x10u:
        v7 = 4;
        break;
      default:
        return -1073741811;
    }
  }
  else
  {
    a2 = 10;
    v7 = 0;
    if ( v6 == 48 )
    {
      v8 = *v5;
      v9 = v5 + 1;
      switch ( v8 )
      {
        case 'x':
          a2 = 16;
          v7 = 4;
          break;
        case 'o':
          a2 = 8;
          v7 = 3;
          break;
        case 'b':
          a2 = 2;
          v7 = 1;
          break;
        default:
          --v9;
          break;
      }
      v10 = *v9;
      v5 = v9 + 1;
      v6 = v10;
    }
  }
  v12 = 0;
  while ( v6 )
  {
    if ( v6 < 48 || v6 > 57 )
    {
      if ( v6 < 65 || v6 > 70 )
      {
        if ( v6 < 97 || v6 > 102 )
          break;
        v13 = v6 - 87;
      }
      else
      {
        v13 = v6 - 55;
      }
    }
    else
    {
      v13 = v6 - 48;
    }
    if ( v13 >= a2 )
      break;
    if ( v7 )
      v12 = (v12 << v7) | v13;
    else
      v12 = v12 * a2 + v13;
    v14 = *v5++;
    v6 = v14;
  }
  if ( v4 == 45 )
    v12 = -v12;
  *a3 = v12;
  return 0;
}
