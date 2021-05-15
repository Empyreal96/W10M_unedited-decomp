// CcBuildUpHighPriorityMappings 
 
int __fastcall CcBuildUpHighPriorityMappings(int result)
{
  int v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r5
  int *v4; // r6

  v1 = result;
  if ( CcNumberOfFreeHighPriorityVacbs < (unsigned int)CcMinimumFreeHighPriorityVacbs )
  {
    v2 = CcMinimumFreeHighPriorityVacbs - CcNumberOfFreeHighPriorityVacbs;
    if ( CcMinimumFreeHighPriorityVacbs - CcNumberOfFreeHighPriorityVacbs <= (unsigned int)CcMinimumFreeHighPriorityVacbs )
    {
      v3 = 0;
      if ( v2 )
      {
        v4 = (int *)(result + 16);
        do
        {
          if ( v3 >= 0x1554 )
            break;
          result = MmReserveViewInSystemCache();
          *v4 = result;
          v4 += 6;
          if ( !result )
            break;
          ++v3;
          ++*(_DWORD *)(v1 + 4);
        }
        while ( v3 < v2 );
      }
    }
  }
  return result;
}
