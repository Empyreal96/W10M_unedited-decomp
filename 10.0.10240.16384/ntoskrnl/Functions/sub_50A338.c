// sub_50A338 
 
void sub_50A338()
{
  int *v0; // r5
  int v1; // r3

  __dmb(0xBu);
  v1 = *v0;
  __dmb(0xBu);
  if ( (v1 & 2) != 0 )
    __debugbreak();
  JUMPOUT(0x437D08);
}
