// FsRtlCheckOplock 
 
int __fastcall FsRtlCheckOplock(_DWORD *a1, int a2, int a3)
{
  int v6; // r7
  int v8; // r2
  int v9; // r3

  v6 = 0;
  FsRtlpOplockStoreKeyForDeleteOperation(a1, a2, 0);
  if ( !*a1 && (!a2 || **(_BYTE **)(a2 + 96)) )
    return 0;
  v8 = *(_DWORD *)(a2 + 96);
  if ( !*(_BYTE *)v8 )
  {
    v9 = *(_DWORD *)(v8 + 12);
    if ( (v9 & 0x100) != 0 )
      v6 = 1;
    if ( (v9 & 0x10000) != 0 )
      v6 |= 0x10000000u;
  }
  return FsRtlCheckOplockEx(a1, a2, v6, a3);
}
