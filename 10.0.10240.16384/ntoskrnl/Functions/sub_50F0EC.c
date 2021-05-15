// sub_50F0EC 
 
void sub_50F0EC()
{
  int v0; // r4
  __int16 *v1; // r5

  ExFreePoolWithTag(v0, 0);
  MiReleaseNonPagedResources(v1, 1024);
  JUMPOUT(0x4E6B76);
}
