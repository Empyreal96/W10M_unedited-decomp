// NtSetSecurityObject 
 
int __fastcall NtSetSecurityObject(int a1, int a2, int a3)
{
  int result; // r0

  if ( a3 )
    result = sub_7DCBF0();
  else
    result = -1073741819;
  return result;
}
