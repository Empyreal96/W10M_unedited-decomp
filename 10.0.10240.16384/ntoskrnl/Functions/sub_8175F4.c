// sub_8175F4 
 
void sub_8175F4()
{
  unsigned int *v0; // r5

  if ( *v0 )
  {
    ExFreePoolWithTag(*v0);
    *v0 = 0;
  }
  JUMPOUT(0x7AF9EE);
}
