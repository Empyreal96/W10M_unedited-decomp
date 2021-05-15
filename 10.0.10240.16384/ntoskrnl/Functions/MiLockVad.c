// MiLockVad 
 
int __fastcall MiLockVad(int a1, int a2)
{
  unsigned __int8 *v3; // r6
  int result; // r0
  int v5; // r4
  unsigned int v6; // r2

  --*(_WORD *)(a1 + 310);
  v3 = (unsigned __int8 *)(a2 + 24);
  result = KeAbPreAcquire(a2 + 24, 0, 0);
  v5 = result;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v3, result, v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_BYTE *)(a1 + 968) |= 0x80u;
  return result;
}
