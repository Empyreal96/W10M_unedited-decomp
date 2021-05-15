// sub_81BC28 
 
void sub_81BC28()
{
  unsigned __int64 *v0; // r3
  unsigned __int64 v1; // r0
  unsigned int *v2; // r1
  unsigned int v3; // r0

  v0 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
  do
    v1 = __ldrexd(v0);
  while ( __strexd(v1 + 1, v0) );
  v2 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + 1, v2) );
  JUMPOUT(0x7BBDAA);
}
