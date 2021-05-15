// PsAssignProcessToJobObject 
 
int __fastcall PsAssignProcessToJobObject(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v7[6]; // [sp+0h] [bp-18h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  if ( PspGetJobAssignmentDisposition(a1, a2, v7) < 0 )
    return -1073741790;
  result = PspAssignProcessToJob(a1, a2, v7[0]);
  if ( result == -1073741267 )
    result = sub_7C185C();
  return result;
}
