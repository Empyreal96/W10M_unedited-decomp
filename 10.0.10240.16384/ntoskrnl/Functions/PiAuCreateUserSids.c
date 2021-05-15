// PiAuCreateUserSids 
 
int __fastcall PiAuCreateUserSids(int *a1)
{
  int result; // r0
  char v3[32]; // [sp+0h] [bp-20h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[4] = 0;
  v3[5] = 5;
  v3[8] = 0;
  v3[9] = 0;
  v3[10] = 0;
  v3[11] = 0;
  v3[12] = 0;
  v3[13] = 1;
  memset(a1, 0, 28);
  result = PiAuAllocateAndInitializeSid(a1, (int)v3, 1u);
  if ( result >= 0 )
    result = sub_96E404();
  return result;
}
