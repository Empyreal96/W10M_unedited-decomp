// PopPepCancelActivityRange 
 
int __fastcall PopPepCancelActivityRange(int result, int a2, int a3, int a4, unsigned int *a5)
{
  int **v5; // r4
  char *v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r2

  if ( a3 <= a4 )
  {
    v5 = (int **)(result + 4 * a3);
    v6 = &ActivityAttributes[124 * a2 + 4 * a3];
    result = a4 - a3 + 1;
    do
    {
      v7 = *((_DWORD *)v6 + 10);
      if ( v7 )
      {
        v8 = **v5;
        if ( (v7 & v8) != 0 )
        {
          if ( (v8 & 2) != 0 )
          {
            __dmb(0xBu);
            do
              v9 = __ldrex(a5);
            while ( __strex(v9 - 1, a5) );
            __dmb(0xBu);
          }
          **v5 &= 0xFFFFFFFC;
        }
      }
      v6 += 4;
      ++v5;
      --result;
    }
    while ( result );
  }
  return result;
}
