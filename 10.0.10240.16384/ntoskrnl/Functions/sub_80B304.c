// sub_80B304 
 
void sub_80B304()
{
  int v0; // r4

  CmpWaitOnHiveWriteQueue(v0, v0 + 3300, 0);
  JUMPOUT(0x78F226);
}
