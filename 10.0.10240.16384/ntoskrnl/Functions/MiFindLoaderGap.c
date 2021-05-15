// MiFindLoaderGap 
 
int __fastcall MiFindLoaderGap(int a1, unsigned int *a2)
{
  int *v2; // r5
  unsigned int v3; // r4
  int *v4; // r2
  unsigned int v5; // lr
  int v6; // r9
  int v7; // r8
  int v8; // r3
  __int64 v9; // kr00_8
  int result; // r0
  unsigned int v11; // r7
  int *v12; // [sp+4h] [bp-24h]
  unsigned int *v13; // [sp+8h] [bp-20h]

  v2 = *(int **)(a1 + 24);
  v3 = *a2;
  v4 = (int *)(a1 + 24);
  v12 = (int *)(a1 + 24);
  v13 = a2;
  *a2 = 0;
  v5 = 1;
  v6 = -1;
  v7 = -1;
  if ( v2 == (int *)(a1 + 24) )
    return -1;
  do
  {
    v8 = v2[2];
    if ( v8 != 30 && v8 != 31 && v8 != 6 && v8 != 32 && v8 != 23 && v8 != 3 && v8 != 22 )
    {
      v9 = *(_QWORD *)(v2 + 3);
      result = v7 + 1;
      if ( (unsigned int)v9 > v7 + 1 )
      {
        v11 = v9 - result;
        if ( v7 == -1 )
        {
          --v11;
          result = 1;
        }
        if ( v3 && v11 >= v3 )
        {
          a2 = v13;
          if ( (((MmPfnDatabase + 24 * ((unsigned int)v9 - v3)) >> 20) & 0xFFC) - 1070596096 == (((unsigned int)(MmPfnDatabase + 24 * v9) >> 20) & 0xFFC)
                                                                                              - 1070596096 )
          {
            *v13 = v3;
            return v9 - v3;
          }
          if ( v7 != -1
            && (((MmPfnDatabase + 24 * (result + v3) - 1) >> 20) & 0xFFC) - 1070596096 == (((unsigned int)(MmPfnDatabase + 24 * result - 1) >> 20) & 0xFFC)
                                                                                        - 1070596096 )
          {
            *v13 = v3;
            return result;
          }
          v4 = v12;
        }
        if ( v11 > v5 )
        {
          v6 = result;
          v5 = v11;
        }
      }
      v7 = HIDWORD(v9) + v9 - 1;
    }
    v2 = (int *)*v2;
  }
  while ( v2 != v4 );
  if ( v5 == 1 )
    return -1;
  *a2 = v5;
  return v6;
}
