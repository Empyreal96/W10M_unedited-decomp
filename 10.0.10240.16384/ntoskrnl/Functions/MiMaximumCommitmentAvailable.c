// MiMaximumCommitmentAvailable 
 
int MiMaximumCommitmentAvailable()
{
  int result; // r0

  if ( dword_640604 > (unsigned int)dword_640384 )
    result = 0;
  else
    result = dword_640384 - dword_640604;
  return result;
}
