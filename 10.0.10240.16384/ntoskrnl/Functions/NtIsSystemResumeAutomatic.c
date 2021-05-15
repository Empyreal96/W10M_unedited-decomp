// NtIsSystemResumeAutomatic 
 
BOOL NtIsSystemResumeAutomatic()
{
  return (PopFullWake & 3) == 0;
}
