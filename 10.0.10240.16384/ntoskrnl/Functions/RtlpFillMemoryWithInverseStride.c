// RtlpFillMemoryWithInverseStride 
 
char *__fastcall RtlpFillMemoryWithInverseStride(int a1, int a2, int a3, unsigned int a4)
{
  char *v4; // r6
  unsigned int v6; // r7
  unsigned int v7; // r3
  bool v8; // cc
  unsigned int v9; // r3
  char *result; // r0
  unsigned int v11; // r2
  unsigned int v12; // r3
  char *v13; // r6
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3

  v4 = (char *)a4;
  v6 = a4 + 4096;
  v7 = (a4 >> 2) - 12 * ((unsigned int)((2863311531u * (unsigned __int64)(a4 >> 2)) >> 32) >> 3);
  v8 = v7 > 2 * a2;
  v9 = 2 * a2 - v7;
  if ( v8 )
    v9 += 12;
  result = &v4[4 * v9];
  if ( (unsigned int)result > v6 )
    result = (char *)v6;
  v11 = 0;
  if ( v4 > result )
    v12 = 0;
  else
    v12 = (unsigned int)(result - v4 + 3) >> 2;
  if ( v12 )
  {
    do
    {
      ++v11;
      *(_DWORD *)v4 = a1;
      v4 += 4;
    }
    while ( v11 < v12 );
  }
  v13 = v4 + 8;
  if ( (unsigned int)result < v6 )
  {
    v14 = v6 - 4 * (((int)(v6 - (_DWORD)result) >> 2) % 0xCu);
    if ( result != (char *)v14 )
    {
      while ( 1 )
      {
        result += 48;
        if ( (unsigned int)v13 >= v14 )
          break;
        v15 = 0;
        if ( v13 > result )
          v16 = 0;
        else
          v16 = (unsigned int)(result - v13 + 3) >> 2;
        if ( v16 )
        {
          do
          {
            ++v15;
            *(_DWORD *)v13 = a1;
            v13 += 4;
          }
          while ( v15 < v16 );
        }
        v13 += 8;
      }
    }
  }
  v17 = 0;
  if ( (unsigned int)v13 > v6 )
    v18 = 0;
  else
    v18 = (v6 - (unsigned int)v13 + 3) >> 2;
  if ( v18 )
  {
    do
    {
      ++v17;
      *(_DWORD *)v13 = a1;
      v13 += 4;
    }
    while ( v17 < v18 );
  }
  return result;
}
