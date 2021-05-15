// PopValidateContextMembership 
 
int __fastcall PopValidateContextMembership(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  LOBYTE(v5[0]) = 0;
  result = RtlCheckTokenMembership(0, a1, (int)v5);
  if ( result < 0 || !LOBYTE(v5[0]) )
    result = -1073741790;
  return result;
}
