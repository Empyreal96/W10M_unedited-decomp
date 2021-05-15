// VfSuspectDriversIsLoaded 
 
BOOL __fastcall VfSuspectDriversIsLoaded(unsigned __int16 *a1)
{
  int v1; // r0

  v1 = ViSuspectDriversLookupEntry(a1);
  return v1 && *(_DWORD *)(v1 + 8) > *(_DWORD *)(v1 + 12);
}
