// WheapSortBadPages 
 
int __fastcall WheapSortBadPages(int result, unsigned int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  int v4; // r5
  unsigned int *v5; // r1
  unsigned int v6; // r4
  unsigned int v7; // r6
  unsigned int v8; // t1
  unsigned int v9; // lr
  unsigned int v10; // r8
  unsigned int v11; // r7

  if ( a2 >= 2 )
  {
    v2 = 0;
    v3 = a2 - 1;
    do
    {
      v4 = 0;
      if ( v3 <= v2 )
        break;
      v5 = (unsigned int *)(result + 8 * v3);
      v6 = v3 - v2;
      do
      {
        v8 = *(v5 - 2);
        v5 -= 2;
        v7 = v8;
        v9 = v5[1];
        v10 = v5[3];
        v11 = v5[2];
        if ( __PAIR64__(v9, v8) > __PAIR64__(v10, v11) )
        {
          *v5 = v11;
          v5[1] = v10;
          v5[2] = v7;
          v5[3] = v9;
          v4 = 1;
        }
        --v6;
      }
      while ( v6 );
      if ( !v4 )
        break;
      ++v2;
    }
    while ( v2 < v3 );
  }
  return result;
}
