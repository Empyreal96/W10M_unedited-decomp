// LOCK_ADDRESS_SPACE_SHARED 
 
int __fastcall LOCK_ADDRESS_SPACE_SHARED(int a1, int a2)
{
  unsigned int *v3; // r6
  int result; // r0
  int v5; // r4
  unsigned int v6; // r2

  --*(_WORD *)(a1 + 310);
  v3 = (unsigned int *)(a2 + 252);
  result = KeAbPreAcquire(a2 + 252, 0, 0);
  v5 = result;
  do
    v6 = __ldrex(v3);
  while ( !v6 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v6 )
    result = ExfAcquirePushLockSharedEx(v3, result, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_BYTE *)(a1 + 968) |= 2u;
  return result;
}
