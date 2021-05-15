// MmGetSystemPageCounts 
 
_DWORD *__fastcall MmGetSystemPageCounts(_DWORD *a1)
{
  int v1; // r2
  int v2; // r3
  int v3; // r4

  v1 = dword_632F54;
  v2 = *(_DWORD *)algn_632F58;
  v3 = *(_DWORD *)&algn_632F58[4];
  *a1 = dword_632F50;
  a1[1] = v1;
  a1[2] = v2;
  a1[3] = v3;
  return a1 + 4;
}
