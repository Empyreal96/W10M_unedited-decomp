// sub_5224DC 
 
void sub_5224DC()
{
  int v0; // r3

  if ( (MmVerifierData & 0x10) != 0 )
    v0 = 40;
  else
    v0 = 32;
  ExAllocatePoolWithTagPriority(512, 0x34u, 538996553, v0);
  JUMPOUT(0x456DC0);
}
