// ExUnlockHandleTableEntry 
 
int __fastcall ExUnlockHandleTableEntry(int a1, unsigned int *a2)
{
  unsigned int v2; // r4
  int result; // r0
  int v4; // t1

  __dmb(0xBu);
  do
    v2 = __ldrex(a2);
  while ( __strex(v2 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  v4 = *(_DWORD *)(a1 + 32);
  result = a1 + 32;
  if ( v4 )
    result = ExfUnblockPushLock(result, 0);
  return result;
}
