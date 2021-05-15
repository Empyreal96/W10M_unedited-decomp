// VfGetHookAddressForOriginal 
 
int __fastcall VfGetHookAddressForOriginal(int a1)
{
  int result; // r0

  result = ViLookupThunkArray(&VfXdvThunks, 20, a1);
  if ( !result )
  {
    result = ViLookupThunkArray(&VfPoolThunks, 20, a1);
    if ( !result )
    {
      result = ViLookupThunkArray(&VfMandatoryThunks, 20, a1);
      if ( !result )
      {
        result = ViLookupThunkArray(&VfRegularThunks, 20, a1);
        if ( !result )
          result = ViLookupThunkArray(&VfOrderDependentThunks, 24, a1);
      }
    }
  }
  return result;
}
