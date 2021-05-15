// PopValidateServiceNotification 
 
int __fastcall PopValidateServiceNotification(int a1, unsigned int a2)
{
  int result; // r0

  if ( a2 < 4 )
    return -1073741811;
  result = RtlStringCbLengthW(a1 + 4, a2 - 4, 0);
  if ( result >= 0 )
    result = 0;
  return result;
}
