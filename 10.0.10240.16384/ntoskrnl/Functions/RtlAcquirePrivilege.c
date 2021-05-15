// RtlAcquirePrivilege 
 
int __fastcall RtlAcquirePrivilege(int a1, int a2, int a3)
{
  int result; // r0

  if ( (a3 & 0xFFFFFFFC) != 0 )
    result = -1073741811;
  else
    result = sub_7E8E6C();
  return result;
}
