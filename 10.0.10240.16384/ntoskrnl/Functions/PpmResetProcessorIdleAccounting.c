// PpmResetProcessorIdleAccounting 
 
_BYTE *__fastcall PpmResetProcessorIdleAccounting(int *a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v8; // r10
  _BYTE *result; // r0
  int *v10; // r1
  int v11; // r5
  int v12; // r6

  v5 = *a1;
  v8 = a1[2];
  result = memset(a1, 0, 984 * *a1 + 40);
  if ( v5 )
  {
    v10 = a1 + 10;
    v11 = v5;
    do
    {
      v10[6] = -1;
      v10[7] = -1;
      result = v10;
      v12 = 26;
      do
      {
        *((_DWORD *)result + 40) = -1;
        *((_DWORD *)result + 41) = -1;
        result += 32;
        --v12;
      }
      while ( v12 );
      v10 += 246;
      --v11;
    }
    while ( v11 );
  }
  a1[2] = v8 + 1;
  a1[8] = 0;
  *a1 = v5;
  a1[4] = a3;
  a1[5] = a4;
  return result;
}
