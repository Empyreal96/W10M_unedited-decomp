// sub_7F233C 
 
void sub_7F233C()
{
  unsigned int v0; // r4
  int v1; // r8
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire(v0, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)v0);
  while ( __strex(v5 | 1, (unsigned __int8 *)v0) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v0, v3, v0);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v0 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v1 != 5 )
    JUMPOUT(0x708492);
  JUMPOUT(0x70848A);
}
