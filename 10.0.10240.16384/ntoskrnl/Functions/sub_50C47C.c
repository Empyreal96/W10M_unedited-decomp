// sub_50C47C 
 
void sub_50C47C()
{
  _DWORD *v0; // r6

  if ( !ExfAcquireRundownProtection(v0) )
    JUMPOUT(0x47BFB0);
  JUMPOUT(0x47BFEC);
}
