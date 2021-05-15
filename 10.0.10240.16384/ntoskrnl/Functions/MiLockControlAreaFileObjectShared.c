// MiLockControlAreaFileObjectShared 
 
int __fastcall MiLockControlAreaFileObjectShared(int a1)
{
  unsigned int v1; // r2
  unsigned int *v2; // r5
  int result; // r0
  unsigned int v4; // r2

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 310);
  v2 = (unsigned int *)(a1 + 72);
  result = KeAbPreAcquire(a1 + 72, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( !v4 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v4 )
    return sub_512348(result, 17);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
