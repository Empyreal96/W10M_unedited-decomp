// WdipSemUpdateProviderEntriesForScenario 
 
int __fastcall WdipSemUpdateProviderEntriesForScenario(int a1)
{
  BOOL v2; // r5
  int result; // r0
  unsigned int v4; // r7
  int v5; // r6

  v2 = *(_DWORD *)(a1 + 52) != 0;
  result = WdipSemUpdateProviderEntryForEvent(a1, v2);
  v4 = 0;
  if ( *(_DWORD *)(a1 + 52) )
  {
    v5 = a1;
    do
    {
      result = WdipSemUpdateProviderEntryForEvent(*(_DWORD *)(v5 + 552), v2);
      ++v4;
      v5 += 4;
    }
    while ( v4 < *(_DWORD *)(a1 + 52) );
  }
  return result;
}
