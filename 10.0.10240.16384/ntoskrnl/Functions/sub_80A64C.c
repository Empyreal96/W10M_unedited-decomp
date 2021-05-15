// sub_80A64C 
 
void sub_80A64C()
{
  int v0; // r4

  if ( !ExAllocatePoolWithTag(1, 48, 2001495379) )
  {
    if ( v0 )
      PspDereferenceSiloObject(v0);
    JUMPOUT(0x75FF72);
  }
  JUMPOUT(0x75FF44);
}
