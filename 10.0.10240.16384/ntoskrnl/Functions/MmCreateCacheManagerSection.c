// MmCreateCacheManagerSection 
 
int __fastcall MmCreateCacheManagerSection(int a1, int a2, int a3, int a4)
{
  int v7; // r5
  int v8; // r4
  int v9; // r0

  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 == 1 )
    v8 = *(unsigned __int8 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 733);
  else
    v8 = 0;
  v9 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  return MiCreateSection(a1, 0, 2, a2, 4, 0x8000000, v8, 0, a4, v7, v9);
}
