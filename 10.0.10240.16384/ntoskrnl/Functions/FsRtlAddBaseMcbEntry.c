// FsRtlAddBaseMcbEntry 
 
BOOL __fastcall FsRtlAddBaseMcbEntry(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return FsRtlAddBaseMcbEntryEx(a1, a6, a3, a4) >= 0;
}
