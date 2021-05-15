// VfTriageActionTaken 
 
int VfTriageActionTaken()
{
  int v0; // r4

  v0 = VerifierTriageActionTaken;
  if ( MEMORY[0xFFFF9264] != 1 || ExVerifySuite(6) || ExVerifySuite(11) || ExVerifySuite(12) )
    v0 |= 0x80000000;
  return v0;
}
