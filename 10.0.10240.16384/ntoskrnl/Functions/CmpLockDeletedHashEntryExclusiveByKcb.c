// CmpLockDeletedHashEntryExclusiveByKcb 
 
int __fastcall CmpLockDeletedHashEntryExclusiveByKcb(int a1)
{
  int v2; // r5
  unsigned int v3; // r8
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0

  v2 = *(_DWORD *)(a1 + 20);
  v3 = *(_DWORD *)(v2 + 1852)
     + 12
     * ((*(_DWORD *)(v2 + 1856) - 1) & ((101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9))) ^ ((unsigned int)(101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9))) >> 9)));
  v4 = KeAbPreAcquire(v3, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v5 | 1, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7D256C(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = CmpReferenceHive(v2);
  if ( !result )
    KeBugCheckEx(81, 23, v2, 8, a1);
  return result;
}
