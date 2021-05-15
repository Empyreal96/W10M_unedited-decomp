// VerifierObReferenceObjectByHandle 
 
int __fastcall VerifierObReferenceObjectByHandle(int a1, int a2, int a3, char a4)
{
  int v4; // r6
  int v7; // r0
  int v8; // r4
  int v9; // r2
  int v10; // r1

  v4 = a4;
  v7 = pXdvObReferenceObjectByHandle(a1, a2, a3, a4);
  v8 = v7;
  if ( (v7 == -1073741816 || v7 == -1073741788)
    && (!v4 || PsIsSystemThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0))
    && (MmVerifierData & 0x800) != 0 )
  {
    if ( !a1 )
    {
      v9 = 0;
      v10 = 245;
LABEL_14:
      VerifierBugCheckIfAppropriate(196, v10, v9, a3, 0);
      return v8;
    }
    if ( !v4 || a1 >= 0 || a1 == -2 || a1 == -1 )
    {
      v9 = a1;
      v10 = 60;
      goto LABEL_14;
    }
    VerifierBugCheckIfAppropriate(196, 247, a1, a3, v4);
  }
  return v8;
}
