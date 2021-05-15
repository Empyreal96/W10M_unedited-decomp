// RtlCreateUnicodeStringFromAsciiz 
 
BOOL __fastcall RtlCreateUnicodeStringFromAsciiz(unsigned __int16 *a1, unsigned int a2, int a3, int a4)
{
  int v5; // r3
  unsigned __int16 v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v8 = a3;
  v9 = a4;
  return RtlInitAnsiStringEx((int)&v7, a2) >= 0 && RtlAnsiStringToUnicodeString(a1, &v7, 1, v5) >= 0;
}
