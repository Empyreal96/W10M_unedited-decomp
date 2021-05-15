// RtlIsAnyDebuggerPresent 
 
BOOL RtlIsAnyDebuggerPresent()
{
  return (MEMORY[0xFFFF92D4] & 3) == 3;
}
