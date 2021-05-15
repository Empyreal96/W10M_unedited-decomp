// PfpSetParameter 
 
int __fastcall PfpSetParameter(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int result; // r0
  _DWORD v6[4]; // [sp+8h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  RtlInitUnicodeString((unsigned int)v6, a2);
  if ( a1 )
    result = ZwSetValueKey();
  else
    result = -1073741811;
  return result;
}
