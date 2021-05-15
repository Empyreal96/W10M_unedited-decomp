// SeSetSecurityDescriptorInfoEx 
 
int __fastcall SeSetSecurityDescriptorInfoEx(int a1, int *a2, int a3, int *a4, char a5, int a6, _DWORD *a7)
{
  int result; // r0

  if ( *a4 )
    result = RtlpSetSecurityObject(*a4, *a2, a3, (int)a4, a5, a6, a7);
  else
    result = -1073741609;
  return result;
}
