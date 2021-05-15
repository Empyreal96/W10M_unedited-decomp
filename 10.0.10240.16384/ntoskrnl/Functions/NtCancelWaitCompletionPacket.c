// NtCancelWaitCompletionPacket 
 
int __fastcall NtCancelWaitCompletionPacket(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r5
  int v7; // r7
  unsigned int *v8; // r4
  int v9; // r8
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r1
  int v15; // r3
  int v16[8]; // [sp+8h] [bp-20h] BYREF

  v16[0] = a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 1, IopWaitCompletionPacketObjectType, v5, v16, 0);
  if ( v6 < 0 )
    return v6;
  v7 = v16[0];
  v8 = (unsigned int *)(v16[0] + 48);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52B044();
  do
    v11 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForSpinLockAndAcquire(v8);
  v12 = *(unsigned __int8 *)(v7 + 52);
  __dmb(0xBu);
  if ( !v12 )
  {
    v6 = -1073741536;
LABEL_9:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v8);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    KfLowerIrql(v9);
    v13 = v16[0];
    goto LABEL_12;
  }
  v14 = a2;
  v13 = v16[0];
  if ( !IopCancelWaitCompletionPacket(v16[0], v14, v9) )
  {
    v15 = *(unsigned __int8 *)(v7 + 52);
    __dmb(0xBu);
    if ( v15 )
      v6 = 259;
    goto LABEL_9;
  }
LABEL_12:
  ObfDereferenceObjectWithTag(v13);
  return v6;
}
