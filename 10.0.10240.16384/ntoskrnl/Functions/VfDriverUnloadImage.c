// VfDriverUnloadImage 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfDriverUnloadImage(int a1)
{
  int result; // r0
  int *v3; // r6
  unsigned int v4; // r9
  int *v5; // r1 OVERLAPPED
  int **v6; // r2 OVERLAPPED

  if ( VfIsVerifierEnabled() )
    return sub_8E51AC();
  if ( ViActiveVerifierThunks )
  {
    ViThunkRemoveImportEntry(&ViVerifierDriverAddedThunkListHead, a1);
    v3 = (int *)ViVerifierDriverAddedSpecialThunkListHead;
    while ( v3 != &ViVerifierDriverAddedSpecialThunkListHead )
    {
      v4 = (unsigned int)v3;
      ViThunkRemoveImportEntry(v3 + 3, a1);
      if ( (int *)v3[3] == v3 + 3 )
      {
        *(_QWORD *)&v5 = *(_QWORD *)v3;
        if ( *(int **)(*v3 + 4) != v3 || *v6 != v3 )
          __fastfail(3u);
        *v6 = v5;
        v5[1] = (int)v6;
        v3 = (int *)*v3;
        ExFreePoolWithTag(v4);
        --ViVerifierSpecialThunkTables;
      }
      else
      {
        v3 = (int *)*v3;
      }
    }
  }
  result = VfTargetDriversRemove(a1);
  if ( (*(_DWORD *)(a1 + 52) & 0x2000000) != 0 )
    result = VfSuspectDriversUnloadCallback(a1);
  return result;
}
