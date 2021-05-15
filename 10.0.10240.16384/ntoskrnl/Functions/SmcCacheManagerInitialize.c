// SmcCacheManagerInitialize 
 
_BYTE *__fastcall SmcCacheManagerInitialize(int a1)
{
  int v2; // r6
  int v3; // r4
  unsigned int *v4; // r0
  unsigned int v5; // r1
  _BYTE *result; // r0

  memset((_BYTE *)a1, 0, 280);
  v2 = 16;
  v3 = a1;
  do
  {
    v4 = (unsigned int *)(v3 + 4);
    *(_DWORD *)(v3 + 4) = 0;
    do
      v5 = __ldrex(v4);
    while ( !v5 && __strex(1u, v4) );
    __dmb(0xBu);
    if ( v5 != 1 && v5 )
      ExfWaitForRundownProtectionRelease(v4, v5);
    *(_DWORD *)(v3 + 8) = 0;
    v3 += 16;
    --v2;
  }
  while ( v2 );
  result = memset((_BYTE *)(a1 + 256), 0, 20);
  *(_DWORD *)(a1 + 256) = 0;
  *(_DWORD *)(a1 + 260) = a1 + 260;
  *(_DWORD *)(a1 + 264) = a1 + 260;
  return result;
}
