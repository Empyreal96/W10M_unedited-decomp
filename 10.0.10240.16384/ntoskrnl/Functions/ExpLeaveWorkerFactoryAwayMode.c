// ExpLeaveWorkerFactoryAwayMode 
 
int __fastcall ExpLeaveWorkerFactoryAwayMode(int result)
{
  int v1; // r4

  v1 = result;
  if ( (*(_DWORD *)(result + 88) & 0x400) != 0 )
  {
    result = KeDeregisterObjectNotification(*(_DWORD *)(*(_DWORD *)(result + 4) + 4), result + 220);
    if ( result )
    {
      result = ObfDereferenceObjectWithTag(v1);
      *(_DWORD *)(v1 + 88) &= 0xFFFFFBFF;
    }
  }
  *(_DWORD *)(v1 + 88) &= 0xFFFFFDFF;
  return result;
}
