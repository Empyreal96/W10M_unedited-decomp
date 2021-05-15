// ViExCheckAPCsDisabled 
 
int __fastcall ViExCheckAPCsDisabled(int a1, int a2)
{
  int v4; // r0
  int v5; // r4

  v4 = KeGetCurrentIrql(a1);
  v5 = v4;
  if ( v4 != 1
    && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) == 0
    && !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
  {
    VerifierBugCheckIfAppropriate(196, a1, v4, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134), a2);
  }
  return v5;
}
