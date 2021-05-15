// sub_52A018 
 
void sub_52A018()
{
  unsigned int v0; // r7
  int v1; // r3

  if ( (MmVerifierData & 0x10) != 0 )
    v1 = 40;
  else
    v1 = 32;
  ExAllocatePoolWithTagPriority(512, v0, 538996553, v1);
  JUMPOUT(0x46937A);
}
