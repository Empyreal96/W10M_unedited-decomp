// PopPepVerifyActivities 
 
_DWORD *__fastcall PopPepVerifyActivities(int a1, int a2, unsigned int a3)
{
  _DWORD *v3; // lr
  int v4; // r1
  _DWORD *v5; // r4
  _DWORD *result; // r0
  _DWORD *v7; // t1

  if ( a3 <= 5 && ActivityAttributes[124 * a3] == 1 )
    v3 = (_DWORD *)(a1 + 48);
  else
    v3 = (_DWORD *)(a2 + 48);
  v4 = 0;
  v5 = v3;
  do
  {
    v7 = (_DWORD *)*v5++;
    result = v7;
    if ( v7 )
    {
      if ( (*(_DWORD *)&ActivityAttributes[124 * a3 + 16 + 4 * v4] & *result) != 0 )
        sub_540308();
    }
    ++v4;
  }
  while ( v4 < 6 );
  return result;
}
