// RtlInt64ToUnicodeString 
 
int __fastcall RtlInt64ToUnicodeString(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-58h] BYREF
  char *v7; // [sp+4h] [bp-54h]
  char v8[80]; // [sp+8h] [bp-50h] BYREF

  v6 = a1;
  v7 = (char *)a2;
  result = ((int (__fastcall *)(int *, int, int, char *))RtlLargeIntegerToChar)(&v6, a3, 65, v8);
  if ( result >= 0 )
  {
    v7 = v8;
    HIWORD(v6) = 65;
    LOWORD(v6) = (unsigned __int16)strlen((unsigned int)v8);
    result = RtlAnsiStringToUnicodeString(a4, &v6, 0);
  }
  return result;
}
