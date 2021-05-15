// MiSectionOpen 
 
int __fastcall MiSectionOpen(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r1

  v4 = MiSectionControlArea(a4);
  return MiInsertSharedCommitNode(v4, v5, 0);
}
