// IopCheckHandleForRevocation 
 
int __fastcall IopCheckHandleForRevocation(int a1, unsigned int *a2, int a3, _DWORD *a4)
{
  unsigned int v5; // r6
  unsigned int v7; // r1

  v5 = *a2 & 0xFFFFFFF8;
  if ( (void *)ObTypeIndexTable[BYTE1(v5) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v5 + 12)] == IoFileObjectType
    && *(_DWORD *)(v5 + 28) == *a4 )
  {
    IopRevokeFileObjectForProcess(v5 + 24, a4[1]);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex(a2);
  while ( __strex(v7 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExpUnblockPushLock((unsigned int *)(a1 + 32), 0, 0);
  return 0;
}
