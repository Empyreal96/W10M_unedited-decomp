// IopDisableCrashDump 
 
int IopDisableCrashDump()
{
  int result; // r0

  result = 0;
  if ( CrashdmpImageEntry && dword_63765C && CrashdmpInitialized )
  {
    result = dword_63765C(0);
    if ( result >= 0 )
    {
      CrashdmpInitialized = 0;
      CrashdmpDumpBlock = 0;
    }
  }
  return result;
}
