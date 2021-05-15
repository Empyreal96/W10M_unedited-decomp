// PopPepComponentGetLatencyIdleState 
 
int __fastcall PopPepComponentGetLatencyIdleState(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r1
  int result; // r0
  __int64 *v7; // r4
  unsigned int v8; // r5
  __int64 v9; // t1
  bool v10; // cc

  v4 = *(_DWORD *)(a1 + 156);
  result = v4 - 1;
  if ( v4 != 1 )
  {
    v7 = (__int64 *)(*(_DWORD *)(a1 + 160) + 24 * result);
    do
    {
      v9 = *v7;
      v7 -= 3;
      v8 = v9;
      v10 = HIDWORD(v9) > a4;
      if ( HIDWORD(v9) < a4 || !v10 && v8 <= a3 )
        break;
      --result;
    }
    while ( result );
  }
  return result;
}
