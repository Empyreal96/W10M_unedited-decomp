// PspCatchCriticalBreak 
 
void PspCatchCriticalBreak(const char *a1, _BYTE *a2, ...)
{
  if ( KdDebuggerEnabled )
  {
    DbgPrintEx(0, 0, (int)a1, (int)a2);
    if ( !KdDebuggerNotPresent )
      DbgPrompt((unsigned int)"Break, or Ignore (bi)? ");
  }
  KeBugCheckEx(239, (int)a2, (*a2 & 0x7F) == 6, 0, 0);
}
