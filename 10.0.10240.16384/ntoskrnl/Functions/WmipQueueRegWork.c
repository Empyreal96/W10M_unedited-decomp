// WmipQueueRegWork 
 
int __fastcall WmipQueueRegWork(int a1, int a2)
{
  int v4; // r5
  unsigned int *v5; // r2
  unsigned int v6; // r4
  int v7; // r0
  void ***v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r1

  v4 = ExAllocatePoolWithTag(1, 16, 1885957463);
  if ( !v4 )
    return -1073741670;
  __dmb(0xBu);
  v5 = (unsigned int *)(a2 + 24);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 + 1, v5) );
  __dmb(0xBu);
  *(_DWORD *)(v4 + 8) = a1;
  *(_DWORD *)(v4 + 12) = a2;
  v7 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v8 = (void ***)off_617538;
  *(_DWORD *)v4 = &WmipRegWorkList;
  *(_DWORD *)(v4 + 4) = v8;
  if ( *v8 != &WmipRegWorkList )
    sub_7EF0A8(v7);
  *v8 = (void **)v4;
  off_617538 = (void **)v4;
  KeReleaseMutex((int)&WmipSMMutex);
  __dmb(0xBu);
  do
  {
    v9 = __ldrex((unsigned int *)&WmipRegWorkItemCount);
    v10 = v9 + 1;
  }
  while ( __strex(v10, (unsigned int *)&WmipRegWorkItemCount) );
  __dmb(0xBu);
  if ( v10 == 1 )
    ExQueueWorkItem(&WmipRegWorkQueue, 1);
  return 0;
}
