// sub_7C8D70 
 
void sub_7C8D70()
{
  unsigned int *v0; // r10

  if ( *v0 )
  {
    ExFreePoolWithTag(*v0);
    *v0 = 0;
  }
  JUMPOUT(0x76799A);
}
