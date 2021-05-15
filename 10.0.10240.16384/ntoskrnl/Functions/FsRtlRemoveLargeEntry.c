// FsRtlRemoveLargeEntry 
 
int __fastcall FsRtlRemoveLargeEntry(int result, int a2, int a3)
{
  int v3; // r5
  unsigned int v4; // r3
  unsigned int v7; // r1

  v3 = result;
  v4 = *(_DWORD *)(result + 4);
  v7 = a2 + a3;
  if ( v7 < v4 )
    result = memmove(*(_DWORD *)(result + 12) + 8 * a2, *(_DWORD *)(result + 12) + 8 * v7, 8 * (v4 - a2 - a3));
  *(_DWORD *)(v3 + 4) -= a3;
  return result;
}
