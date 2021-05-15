// PfSnPrefetchFileMetadata 
 
int __fastcall PfSnPrefetchFileMetadata(int a1, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  unsigned int v9; // r6
  int v10; // r3
  int result; // r0
  int v12[10]; // [sp+28h] [bp-28h] BYREF

  if ( !a5 )
    return 0;
  v9 = *(_DWORD *)(a3 + 4);
  if ( v9 <= a4 || v9 - a4 < a5 )
    return -1073741701;
  v10 = *(_DWORD *)(a1 + 124) & 7 | (8 * (*(_DWORD *)(a1 + 128) & 7 | 8));
  if ( a4 || a5 > 0x300 )
    return sub_7E64B0(0);
  *(_DWORD *)(a3 + 4) = a5;
  *(_DWORD *)(a3 + 8) = v10;
  NtResetEvent(a6, 0);
  result = NtFsControlFile(a2, a6, 0, 0, v12, 590112, a3, 8 * (a5 + 2), 0, 0);
  if ( result == 259 )
  {
    NtWaitForSingleObject(a6, 0, 0);
    result = v12[0];
  }
  *(_DWORD *)(a3 + 4) = v9;
  return result;
}
