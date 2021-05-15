// EtwpRealtimeDisconnectAllConsumers 
 
int __fastcall EtwpRealtimeDisconnectAllConsumers(int result)
{
  if ( *(_DWORD *)(result + 256) != result + 256 )
    result = sub_7EEF50();
  return result;
}
