// VerifierIoInitializeWorkItem 
 
int __fastcall VerifierIoInitializeWorkItem(int a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v4 = IoSizeofWorkItem();
  if ( a2 < MmHighestUserAddress || v4 + a2 < a2 )
    VerifierBugCheckIfAppropriate(196, 224, a2);
  if ( MmIsSessionAddress(a2) )
    VerifierBugCheckIfAppropriate(196, 304, a2);
  if ( (MmVerifierData & 2) != 0 && !MmIsNonPagedSystemAddressValid(a2, v5, v6) )
    VerifierBugCheckIfAppropriate(196, 305, a2);
  return pXdvIoInitializeWorkItem(a1, a2);
}
