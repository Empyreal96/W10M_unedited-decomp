// AdtpPermissionBitPosition 
 
int __fastcall AdtpPermissionBitPosition(unsigned int a1)
{
  int v1; // r3
  unsigned int i; // r2

  v1 = 0;
  for ( i = a1 >> 1; i; i >>= 1 )
    v1 = (unsigned __int8)(v1 + 1);
  return v1;
}
