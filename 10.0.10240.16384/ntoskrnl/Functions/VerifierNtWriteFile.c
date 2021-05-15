// VerifierNtWriteFile 
 
int __fastcall VerifierNtWriteFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int vars4; // [sp+34h] [bp+4h]

  if ( (MmVerifierData & 0x10) != 0 && KeGetCurrentIrql(a1) )
    VfErrorReport9(586, vars4);
  return pXdvNtWriteFile(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
