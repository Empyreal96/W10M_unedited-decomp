// PnpHandleProcessWalkWorker 
 
int __fastcall PnpHandleProcessWalkWorker(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v5; // r9
  int v8; // r4
  unsigned int v9; // r1

  v5 = *a2 & 0xFFFFFFF8;
  if ( (void *)ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(*(_WORD *)a2 & 0xFFF8) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v5 + 12)] == IoFileObjectType
    && IoGetBaseFileSystemDeviceObject((_DWORD *)(v5 + 24)) == *(_DWORD *)a4 )
  {
    v8 = (*(unsigned __int8 (__fastcall **)(_DWORD, _DWORD, unsigned int, int))(a4 + 8))(
           *(_DWORD *)a4,
           *(_DWORD *)(a4 + 4),
           v5 + 24,
           a3);
  }
  else
  {
    v8 = 0;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex(a2);
  while ( __strex(v9 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  return v8;
}
