// PspSetFileHandleFlow 
 
BOOL __fastcall PspSetFileHandleFlow(int a1, unsigned int *a2, int a3, int *a4)
{
  unsigned int v5; // r0
  int v6; // r6
  unsigned int v8; // r1

  v5 = *a2 & 0xFFFFFFF8;
  v6 = 0;
  if ( (void *)ObTypeIndexTable[BYTE1(v5) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v5 + 12)] == IoFileObjectType )
  {
    v6 = IoSetHandleFlow(v5 + 24, *a4, (int)IoFileObjectType, a4[1]);
    if ( v6 == -1073741585 )
      v6 = 0;
  }
  __dmb(0xBu);
  do
    v8 = __ldrex(a2);
  while ( __strex(v8 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  return v6 < 0;
}
