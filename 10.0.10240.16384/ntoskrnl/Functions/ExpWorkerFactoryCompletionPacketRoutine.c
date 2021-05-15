// ExpWorkerFactoryCompletionPacketRoutine 
 
int __fastcall ExpWorkerFactoryCompletionPacketRoutine(int a1, int a2)
{
  int v3; // r0
  int v4; // r5
  bool v5; // zf
  int result; // r0
  int v7; // r0
  unsigned int *v8; // r1
  int *v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12[2]; // [sp+10h] [bp-20h] BYREF
  unsigned __int8 v13; // [sp+18h] [bp-18h]

  v3 = KeAcquireInStackQueuedSpinLock((unsigned int *)a2, (unsigned int)v12);
  v4 = 0;
  if ( *(_BYTE *)(a2 + 22) )
  {
    v4 = 2;
  }
  else
  {
    if ( *(_BYTE *)(a2 + 21) )
      v5 = *(_DWORD *)(a2 + 16) == 0;
    else
      v5 = (*(_DWORD *)(a2 + 12))-- == 1;
    if ( !v5 )
    {
      v4 = 1;
      goto LABEL_7;
    }
  }
  *(_BYTE *)(a2 + 20) = 0;
LABEL_7:
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_54B5D4(v3);
  v7 = v12[0];
  if ( !v12[0] )
  {
    v8 = (unsigned int *)v12[1];
    __dmb(0xBu);
    do
      v9 = (int *)__ldrex(v8);
    while ( v9 == v12 && __strex(0, v8) );
    if ( v9 == v12 )
      goto LABEL_14;
    v7 = KxWaitForLockChainValid(v12);
  }
  v12[0] = 0;
  __dmb(0xBu);
  v10 = (unsigned int *)(v7 + 4);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 ^ 1, v10) );
LABEL_14:
  result = KfLowerIrql(v13);
  if ( v4 == 1 )
    return IoSetIoCompletionEx(*(_DWORD *)(a2 + 4), 0, 0, 0);
  if ( v4 == 2 )
  {
    IoFreeMiniCompletionPacket(*(_DWORD *)(a2 + 8));
    result = ExFreePoolWithTag(a2, 0);
  }
  return result;
}
