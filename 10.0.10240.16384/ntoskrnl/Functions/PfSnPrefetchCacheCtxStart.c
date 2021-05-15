// PfSnPrefetchCacheCtxStart 
 
int __fastcall PfSnPrefetchCacheCtxStart(unsigned int a1)
{
  int v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r2
  unsigned int *v5; // r5
  unsigned int v6; // r0
  unsigned int v7; // r3
  int v8; // r3
  _DWORD *v9; // r0
  _DWORD *v10; // r2

  v2 = ExAllocatePoolWithTag(512, 4096, 1716544323);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  v4 = v2 + 128;
  v5 = (unsigned int *)v2;
  v6 = 0;
  if ( v3 > v4 )
    v7 = 0;
  else
    v7 = 32;
  if ( v7 )
  {
    do
    {
      ++v6;
      *v5++ = a1 | 1;
    }
    while ( v6 < v7 );
  }
  if ( (*(_DWORD *)(a1 + 4) & 0xFFFFFFE0) != 0 )
    return sub_8195DC(0);
  v8 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 8) = v3;
  *(_DWORD *)(a1 + 4) = v8 & 0x1F | 0x400;
  v9 = (_DWORD *)((v3 + 131) & 0xFFFFFFFC);
  v10 = &v9[26 * ((v3 - (unsigned int)v9 + 4096) / 0x68)];
  while ( v9 < v10 )
  {
    *v9 = *(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 20) = v9;
    v9 += 26;
  }
  return 0;
}
