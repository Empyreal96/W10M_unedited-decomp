// PoNotifyVSyncChange 
 
int __fastcall PoNotifyVSyncChange(char a1)
{
  int v2; // r0

  v2 = PpmAcquireLock(&PopFxSystemLatencyLock);
  PopFxVSyncEnabled = a1;
  PoFxSendSystemLatencyUpdate(v2);
  return PpmReleaseLock(&PopFxSystemLatencyLock);
}
