// IopCancelWaitCompletionPacket 
 
int __fastcall IopCancelWaitCompletionPacket(int a1, int a2, int a3)
{
  int v4; // r7
  int v7; // r0
  int v8; // r0
  int v9; // r6

  v4 = *(_DWORD *)(a1 + 40);
  v7 = ObGetAssociatedWaitObject(v4);
  v8 = KeDeregisterObjectNotification(v7, a1);
  v9 = *(_DWORD *)(a1 + 44);
  if ( !v8 && (!a2 || !KeRemoveQueueEntry(*(_DWORD *)(a1 + 44), a1)) )
    return 0;
  __dmb(0xBu);
  *(_BYTE *)(a1 + 52) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_52B064();
  __dmb(0xBu);
  *(_DWORD *)(a1 + 48) = 0;
  KfLowerIrql(a3);
  ObfDereferenceObjectWithTag(v4);
  ObfDereferenceObjectWithTag(v9);
  ObfDereferenceObjectWithTag(a1);
  return 1;
}
