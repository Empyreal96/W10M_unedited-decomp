// ExInitializeRundownProtectionCacheAware 
 
int __fastcall ExInitializeRundownProtectionCacheAware(int *a1, int a2)
{
  unsigned int v2; // r6
  _DWORD *v4; // r7
  int result; // r0
  unsigned int v6; // r0
  unsigned int v7; // r5
  int v8; // r7
  unsigned int v9; // r5
  unsigned int v10; // r0
  int v11; // r1

  v2 = a2 - 16;
  v4 = a1 + 4;
  if ( a2 == 20 )
    return sub_81715C();
  v6 = KeGetRecommendedSharedDataAlignment();
  v7 = v6;
  if ( !v6 )
    __brkdiv0();
  result = v2 / v6;
  v8 = ((unsigned int)v4 + v7 - 1) & ~(v7 - 1);
  a1[1] = 195938833;
  a1[2] = v7;
  v9 = 0;
  *a1 = v8;
  a1[3] = result - 1;
  if ( result != 1 )
  {
    do
    {
      v10 = a1[3];
      if ( !v10 )
        __brkdiv0();
      v11 = v9 % v10;
      result = v9 / v10;
      ++v9;
      *(_DWORD *)(v11 * a1[2] + *a1) = 0;
    }
    while ( v9 < a1[3] );
  }
  return result;
}
