// MmMapMemoryDumpMdl 
 
int __fastcall MmMapMemoryDumpMdl(int a1)
{
  return MmMapMemoryDumpMdlEx(dword_634390 << 10, MiState, a1, 0);
}
