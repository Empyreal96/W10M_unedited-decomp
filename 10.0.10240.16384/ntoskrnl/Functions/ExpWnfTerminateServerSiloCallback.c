// ExpWnfTerminateServerSiloCallback 
 
int __fastcall ExpWnfTerminateServerSiloCallback(int result, unsigned int *a2)
{
  if ( *a2 )
  {
    ExWnfServerSiloTerminated(result);
    result = ExFreePoolWithTag(*a2);
  }
  return result;
}
