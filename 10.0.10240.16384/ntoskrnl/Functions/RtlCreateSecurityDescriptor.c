// RtlCreateSecurityDescriptor 
 
int __fastcall RtlCreateSecurityDescriptor(_BYTE *a1, int a2)
{
  if ( a2 != 1 )
    return -1073741736;
  memset(a1, 0, 20);
  *a1 = 1;
  return 0;
}
