// CmpTryToLockHashEntryByIndexExclusive 
 
int __fastcall CmpTryToLockHashEntryByIndexExclusive(int a1, int a2)
{
  int v3; // r5
  int v5; // r0
  unsigned int v6; // r2
  int v7; // r4

  v3 = *(_DWORD *)(a1 + 1844) + 12 * a2;
  v5 = KeAbPreAcquire(v3, 0, 1);
  do
    v6 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v6 | 1, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
  {
    if ( v5 )
      KeAbPostReleaseEx(v3, v5);
    v7 = 0;
  }
  else
  {
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    v7 = 1;
    *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( !CmpReferenceHive(a1) )
      KeBugCheckEx(81, 23, a1, 12, a2);
  }
  return v7;
}
