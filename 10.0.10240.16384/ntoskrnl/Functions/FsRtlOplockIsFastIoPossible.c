// FsRtlOplockIsFastIoPossible 
 
int __fastcall FsRtlOplockIsFastIoPossible(int a1)
{
  int v1; // r3
  int v3; // r2

  v1 = 1;
  if ( !*(_DWORD *)a1 )
    return v1;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 72);
  if ( v3 == 1 )
    return 1;
  if ( (v3 & 0x40) == 0 )
    return 0;
  return sub_7E7164();
}
