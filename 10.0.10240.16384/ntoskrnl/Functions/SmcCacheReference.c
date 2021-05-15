// SmcCacheReference 
 
int __fastcall SmcCacheReference(int a1, unsigned int a2)
{
  _DWORD *v2; // r7
  int v3; // r6
  unsigned int *v4; // r5
  unsigned int v6; // r4
  unsigned int v7; // r0
  int v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1

  v2 = (_DWORD *)(a1 + 16 * (a2 & 0xF));
  v3 = 0;
  v4 = v2 + 1;
  __pld(v2 + 1);
  v6 = v2[1] & 0xFFFFFFFE;
  do
    v7 = __ldrex(v4);
  while ( v7 == v6 && __strex(v6 + 2, v4) );
  __dmb(0xBu);
  if ( v7 == v6 )
  {
    v8 = 1;
  }
  else
  {
    v8 = ExfAcquireRundownProtection(v2 + 1);
    if ( !v8 )
      return v3;
  }
  if ( (v2[3] & 0xFFF) == a2 >> 4 )
  {
    v3 = *v2;
    v8 = 0;
  }
  if ( v8 )
  {
    __pld(v4);
    v9 = *v4 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v10 = __ldrex(v4);
    while ( v10 == v9 && __strex(v9 - 2, v4) );
    if ( v10 != v9 )
      ExfReleaseRundownProtection((unsigned __int8 *)v2 + 4);
  }
  return v3;
}
