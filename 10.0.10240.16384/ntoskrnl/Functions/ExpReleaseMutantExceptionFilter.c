// ExpReleaseMutantExceptionFilter 
 
BOOL __fastcall ExpReleaseMutantExceptionFilter(int a1)
{
  return *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && (a1 == 128 || a1 == -1073741754);
}
