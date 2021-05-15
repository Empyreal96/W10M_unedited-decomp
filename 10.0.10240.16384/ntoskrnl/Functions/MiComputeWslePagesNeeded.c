// MiComputeWslePagesNeeded 
 
int __fastcall MiComputeWslePagesNeeded(int a1, int a2)
{
  int v2; // r6
  int v3; // r10
  unsigned int v4; // r7
  unsigned int v5; // r4

  v2 = 0;
  v3 = 2;
  v4 = 4096;
  do
  {
    v5 = v4 - 1;
    if ( ((v4 - 1) & a1) != 0 && (((a2 - 1) ^ a1) & ~v5) == 0 )
      break;
    if ( !v4 )
      __brkdiv0();
    v2 += (((v4 + a2 - 1) & ~v5) - ((v4 + a1 - 1) & ~v5)) / v4;
    v4 <<= 10;
    --v3;
  }
  while ( v3 );
  return v2;
}
