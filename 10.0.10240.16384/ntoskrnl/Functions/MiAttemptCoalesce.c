// MiAttemptCoalesce 
 
int *__fastcall MiAttemptCoalesce(int *result, int a2, int a3)
{
  int *v3; // r7
  int v4; // r6
  int v5; // r3
  unsigned int v6; // r5
  unsigned int v7; // r8
  unsigned int v8; // r4
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r2
  int *v12; // lr
  int v13; // t1
  int v15; // r3

  v3 = result;
  v4 = 1024;
  if ( (result[3] & 4) != 0 )
    v4 = 64;
  v5 = (v4 + a2 + a3 - 1) & ~(v4 - 1);
  v6 = a2 & ~(v4 - 1);
  v7 = v5 - v6;
  v8 = 0;
  if ( v5 != v6 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = v9 + v6;
      if ( v9 + v6 < *v3 )
      {
        v11 = v3[1];
        result = (int *)(v11 + 4 * (v6 >> 5));
        v12 = (int *)(v11 + 4 * (v10 >> 5));
        if ( result == v12 )
        {
          if ( ((0xFFFFFFFF >> (32 - v4) << (v6 & 0x1F)) & *result) == 0 )
            goto LABEL_14;
          goto LABEL_18;
        }
        v13 = *result++;
        if ( ((-1 << (v6 & 0x1F)) & v13) == 0 )
        {
          while ( result != v12 )
          {
            if ( *result++ )
              goto LABEL_8;
          }
          if ( ((0xFFFFFFFF >> (31 - (v10 & 0x1F))) & *result) == 0 )
          {
LABEL_14:
            v15 = 1;
            goto LABEL_15;
          }
LABEL_18:
          v15 = 0;
LABEL_15:
          if ( v15 == 1 )
          {
            result = (int *)RtlInterlockedSetClearRun(v3, v6, v4);
            if ( result == (int *)1 )
              result = (int *)MiReturnSystemPtes(v3, v6, v4, 0);
          }
          goto LABEL_8;
        }
      }
LABEL_8:
      v8 += v4;
      v6 += v4;
    }
    while ( v8 < v7 );
  }
  return result;
}
