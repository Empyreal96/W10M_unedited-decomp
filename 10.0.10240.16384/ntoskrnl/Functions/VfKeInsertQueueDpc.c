// VfKeInsertQueueDpc 
 
int __fastcall VfKeInsertQueueDpc(unsigned int a1, int a2, int a3)
{
  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  return pXdvKeInsertQueueDpc(a1, a2, a3);
}
