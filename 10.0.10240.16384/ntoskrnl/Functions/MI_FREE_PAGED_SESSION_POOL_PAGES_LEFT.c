// MI_FREE_PAGED_SESSION_POOL_PAGES_LEFT 
 
unsigned int MI_FREE_PAGED_SESSION_POOL_PAGES_LEFT()
{
  int v0; // r2
  int v1; // r0
  unsigned int v2; // r4
  int v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r3

  v0 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v1 = *(_DWORD *)(v0 + 3244);
  v2 = *(_DWORD *)(v0 + 8308);
  v3 = dword_635310;
  v4 = v2 << 22;
  if ( dword_63529C )
  {
    if ( v2 < dword_63529C )
    {
      if ( dword_635310 > (dword_63529C - v2) << 22 )
        v3 = (dword_63529C - v2) << 22;
    }
    else
    {
      v3 = 0;
    }
  }
  v5 = v4 - (v1 << 12);
  if ( v4 <= v1 << 12 )
    v5 = 0;
  return (v5 + v3) >> 12;
}
