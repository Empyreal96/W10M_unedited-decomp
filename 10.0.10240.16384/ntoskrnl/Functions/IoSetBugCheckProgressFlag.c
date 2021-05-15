// IoSetBugCheckProgressFlag 
 
int __fastcall IoSetBugCheckProgressFlag(int result)
{
  if ( CrashdmpDumpBlock )
  {
    *(_DWORD *)(CrashdmpDumpBlock + 528) |= result;
    if ( !BugCheckProgressEFICalled )
    {
      BugCheckProgressEFICalled = 1;
      result = IopReportBugCheckProgress(L"BugCheckProgress", BUGCHECK_EFI_GUID, CrashdmpDumpBlock + 528, 4, 1);
      BugCheckProgressEFICalled = 0;
    }
  }
  return result;
}
