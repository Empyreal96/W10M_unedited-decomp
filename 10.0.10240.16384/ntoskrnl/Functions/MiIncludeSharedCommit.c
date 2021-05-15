// MiIncludeSharedCommit 
 
BOOL __fastcall MiIncludeSharedCommit(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 28);
  return (v1 & 0x20) != 0 || (v1 & 0x400) == 0 && a1 != dword_632EEC && !*(_DWORD *)(a1 + 32);
}
