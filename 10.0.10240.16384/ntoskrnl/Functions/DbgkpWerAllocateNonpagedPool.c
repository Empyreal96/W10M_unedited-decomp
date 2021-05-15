// DbgkpWerAllocateNonpagedPool 
 
int DbgkpWerAllocateNonpagedPool()
{
  return ExAllocatePoolWithTag(512, 16);
}
