// PfSnIsSectionPrefetchedAfterPhase 
 
BOOL __fastcall PfSnIsSectionPrefetchedAfterPhase(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r3
  int v4; // r3
  unsigned int v5; // r3
  BOOL v6; // r3

  v3 = *(_DWORD *)(a1 + 20);
  if ( a2 == 1 )
    v4 = (v3 >> 8) & 0x7F;
  else
    v4 = (unsigned __int8)v3 >> 1;
  v5 = __clz(v4);
  if ( 1 == (unsigned __int8)(v5 >> 5) )
    v6 = 0;
  else
    v6 = 31 - v5 > 31 - __clz(a3);
  return v6;
}
