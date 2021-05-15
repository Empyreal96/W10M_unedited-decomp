// PfSnAsyncPrefetchStep 
 
int __fastcall PfSnAsyncPrefetchStep(int a1, int a2, int a3)
{
  int result; // r0

  PfSnPrefetchMetadata(a2, a3);
  result = PfSnPrefetchSections(a2, 0, a3);
  if ( result >= 0 )
  {
    result = PfSnPrefetchSections(a2, 1, a3);
    if ( result >= 0 )
    {
      *(_DWORD *)(a1 + 140) |= a3;
      result = 0;
    }
  }
  return result;
}
