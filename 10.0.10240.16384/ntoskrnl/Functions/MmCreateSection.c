// MmCreateSection 
 
int __fastcall MmCreateSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v11; // r7
  int v12; // r4
  int v13; // r5
  int v14; // r0

  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v11 == 1 )
    v12 = *(unsigned __int8 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 733);
  else
    v12 = 0;
  v13 = 0;
  if ( a8 )
    v13 = 2;
  v14 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  return MiCreateSection(a1, a3, v13, a4, a5, a6, v12, a7, a8, v11, v14);
}
