// ViMmValidateIrql 
 
unsigned int __fastcall ViMmValidateIrql(unsigned int result)
{
  if ( !result )
  {
    result = KeGetCurrentIrql(0);
    if ( result > 2 )
      result = VerifierBugCheckIfAppropriate(196, 126, result, 2, 0);
  }
  return result;
}
