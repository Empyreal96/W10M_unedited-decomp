// VfUtilEqualUnicodeString 
 
BOOL __fastcall VfUtilEqualUnicodeString(unsigned __int8 **a1, unsigned __int16 *a2)
{
  int v2; // r4

  v2 = *(unsigned __int16 *)a1;
  return v2 == *a2 && RtlCompareMemory(a1[1], *((_DWORD *)a2 + 1), v2) == v2;
}
