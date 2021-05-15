// CmpLockHashEntryShared 
 
int __fastcall CmpLockHashEntryShared(int a1, unsigned int a2)
{
  unsigned int *v3; // r6
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0

  v3 = (unsigned int *)(*(_DWORD *)(a1 + 1844)
                      + 12
                      * (((101027 * (a2 ^ (a2 >> 9))) ^ ((101027 * (a2 ^ (a2 >> 9))) >> 9)) & (*(_DWORD *)(a1 + 1848) - 1)));
  v4 = KeAbPreAcquire((unsigned int)v3, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( !v6 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  result = CmpReferenceHive(a1);
  if ( !result )
    sub_7FE93C();
  return result;
}
