// PopInitializeAdpm 
 
_BYTE *PopInitializeAdpm()
{
  ExInitializeResourceLite((int)&PopAdpmLock);
  memset(&PopConsoleContext, 0, 40);
  PopConsoleContext = -1;
  dword_61DE60 = 3;
  PopMaximumConnectionSessions = 0;
  PopConnectionState = 0;
  return PopExtendConnectionState();
}
