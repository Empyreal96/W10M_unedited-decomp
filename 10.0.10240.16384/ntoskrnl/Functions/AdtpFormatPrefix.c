// AdtpFormatPrefix 
 
int __fastcall AdtpFormatPrefix(unsigned __int16 *a1, int a2, int a3)
{
  int result; // r0
  int v7; // r2
  int v8; // r3
  unsigned __int16 v9[2]; // [sp+0h] [bp-30h] BYREF
  char *v10; // [sp+4h] [bp-2Ch]
  char v11; // [sp+8h] [bp-28h] BYREF

  v10 = &v11;
  v9[1] = 20;
  v9[0] = 0;
  RtlAppendUnicodeToString(a1, (int)L"%%", a3, 0);
  result = RtlIntegerToUnicodeString(a2, 10, v9);
  if ( result >= 0 )
  {
    result = RtlAppendUnicodeStringToString(a1, v9);
    if ( a3 == 1 )
      result = RtlAppendUnicodeToString(a1, (int)L"\t", v7, v8);
  }
  return result;
}
