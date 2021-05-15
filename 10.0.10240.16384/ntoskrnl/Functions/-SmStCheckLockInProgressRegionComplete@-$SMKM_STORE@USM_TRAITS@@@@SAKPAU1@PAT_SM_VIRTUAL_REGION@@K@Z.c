// -SmStCheckLockInProgressRegionComplete@-$SMKM_STORE@USM_TRAITS@@@@SAKPAU1@PAT_SM_VIRTUAL_REGION@@K@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStCheckLockInProgressRegionComplete(int a1, int a2)
{
  if ( *(_DWORD *)(a1 + 3864) != a2 )
    return 1;
  if ( SmKmStoreHelperCheckWaitCommand(a1 + 3740) == -1073741536 )
  {
    *(_DWORD *)(a1 + 3864) = 0;
    return 1;
  }
  return 0;
}
