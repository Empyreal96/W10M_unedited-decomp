// RtlSecondsSince1970ToTime 
 
int *__fastcall RtlSecondsSince1970ToTime(unsigned int a1, _QWORD *a2)
{
  int *result; // r0

  result = dword_989680;
  *a2 = (a1 + 0x2B6109100i64) * (unsigned int)dword_989680;
  return result;
}
