// IopCancelIrpsInThreadList 
 
int __fastcall IopCancelIrpsInThreadList(int a1, int a2)
{
  int v4; // r1
  int v6; // r0
  char v7[16]; // [sp+10h] [bp-10h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 == v4 )
    return IopCancelIrpsInCurrentThreadList(
             *(_DWORD *)(a2 + 48),
             v4,
             *(_DWORD *)(a2 + 52),
             *(unsigned __int8 *)(a2 + 72));
  KeInitializeApc(a2, a1, 0, (int)IopCancelIrpsInCurrentThreadListSpecialApc, 0, 0, 0, 0);
  if ( KeInsertQueueApc(a2, (int)v7, 0, 0) )
  {
    KeWaitForSingleObject(a2 + 56, 0, 0, 0, 0);
    v6 = KeResetEvent(a2 + 56);
    if ( *(_BYTE *)(a2 + 72) )
      return sub_7F3458(v6);
    KeInitializeEvent(a2 + 56, 0, 0);
    KeInitializeApc(
      a2,
      a1,
      0,
      (int)AlpcMessageDeleteProcedure,
      0,
      (int)IopCancelIrpsInCurrentThreadListApcRoutine,
      0,
      a2);
    if ( KeInsertQueueApc(a2, 0, 0, 0) )
    {
      KeWaitForSingleObject(a2 + 56, 0, 0, 0, 0);
      KeResetEvent(a2 + 56);
    }
  }
  return *(_DWORD *)(a2 + 76);
}
