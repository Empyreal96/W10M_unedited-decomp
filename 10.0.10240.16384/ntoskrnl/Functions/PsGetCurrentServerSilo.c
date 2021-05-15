// PsGetCurrentServerSilo 
 
int PsGetCurrentServerSilo()
{
  int result; // r0

  if ( (unsigned int)KeGetCurrentIrql() < 2 )
    result = PspGetThreadServerSilo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  else
    result = sub_517420();
  return result;
}
