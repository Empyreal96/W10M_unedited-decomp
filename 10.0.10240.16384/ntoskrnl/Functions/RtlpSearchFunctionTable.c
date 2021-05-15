// RtlpSearchFunctionTable 
 
unsigned int *__fastcall RtlpSearchFunctionTable(int a1, int a2, int a3, int a4)
{
  unsigned int *result; // r0
  unsigned int v8; // r1
  int v9; // r2
  int v10; // r4
  int v11; // r5
  unsigned int v12; // r3
  int v13; // r3

  if ( !a2 )
    return 0;
  result = (unsigned int *)(a1 + 8 * a2 - 8);
  v8 = a3 - a4;
  if ( a3 - a4 < *result )
  {
    v9 = a2 - 2;
    v10 = 0;
    while ( v9 >= v10 )
    {
      v11 = (v9 + v10) >> 1;
      result = (unsigned int *)(a1 + 8 * v11);
      if ( v8 < *result )
      {
        v9 = v11 - 1;
      }
      else
      {
        if ( v8 < result[2] )
          break;
        v10 = v11 + 1;
      }
    }
  }
  if ( v8 < *result )
    return 0;
  v12 = result[1];
  v13 = (v12 & 3) != 0 ? (v12 >> 2) & 0x7FF : *(_DWORD *)(v12 + a4) & 0x3FFFF;
  if ( v8 >= *result + 2 * v13 )
    return 0;
  return result;
}
