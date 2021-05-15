// ObpShutdownCloseHandleProcedure 
 
int __fastcall ObpShutdownCloseHandleProcedure(int a1, unsigned int *a2, int a3, _DWORD *a4)
{
  unsigned int v6; // r9
  unsigned int v7; // r6
  int v8; // r0
  int v9; // t1

  v6 = *a2 & 0xFFFFFFF8;
  __dmb(0xBu);
  do
    v7 = __ldrex(a2);
  while ( __strex(v7 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  v9 = *(_DWORD *)(a1 + 32);
  v8 = a1 + 32;
  if ( v9 )
    ExfUnblockPushLock(v8, 0);
  DbgPrint("\tFound object %p(handle %08lx)\n", (const void *)(v6 + 24), a3);
  ++*a4;
  return 0;
}
