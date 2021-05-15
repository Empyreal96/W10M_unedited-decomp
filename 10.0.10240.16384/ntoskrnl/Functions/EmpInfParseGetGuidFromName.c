// EmpInfParseGetGuidFromName 
 
int __fastcall EmpInfParseGetGuidFromName(int a1, int a2, int a3, _BYTE *a4)
{
  unsigned int v5; // r1
  int v6; // r3
  int result; // r0
  unsigned __int16 v8[2]; // [sp+8h] [bp-70h] BYREF
  char *v9; // [sp+Ch] [bp-6Ch]
  unsigned __int16 v10[4]; // [sp+10h] [bp-68h] BYREF
  char v11; // [sp+18h] [bp-60h] BYREF

  v8[1] = 78;
  v9 = &v11;
  v5 = EmpInfParseGetValueFromSectionAndKeyName(a1, a2, a3);
  if ( !v5 )
    return -1073741275;
  RtlInitAnsiString((unsigned int)v10, v5);
  result = RtlAnsiStringToUnicodeString(v8, v10, 0, v6);
  if ( result >= 0 )
    result = RtlGUIDFromString(v8, a4);
  return result;
}
