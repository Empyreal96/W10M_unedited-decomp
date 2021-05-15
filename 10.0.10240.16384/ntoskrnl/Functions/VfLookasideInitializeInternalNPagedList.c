// VfLookasideInitializeInternalNPagedList 
 
int __fastcall VfLookasideInitializeInternalNPagedList(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int16 a7)
{
  return pXdvExInitializeNPagedLookasideList(
           a1,
           a2,
           a3,
           512,
           a5,
           a6,
           a7,
           VfInitializedWithoutReboot,
           ExInitializeNPagedLookasideListInternal);
}
