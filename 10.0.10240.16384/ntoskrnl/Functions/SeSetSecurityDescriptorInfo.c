// SeSetSecurityDescriptorInfo 
 
int __fastcall SeSetSecurityDescriptorInfo(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int result; // r0

  if ( *a4 )
    result = RtlpSetSecurityObject(*a4, *a2, a3);
  else
    result = -1073741609;
  return result;
}
