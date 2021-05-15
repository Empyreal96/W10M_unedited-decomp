// VerifierMmFreeContiguousMemory 
 
int __fastcall VerifierMmFreeContiguousMemory(int a1, int a2, int a3)
{
  int vars4; // [sp+Ch] [bp+4h]

  if ( dword_61D2B8 )
    ViTargetFreeContiguousMemory(vars4, a1, a3, dword_61D2B8);
  return pXdvMmFreeContiguousMemory(a1);
}
