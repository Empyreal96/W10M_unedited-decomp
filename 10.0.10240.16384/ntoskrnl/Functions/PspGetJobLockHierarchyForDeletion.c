// PspGetJobLockHierarchyForDeletion 
 
int __fastcall PspGetJobLockHierarchyForDeletion(int a1, int a2)
{
  unsigned int v4; // r6
  int v5; // r0
  unsigned int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r1
  int result; // r0
  __int16 v12; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  v5 = KeAbPreAcquire((unsigned int)&PspJobAssignmentLock, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)&PspJobAssignmentLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&PspJobAssignmentLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    return sub_7C0BEC(v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *(_DWORD *)(a1 + 572);
  v8 = 0;
  if ( v7 )
  {
    *(_DWORD *)(a2 + 4) = v7;
    *(_BYTE *)(a2 + 8) = 0;
    v8 = 1;
  }
  v9 = a2 + 8 * v8;
  *(_DWORD *)(v9 + 4) = a1;
  *(_BYTE *)(v9 + 8) = 0;
  *(_DWORD *)a2 = v8 + 1;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&PspJobAssignmentLock);
  while ( __strex(v10 - 1, (unsigned int *)&PspJobAssignmentLock) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PspJobAssignmentLock);
  result = KeAbPostRelease((unsigned int)&PspJobAssignmentLock);
  v12 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v12;
  if ( !v12 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
