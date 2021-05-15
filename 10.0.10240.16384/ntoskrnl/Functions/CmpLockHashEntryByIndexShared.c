// CmpLockHashEntryByIndexShared 
 
int __fastcall CmpLockHashEntryByIndexShared(int a1, int a2)
{
  unsigned int *v3; // r5
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int result; // r0

  v3 = (unsigned int *)(*(_DWORD *)(a1 + 1844) + 12 * a2);
  v5 = KeAbPreAcquire((unsigned int)v3, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v3);
  while ( !v7 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(v3, v5, (unsigned int)v3);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  result = CmpReferenceHive(a1);
  if ( !result )
    KeBugCheckEx(81, 23, a1, 10, a2);
  return result;
}
