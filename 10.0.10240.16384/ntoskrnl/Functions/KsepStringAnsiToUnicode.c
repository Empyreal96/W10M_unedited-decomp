// KsepStringAnsiToUnicode 
 
int __fastcall KsepStringAnsiToUnicode(int a1, unsigned __int16 a2, int a3, int a4)
{
  unsigned __int16 v5[2]; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+4h] [bp-Ch]
  unsigned __int16 v7[2]; // [sp+8h] [bp-8h] BYREF
  int v8; // [sp+Ch] [bp-4h]

  v7[1] = a2;
  v7[0] = 0;
  v8 = a1;
  v6 = a3;
  v5[1] = a4;
  v5[0] = a4;
  return RtlAnsiStringToUnicodeString(v7, v5, 0, a4);
}
