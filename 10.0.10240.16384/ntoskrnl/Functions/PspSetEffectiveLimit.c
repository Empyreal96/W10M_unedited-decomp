// PspSetEffectiveLimit 
 
BOOL __fastcall PspSetEffectiveLimit(int a1, _DWORD *a2)
{
  return !a2 || (*(_DWORD *)(*a2 + 176) & a1) != 0 || (a2[2] & a1) != 0;
}
