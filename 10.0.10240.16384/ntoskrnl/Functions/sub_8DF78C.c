// sub_8DF78C 
 
void sub_8DF78C()
{
  unsigned int v0; // r5
  unsigned int v1; // r0

  BgpFwReleaseLock();
  v1 = ExFreePoolWithTag(v0);
  BgpFwAcquireLock(v1);
  JUMPOUT(0x8DDD86);
}
