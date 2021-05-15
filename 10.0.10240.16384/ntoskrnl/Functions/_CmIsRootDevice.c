// _CmIsRootDevice 
 
int __fastcall CmIsRootDevice(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( RtlInitUnicodeStringEx((int)v5, a1) < 0 )
    result = 0;
  else
    result = RtlEqualUnicodeString((unsigned __int16 *)v5, (unsigned __int16 *)&dword_401D04, 1);
  return result;
}
