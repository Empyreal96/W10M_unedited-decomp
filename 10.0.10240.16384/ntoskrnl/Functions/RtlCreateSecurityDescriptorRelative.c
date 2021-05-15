// RtlCreateSecurityDescriptorRelative 
 
int __fastcall RtlCreateSecurityDescriptorRelative(_BYTE *a1)
{
  memset(a1, 0, 20);
  *a1 = 1;
  return 0;
}
