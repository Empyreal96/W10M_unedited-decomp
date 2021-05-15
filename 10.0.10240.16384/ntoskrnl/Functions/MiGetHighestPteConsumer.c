// MiGetHighestPteConsumer 
 
int *__fastcall MiGetHighestPteConsumer(unsigned int *a1)
{
  char v1; // r3
  int *result; // r0
  int *v3; // r1
  unsigned int i; // r2
  int *v5; // r2
  unsigned int v6; // r6
  unsigned int v7; // r5
  int v8; // r3
  int *v9; // r7
  int *v10; // r1
  int v11; // r10
  unsigned int v12; // r8
  unsigned int v13; // r4
  int v14; // [sp+4h] [bp-2Ch]

  v1 = dword_681258;
  *a1 = 0;
  if ( (v1 & 1) == 0 || byte_634854 == 1 )
    return 0;
  v3 = &dword_634F90;
  for ( i = 0; i < 0x10; ++i )
  {
    if ( (int *)*v3 != v3 )
      break;
    v3 += 2;
  }
  if ( i == 16 || !PsLoadedModuleList )
    return 0;
  v5 = (int *)dword_62127C;
  v6 = 0;
  for ( result = 0; v5 != &PsLoadedModuleList; v5 = (int *)v5[1] )
  {
    v7 = 0;
    v8 = 16;
    v14 = 16;
    v9 = MiState;
    do
    {
      v10 = (int *)v9[2372];
      if ( v10 != v9 + 2372 )
      {
        do
        {
          v11 = v10[9];
          if ( (v11 & 2) == 0 )
          {
            if ( (v12 = v5[6], v10[11] >= v12) && v10[11] < v5[8] + v12
              || (v13 = v10[12], v13 >= v12) && v13 < v5[8] + v12 )
            {
              v7 += v10[3];
              v10[9] = v11 | 2;
            }
          }
          v10 = (int *)*v10;
        }
        while ( v10 != v9 + 2372 );
        v8 = v14;
      }
      v9 += 2;
      v14 = --v8;
    }
    while ( v8 );
    if ( v7 > v6 )
    {
      v6 = v7;
      result = v5;
    }
  }
  *a1 = v6;
  return result;
}
