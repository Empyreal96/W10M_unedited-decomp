// sub_7C90B8 
 
void sub_7C90B8()
{
  unsigned int *v0; // r6
  unsigned int v1; // r7

  if ( *v0 )
  {
    ExFreePoolWithTag(*v0);
    *v0 = v1;
  }
  JUMPOUT(0x76844A);
}
