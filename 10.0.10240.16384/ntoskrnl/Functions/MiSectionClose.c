// MiSectionClose 
 
int __fastcall MiSectionClose(int a1, int a2)
{
  int v2; // r0
  int v3; // r1

  v2 = MiSectionControlArea(a2);
  return MiRemoveSharedCommitNode(v2, v3, 0);
}
