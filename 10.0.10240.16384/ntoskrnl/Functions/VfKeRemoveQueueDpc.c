// VfKeRemoveQueueDpc 
 
int __fastcall VfKeRemoveQueueDpc(unsigned int a1)
{
  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  return pXdvKeRemoveQueueDpc(a1);
}
