// MiRemoveLockedPageChargeAndDecRef 
 
int __fastcall MiRemoveLockedPageChargeAndDecRef(int a1)
{
  if ( !MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(a1) )
    return 0;
  MiPfnReferenceCountIsZero(a1, (a1 - MmPfnDatabase) / 24);
  return 1;
}
