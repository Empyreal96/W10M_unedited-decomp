// ViMmMapLockedPagesSanityChecks 
 
int __fastcall ViMmMapLockedPagesSanityChecks(int a1, char a2)
{
  int v2; // r5
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r2
  int v10; // r3

  v2 = a2;
  v4 = KeGetCurrentIrql(a1);
  if ( v2 )
  {
    if ( v4 <= 1 )
      goto LABEL_7;
    v5 = 117;
  }
  else
  {
    if ( v4 <= 2 )
      goto LABEL_7;
    v5 = 116;
  }
  VerifierBugCheckIfAppropriate(196, v5, v4, a1, v2);
LABEL_7:
  if ( v2 != 1 )
  {
    v6 = 37;
    v7 = *(__int16 *)(a1 + 6);
    if ( (unsigned int)VfVerifyMode < 3 )
      v6 = 33;
    v8 = v6 & v7;
    if ( v8 )
      VerifierBugCheckIfAppropriate(196, 178, a1, v7, v8);
  }
  v9 = *(__int16 *)(a1 + 6);
  v10 = 18;
  if ( v2 == 1 )
    v10 = 23;
  if ( (v9 & v10) == 0 )
    VerifierBugCheckIfAppropriate(196, 179, a1, v9, v10);
  return MmCheckMdlPages(a1);
}
