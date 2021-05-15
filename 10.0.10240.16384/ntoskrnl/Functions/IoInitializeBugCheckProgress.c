// IoInitializeBugCheckProgress 
 
int __fastcall IoInitializeBugCheckProgress(int result, int a2)
{
  int vars8; // [sp+20h] [bp+8h] BYREF
  int varsC; // [sp+24h] [bp+Ch] BYREF

  vars8 = result;
  varsC = a2;
  if ( CrashdmpDumpBlock )
  {
    *(_DWORD *)(CrashdmpDumpBlock + 528) = 0;
    result = off_617B48();
    if ( result == 1 || vars8 == 265 )
    {
      BugCheckProgressEFICalled = 1;
    }
    else if ( !BugCheckProgressEFICalled )
    {
      BugCheckProgressEFICalled = 1;
      IopReportBugCheckProgress(L"BugCheckCode", BUGCHECK_EFI_GUID, &vars8, 4, 1);
      result = IopReportBugCheckProgress(L"BugCheckParameter1", BUGCHECK_EFI_GUID, &varsC, 4, 1);
      BugCheckProgressEFICalled = 0;
    }
  }
  return result;
}
