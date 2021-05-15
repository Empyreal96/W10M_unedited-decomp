// CmpLockHashEntryExclusive 
 
int __fastcall CmpLockHashEntryExclusive(int a1, unsigned int a2)
{
  unsigned int v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0

  v3 = *(_DWORD *)(a1 + 1844)
     + 12 * ((*(_DWORD *)(a1 + 1848) - 1) & ((101027 * (a2 ^ (a2 >> 9))) ^ ((101027 * (a2 ^ (a2 >> 9))) >> 9)));
  v4 = KeAbPreAcquire(v3, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v6 | 1, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v3, v4, v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = CmpReferenceHive(a1);
  if ( !result )
    sub_804F34();
  return result;
}
