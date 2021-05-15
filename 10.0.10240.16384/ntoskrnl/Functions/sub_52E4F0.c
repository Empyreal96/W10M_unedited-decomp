// sub_52E4F0 
 
void sub_52E4F0()
{
  _DWORD *v0; // r6

  if ( !ExfAcquireRundownProtection(v0) )
    JUMPOUT(0x47BF04);
  JUMPOUT(0x47BF3E);
}
