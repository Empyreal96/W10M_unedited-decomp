// _RegRtlSetValue 
 
int __fastcall RegRtlSetValue(int a1, unsigned __int16 *a2)
{
  int result; // r0
  char v3[24]; // [sp+8h] [bp-18h] BYREF

  result = RtlInitUnicodeStringEx((int)v3, a2);
  if ( result >= 0 )
    result = ZwSetValueKey();
  return result;
}
