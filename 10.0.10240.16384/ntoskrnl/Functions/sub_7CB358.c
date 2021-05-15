// sub_7CB358 
 
void sub_7CB358()
{
  unsigned int v0; // r4
  _DWORD *v1; // r6
  int v2; // r3

  if ( (*v1 & 0x10) != 0 )
    v2 = 40;
  else
    v2 = 32;
  ExAllocatePoolWithTagPriority(1, v0, 538996553, v2);
  JUMPOUT(0x76C96C);
}
