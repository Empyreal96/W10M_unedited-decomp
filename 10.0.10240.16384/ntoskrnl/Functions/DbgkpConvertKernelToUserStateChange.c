// DbgkpConvertKernelToUserStateChange 
 
int *__fastcall DbgkpConvertKernelToUserStateChange(int *result, _DWORD *a2)
{
  int v3; // r3
  int v4; // r3
  int **v5; // r5
  int *v6; // r1
  int *v7; // r2
  int *v8; // r3
  int **v9; // r5
  int *v10; // r1
  int *v11; // r2
  int *v12; // r3
  int *v13; // r2
  int *v14; // r3
  int v15; // r2
  int v16; // r3

  result[1] = a2[6];
  result[2] = a2[7];
  v3 = a2[20];
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      *result = 2;
      result[4] = a2[22];
      result[5] = a2[23];
    }
    else if ( v3 == 2 )
    {
      *result = 3;
      v9 = (int **)(result + 5);
      result = (int *)a2[22];
      v10 = (int *)a2[23];
      v11 = (int *)a2[24];
      v12 = (int *)a2[25];
      *v9 = result;
      v9[1] = v10;
      v9[2] = v11;
      v9[3] = v12;
      v9 += 4;
      v13 = (int *)a2[27];
      v14 = (int *)a2[28];
      *v9 = (int *)a2[26];
      v9[1] = v13;
      v9[2] = v14;
      a2[23] = 0;
    }
    else
    {
      switch ( v3 )
      {
        case 3:
          v4 = 4;
          break;
        case 4:
          v4 = 5;
          break;
        case 5:
          *result = 9;
          v5 = (int **)(result + 3);
          result = (int *)a2[22];
          v6 = (int *)a2[23];
          v7 = (int *)a2[24];
          v8 = (int *)a2[25];
          *v5 = result;
          v5[1] = v6;
          v5[2] = v7;
          v5[3] = v8;
          v5[4] = (int *)a2[26];
          a2[22] = 0;
          return result;
        case 6:
          v4 = 10;
          break;
        default:
          return result;
      }
      *result = v4;
      result[3] = a2[22];
    }
  }
  else
  {
    v15 = a2[22];
    if ( v15 == -2147483645 )
    {
      v16 = 7;
    }
    else if ( v15 == -2147483644 )
    {
      v16 = 8;
    }
    else
    {
      v16 = 6;
    }
    *result = v16;
    result = (int *)memmove((int)(result + 3), (int)(a2 + 22), 0x54u);
  }
  return result;
}
