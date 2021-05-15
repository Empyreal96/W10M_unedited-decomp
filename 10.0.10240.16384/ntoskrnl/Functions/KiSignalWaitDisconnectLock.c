// KiSignalWaitDisconnectLock 
 
int __fastcall KiSignalWaitDisconnectLock(unsigned int a1, int a2)
{
  int result; // r0

  if ( a2 )
    result = KeWaitForSingleObject(a1, 0, 0, 0, 0);
  else
    result = KeSetEvent(a1, 0, 0);
  return result;
}
