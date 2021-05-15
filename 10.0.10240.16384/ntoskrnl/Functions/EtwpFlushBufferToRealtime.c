// EtwpFlushBufferToRealtime 
 
int __fastcall EtwpFlushBufferToRealtime(int a1, int a2, int a3)
{
  int result; // r0

  if ( !*(_DWORD *)(a1 + 264) || *(_DWORD *)(a1 + 328) || (result = EtwpRealtimeDeliverBuffer(a1, a2), result < 0) )
  {
    if ( a3 )
      return sub_809E8C();
    result = EtwpRealtimeSaveBuffer(a1, a2);
  }
  else if ( a3 )
  {
    return sub_809E8C();
  }
  return result;
}
