// ObpAuditObjectAccess 
 
int __fastcall ObpAuditObjectAccess(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  int v8; // r0
  int *v9; // r8
  unsigned int v10; // r5
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r4
  unsigned int v15; // r1
  __int16 v16; // r3

  if ( !*(_DWORD *)(a1 + 4) )
    return 1;
  v8 = ExpGetHandleExtraInfo(a1, a2);
  v9 = (int *)v8;
  if ( !v8 )
    return 1;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  do
  {
    while ( 1 )
    {
      __pld(a3);
      v11 = *a3;
      if ( (*a3 & 1) != 0 )
        break;
      if ( !v11 )
      {
        v14 = 0;
        goto LABEL_20;
      }
      v8 = ExpBlockOnLockedHandleEntry(a1, (unsigned __int64 *)a3, *a3);
    }
    do
      v12 = __ldrex(a3);
    while ( v12 == v11 && __strex(v11 - 1, a3) );
    __dmb(0xBu);
  }
  while ( v12 != v11 );
  v13 = *v9;
  if ( a4 == (*a3 & 0xFFFFFFF8) )
  {
    v8 = v13 & a5;
    if ( (v13 & a5) != 0 )
    {
      *v9 = v13 & ~a5;
      v8 = SeOperationAuditAlarm(v8);
    }
    v14 = 1;
  }
  else
  {
    v14 = 0;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex(a3);
  while ( __strex(v15 + 1, a3) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    v8 = ExfUnblockPushLock(a1 + 32, 0);
LABEL_20:
  v16 = *(_WORD *)(v10 + 308) + 1;
  *(_WORD *)(v10 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v14;
}
