// sub_7C6A24 
 
void sub_7C6A24()
{
  unsigned int *v0; // r5
  unsigned int v1; // r8

  if ( *v0 )
  {
    ExFreePoolWithTag(*v0);
    *v0 = v1;
  }
  JUMPOUT(0x6C91AA);
}
