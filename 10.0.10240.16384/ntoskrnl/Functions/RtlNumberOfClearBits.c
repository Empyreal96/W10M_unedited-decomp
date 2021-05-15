// RtlNumberOfClearBits 
 
int __fastcall RtlNumberOfClearBits(_DWORD *a1)
{
  return *a1 - RtlNumberOfSetBits();
}
