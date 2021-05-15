// MiTryLockVad 
 
int __fastcall MiTryLockVad(int a1, int a2)
{
  int result; // r0
  unsigned __int8 *v4; // r5
  int v5; // r0
  unsigned int v6; // r2

  if ( (*(_BYTE *)(a1 + 968) & 0x80) == 128 )
    return 0;
  v4 = (unsigned __int8 *)(a2 + 24);
  v5 = KeAbPreAcquire(a2 + 24, 0, 1);
  do
    v6 = __ldrex(v4);
  while ( __strex(v6 | 1, v4) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
  {
    if ( v5 )
      KeAbPostReleaseEx((int)v4, v5);
    result = 0;
  }
  else
  {
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    result = 1;
  }
  if ( result == 1 )
    *(_BYTE *)(a1 + 968) |= 0x80u;
  return result;
}
