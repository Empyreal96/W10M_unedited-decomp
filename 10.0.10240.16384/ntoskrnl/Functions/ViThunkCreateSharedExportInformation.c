// ViThunkCreateSharedExportInformation 
 
int __fastcall ViThunkCreateSharedExportInformation(int a1, int a2, int a3, _DWORD *a4, int *a5)
{
  int v9; // r4
  int v10; // r0
  int v11; // r0

  v9 = 1;
  v10 = RtlNumberOfClearBits(a4);
  if ( v10 )
  {
    v11 = ExAllocatePoolWithTag(512, 8 * v10, 1414096470);
    *a5 = v11;
    if ( v11 )
    {
      if ( !ViThunkSnapSharedExports(a1, a2, a3, a4) )
        ViThunkFreeSharedThunksArray(a5);
    }
    else
    {
      v9 = 0;
    }
  }
  else
  {
    *a5 = 0;
  }
  return v9;
}
