// MiInitializeCrashDumpPtes 
 
int MiInitializeCrashDumpPtes()
{
  int result; // r0

  result = MiReservePtes(&dword_634D58, 0x20u);
  dword_634390 = result;
  return result;
}
