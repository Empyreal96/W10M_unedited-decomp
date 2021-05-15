// KeCopyAffinityEx 
 
_DWORD *__fastcall KeCopyAffinityEx(_DWORD *a1, _DWORD *a2)
{
  int v2; // r3
  int v3; // r4

  v2 = a2[1];
  v3 = a2[2];
  *a1 = *a2;
  a1[1] = v2;
  a1[2] = v3;
  return a1 + 3;
}
