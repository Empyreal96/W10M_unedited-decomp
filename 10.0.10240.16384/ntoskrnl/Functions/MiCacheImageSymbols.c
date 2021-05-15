// MiCacheImageSymbols 
 
int __fastcall MiCacheImageSymbols(int a1, int a2, int a3, int a4)
{
  _DWORD v5[3]; // [sp+4h] [bp-Ch] BYREF

  v5[0] = a3;
  v5[1] = a4;
  return RtlImageDirectoryEntryToData(a1, 1, 6, (int)v5);
}
