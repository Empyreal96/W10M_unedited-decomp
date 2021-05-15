// MmMapViewInSessionSpaceEx 
 
int __fastcall MmMapViewInSessionSpaceEx(int a1, int a2, int a3)
{
  int v3; // r5
  int result; // r0

  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (*(_DWORD *)(v3 + 192) & 0x10000) != 0 )
    result = MiMapViewInSystemSpace(a1, *(_DWORD *)(v3 + 324) + 3200, a2, a3);
  else
    result = -1073741799;
  return result;
}
