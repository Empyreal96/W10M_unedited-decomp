// ExpWnfCompleteThreadSubscriptions 
 
int __fastcall ExpWnfCompleteThreadSubscriptions(int a1, int a2)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int result; // r0
  char v6[40]; // [sp+18h] [bp-28h] BYREF

  __mrc(15, 0, 13, 0, 3);
  v2 = ExpCaptureWnfStateName(a2, v6, 0);
  if ( v2 >= 0 )
    result = sub_7C3EB8(v2, v3, v4);
  else
    result = -1073741811;
  return result;
}
