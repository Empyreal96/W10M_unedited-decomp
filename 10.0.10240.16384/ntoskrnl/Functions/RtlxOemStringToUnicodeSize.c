// RtlxOemStringToUnicodeSize 
 
int __fastcall RtlxOemStringToUnicodeSize(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  RtlMultiByteToUnicodeSize(v5, *((_DWORD *)a1 + 1), *a1);
  return v5[0] + 2;
}
