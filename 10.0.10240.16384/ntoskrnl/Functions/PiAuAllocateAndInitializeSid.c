// PiAuAllocateAndInitializeSid 
 
int __fastcall PiAuAllocateAndInitializeSid(int *a1, int a2, unsigned int a3)
{
  unsigned __int8 v4; // r4
  int v6; // r0
  int v7; // r0
  int result; // r0

  v4 = a3;
  v6 = RtlLengthRequiredSid(a3);
  v7 = ExAllocatePoolWithTag(1, v6, 538996816);
  *a1 = v7;
  if ( !v7 )
    return sub_8175F4();
  result = RtlInitializeSid(v7, a2, v4);
  if ( result < 0 )
    JUMPOUT(0x8175F6);
  return result;
}
