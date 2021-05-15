// FsRtlRemoveMcbEntry 
 
int __fastcall FsRtlRemoveMcbEntry(unsigned int **a1, int a2)
{
  return FsRtlRemoveLargeMcbEntry(a1, a2, a2, 0);
}
