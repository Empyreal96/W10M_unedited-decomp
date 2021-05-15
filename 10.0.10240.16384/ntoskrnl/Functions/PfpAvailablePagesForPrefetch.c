// PfpAvailablePagesForPrefetch 
 
BOOL __fastcall PfpAvailablePagesForPrefetch(_DWORD *a1, unsigned int a2)
{
  return (unsigned int)(*a1 + PfpGetPageListCount((int)(a1 + 5), 0, a2) + a1[1]) >= 0x80;
}
