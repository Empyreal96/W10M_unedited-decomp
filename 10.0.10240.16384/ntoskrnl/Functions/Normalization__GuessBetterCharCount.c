// Normalization__GuessBetterCharCount 
 
int __fastcall Normalization__GuessBetterCharCount(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r1
  int v9; // r5

  v4 = a2;
  v5 = a4;
  if ( !a2 )
  {
    v4 = 1;
    v5 = a4 + *(_DWORD *)(a1 + 12);
  }
  v6 = Normalization__GuessCharCountBySize(a1, a3);
  v8 = v7 * v5;
  v9 = v6;
  if ( !v4 )
    __brkdiv0();
  if ( v8 / v4 > v6 )
    v9 = v8 / v4;
  return v9 + (v9 >> 3) + v5;
}
