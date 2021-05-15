// KeSynchronizeWithDynamicProcessors 
 
int KeSynchronizeWithDynamicProcessors()
{
  int result; // r0

  if ( KeDynamicPartitioningSupported )
    result = sub_7E8190();
  return result;
}
