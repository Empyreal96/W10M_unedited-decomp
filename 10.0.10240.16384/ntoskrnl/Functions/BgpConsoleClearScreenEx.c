// BgpConsoleClearScreenEx 
 
int BgpConsoleClearScreenEx()
{
  int result; // r0
  int v1; // r3
  int *v2; // r2
  int v3; // r1
  unsigned int v4; // r6
  int *v5; // r5

  dword_610384 = 0;
  dword_610388 = 0;
  result = BgpClearScreen(dword_610358);
  if ( result >= 0 )
  {
    v1 = dword_61034C;
    v2 = &dword_610348;
    v3 = 80;
    do
    {
      v4 = 0;
      if ( v1 )
      {
        v5 = v2;
        do
        {
          *((_WORD *)v5 + 40) = 32;
          ++v4;
          v5[19] = dword_610358;
          v5[18] = dword_610354;
          v1 = dword_61034C;
          v5 += 3;
        }
        while ( v4 < dword_61034C );
      }
      v2 += 75;
      --v3;
    }
    while ( v3 );
  }
  return result;
}
