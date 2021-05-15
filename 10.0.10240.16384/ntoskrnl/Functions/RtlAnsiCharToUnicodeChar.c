// RtlAnsiCharToUnicodeChar 
 
int __fastcall RtlAnsiCharToUnicodeChar(unsigned __int8 **a1, int a2, int a3, int a4)
{
  unsigned __int8 *v5; // r1
  int v6; // r4
  int result; // r0
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = *a1;
  LOWORD(v8[0]) = 32;
  if ( NlsLeadByteInfoTable[*v5] )
    v6 = 2;
  else
    v6 = 1;
  if ( RtlMultiByteToUnicodeN(v8, 2, 0, v5) < 0 )
    result = 32;
  else
    result = LOWORD(v8[0]);
  *a1 += v6;
  return result;
}
