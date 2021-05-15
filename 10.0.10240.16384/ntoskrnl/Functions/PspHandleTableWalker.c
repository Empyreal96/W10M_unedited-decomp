// PspHandleTableWalker 
 
int __fastcall PspHandleTableWalker(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v6; // r6
  unsigned int *v7; // r0
  int v8; // t1
  __int64 v9; // kr00_8

  __dmb(0xBu);
  do
    v6 = __ldrex(a2);
  while ( __strex(v6 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  v8 = *(_DWORD *)(a1 + 32);
  v7 = (unsigned int *)(a1 + 32);
  if ( v8 )
    ExpUnblockPushLock(v7, 0, 0);
  v9 = *(_QWORD *)(a4 + 4);
  if ( HIDWORD(v9) >= (unsigned int)v9 )
    return 1;
  *(_DWORD *)(*(_DWORD *)a4 + 4 * HIDWORD(v9)) = a3;
  ++*(_DWORD *)(a4 + 8);
  return 0;
}
