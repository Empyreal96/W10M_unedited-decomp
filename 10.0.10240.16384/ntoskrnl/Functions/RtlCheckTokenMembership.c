// RtlCheckTokenMembership 
 
int __fastcall RtlCheckTokenMembership(int a1, int a2, int a3)
{
  return RtlCheckTokenMembershipEx(a1, a2, 0, a3);
}
