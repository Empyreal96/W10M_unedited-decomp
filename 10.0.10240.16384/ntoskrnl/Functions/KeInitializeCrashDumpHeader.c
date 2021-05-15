// KeInitializeCrashDumpHeader 
 
int __fastcall KeInitializeCrashDumpHeader(int a1, int a2, int a3, unsigned int a4, _DWORD *a5)
{
  if ( a5 )
    *a5 = 4096;
  if ( a1 != 1 )
    return -1073741585;
  if ( a2 )
    return -1073741584;
  if ( a4 < 0x1000 )
    return -1073741582;
  __mrc(15, 0, 13, 0, 3);
  IoFillDumpHeader(a3, 1, 0);
  return 0;
}
