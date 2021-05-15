// sub_5380C4 
 
void __fastcall sub_5380C4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32)
{
  int v32; // r4
  int v33; // r8

  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v33 + 36), a32);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v33 + 36) = 0;
  }
  KfLowerIrql(v32);
  JUMPOUT(0x496186);
}
