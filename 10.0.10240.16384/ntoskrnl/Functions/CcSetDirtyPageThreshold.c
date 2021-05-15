// CcSetDirtyPageThreshold 
 
int __fastcall CcSetDirtyPageThreshold(int result, int a2)
{
  int v2; // r3
  int v3; // r2

  v2 = *(_DWORD *)(*(_DWORD *)(result + 20) + 4);
  if ( v2 )
    *(_DWORD *)(v2 + 168) = a2;
  v3 = *(_DWORD *)(result + 12);
  if ( (*(_BYTE *)(v3 + 4) & 4) == 0 )
    *(_BYTE *)(v3 + 4) |= 4u;
  return result;
}
