// sub_7C2F40 
 
void sub_7C2F40()
{
  int v0; // r4

  LOCK_HIVE_LOAD();
  CmpLockRegistry();
  if ( *(_BYTE *)(*(_DWORD *)(v0 + 20) + 2532) == 1 )
  {
    CmpDereferenceKeyControlBlock((unsigned int *)v0);
    CmpDoQueueLateUnloadWorker(*(_DWORD *)(v0 + 20));
  }
  else
  {
    CmpDereferenceKeyControlBlock((unsigned int *)v0);
  }
  CmpUnlockRegistry();
  UNLOCK_HIVE_LOAD();
  JUMPOUT(0x6B1E60);
}
