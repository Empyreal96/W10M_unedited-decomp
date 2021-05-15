// SmcCacheInitialize 
 
void *__fastcall SmcCacheInitialize(int a1)
{
  void *result; // r0
  _DWORD *v3; // r4
  _DWORD *v4; // r6
  unsigned int *v5; // r5
  unsigned int v6; // r1

  memset((_BYTE *)a1, 0, 896);
  memset((_BYTE *)(a1 + 40), 0, 32);
  result = StEtaInitialize((_BYTE *)(a1 + 72));
  *(_DWORD *)(a1 + 120) = 0;
  v3 = (_DWORD *)(a1 + 124);
  v4 = v3 + 64;
  if ( v3 < v3 + 64 )
  {
    v5 = v3 + 3;
    do
    {
      *v3 = -1;
      v3[3] = 0;
      do
        v6 = __ldrex(v5);
      while ( !v6 && __strex(1u, v5) );
      __dmb(0xBu);
      if ( v6 )
      {
        if ( v6 != 1 )
          result = ExfWaitForRundownProtectionRelease(v5, v6);
      }
      v3 += 4;
      v5 += 4;
    }
    while ( v3 < v4 );
  }
  return result;
}
