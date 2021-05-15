// FsRtlWorkerThread 
 
void __fastcall __noreturn FsRtlWorkerThread(int a1, int a2, int *a3, int *a4)
{
  int v5; // r0
  int *v6[8]; // [sp+8h] [bp-20h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  KeSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, a1 + 16);
  do
  {
    KeRemoveQueueEx((int)&FsRtlWorkerQueues + 40 * a1, 0, 0, 0, v6, 1u);
    v5 = (*((int (__fastcall **)(int))v6[0] + 2))(v6[0][3]);
  }
  while ( !KeGetCurrentIrql(v5) );
  sub_55567C();
}
