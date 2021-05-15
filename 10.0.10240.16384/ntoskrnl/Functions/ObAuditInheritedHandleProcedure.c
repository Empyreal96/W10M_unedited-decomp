// ObAuditInheritedHandleProcedure 
 
int __fastcall ObAuditInheritedHandleProcedure(int a1, unsigned int *a2, int a3, _DWORD *a4)
{
  unsigned int v5; // r3
  int v7; // r7
  unsigned int v8; // r6
  int v9; // r0
  int v10; // t1

  v5 = a2[1];
  v7 = *a2 & 6;
  if ( (v5 & 0x4000000) != 0 )
    LOBYTE(v7) = v7 | 8;
  if ( (v5 & 0x2000000) != 0 )
    LOBYTE(v7) = v7 | 1;
  __dmb(0xBu);
  do
    v8 = __ldrex(a2);
  while ( __strex(v8 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  v10 = *(_DWORD *)(a1 + 32);
  v9 = a1 + 32;
  if ( v10 )
    ExfUnblockPushLock(v9, 0);
  if ( (v7 & 4) != 0 )
    SeAuditHandleDuplication(a3, a3, a4[1], *a4);
  return 0;
}
