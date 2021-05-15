// adapt 
 
int __fastcall adapt(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r1

  if ( a3 )
    v3 = a1 / 700;
  else
    v3 = a1 / 2;
  if ( !a2 )
    __brkdiv0();
  v4 = v3 / a2 + v3;
  v5 = 0;
  while ( v4 > 455 )
  {
    v4 /= 35;
    v5 += 36;
  }
  v6 = v4 + 38;
  v7 = 36 * v4;
  if ( !v6 )
    __brkdiv0();
  return v7 / v6 + v5;
}
