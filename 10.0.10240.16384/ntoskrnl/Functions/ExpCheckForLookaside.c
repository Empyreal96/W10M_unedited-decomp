// ExpCheckForLookaside 
 
int __fastcall ExpCheckForLookaside(int a1, int a2)
{
  int result; // r0

  if ( (MmVerifierData & 0x800) == 0 || (result = VfCheckForLookaside()) == 0 )
  {
    ExpCheckForLookasideList(a1, a2, &ExNPagedLookasideListHead, &ExNPagedLookasideLock);
    result = ExpCheckForLookasideList(a1, a2, &ExPagedLookasideListHead, &ExPagedLookasideLock);
  }
  return result;
}
