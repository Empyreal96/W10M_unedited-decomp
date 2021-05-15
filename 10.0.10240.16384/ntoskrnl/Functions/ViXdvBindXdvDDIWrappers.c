// ViXdvBindXdvDDIWrappers 
 
int __fastcall ViXdvBindXdvDDIWrappers(int (__fastcall *a1)(int))
{
  int v1; // r4
  _DWORD *v2; // r0
  _DWORD *v3; // r5
  unsigned int i; // r4

  ViXdvThunksNoXdvEntry = 0;
  ViXdvThunksBoundToXdv = 0;
  ViXdvThunksNotFound = 0;
  ViXdvThunksNotPristine = 0;
  ViXdvThunksShared = 0;
  if ( !a1 )
    return 0;
  v1 = 0;
  v2 = (_DWORD *)a1(MmVerifyDriverLevel);
  v3 = v2;
  if ( v2 )
  {
    if ( *v2 == 4 )
    {
      for ( i = 0; i < v3[1]; ++i )
      {
        if ( v3[i + 2] )
        {
          if ( !ViXdvSearchAllThunkArrays(i) )
            ++ViXdvThunksNotFound;
        }
        else
        {
          ++ViXdvThunksNoXdvEntry;
        }
      }
      v1 = 1;
    }
    else
    {
      VfUtilDbgPrint((int)"XDV DDI version mismatch: kernel version %d   driver version %d\n");
    }
  }
  return v1;
}
