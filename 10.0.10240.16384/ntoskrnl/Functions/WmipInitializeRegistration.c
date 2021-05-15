// WmipInitializeRegistration 
 
__int64 __fastcall WmipInitializeRegistration(__int64 a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r1
  __int64 v4; // [sp+0h] [bp-10h]

  v4 = a1;
  if ( (_DWORD)a1 )
  {
    dword_61B658 = (int)WmipRegistrationWorker;
    dword_61B65C = 0;
    WmipRegWorkQueue = 0;
    __dmb(0xBu);
    do
    {
      v2 = __ldrex((unsigned int *)&WmipRegWorkItemCount);
      v3 = v2 - 1;
    }
    while ( __strex(v3, (unsigned int *)&WmipRegWorkItemCount) );
    __dmb(0xBu);
    if ( v3 )
      ExQueueWorkItem(&WmipRegWorkQueue, 1);
  }
  else
  {
    v4 = 0x52696D5700000020i64;
    ExInitializeNPagedLookasideList((int)&WmipRegLookaside, 0, 0, 512);
    WmipRegistrationSpinLock = 0;
    WmipCancelSpinLock = 0;
  }
  return v4;
}
