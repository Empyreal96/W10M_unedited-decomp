// PopExtendConnectionState 
 
_BYTE *PopExtendConnectionState()
{
  _BYTE *result; // r0
  int v1; // r6
  unsigned int v2; // r8

  if ( PopMaximumConnectionSessions )
    return (_BYTE *)sub_7F14A4();
  result = (_BYTE *)ExAllocatePoolWithTag(1, 8, 1936020304);
  v1 = (int)result;
  if ( result )
  {
    result = memset(result, 0, 8);
    v2 = PopConnectionState;
    if ( PopConnectionState )
    {
      memmove(v1, PopConnectionState, (unsigned int)PopMaximumConnectionSessions >> 3);
      result = (_BYTE *)ExFreePoolWithTag(v2);
    }
    PopConnectionState = v1;
    PopConnectionBitmap = 64;
    dword_61DE24 = v1;
    PopMaximumConnectionSessions = 64;
  }
  else
  {
    PopMaximumConnectionSessions = 0;
  }
  return result;
}
