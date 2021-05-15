// RtlIntegerToUnicodeString 
 
int __fastcall RtlIntegerToUnicodeString(int a1, int a2, unsigned __int16 *a3)
{
  int result; // r0
  int v5; // r3
  unsigned __int16 v6[2]; // [sp+0h] [bp-38h] BYREF
  char *v7; // [sp+4h] [bp-34h]
  char v8[48]; // [sp+8h] [bp-30h] BYREF

  result = RtlIntegerToChar(a1, a2, 33, v8);
  if ( result >= 0 )
  {
    v7 = v8;
    v6[1] = 33;
    v6[0] = (unsigned __int16)strlen((unsigned int)v8);
    result = RtlAnsiStringToUnicodeString(a3, v6, 0, v5);
  }
  return result;
}
