// FsRtlAddMcbEntry 
 
int __fastcall FsRtlAddMcbEntry(unsigned int **a1, int a2, int a3, int a4)
{
  return FsRtlAddLargeMcbEntry(a1, a2, a2, 0, a3, 0, a4, 0);
}
