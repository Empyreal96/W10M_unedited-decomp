// PiUEventHashStringIntoBucket 
 
unsigned int __fastcall PiUEventHashStringIntoBucket(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+0h] [bp-10h] BYREF
  _DWORD v6[2]; // [sp+8h] [bp-8h] BYREF

  v5[1] = a2;
  v6[0] = a3;
  v6[1] = a4;
  v5[0] = 0;
  RtlInitUnicodeString(v6, a1);
  RtlHashUnicodeString(v6, 1, 0, v5);
  return v5[0] % 0xDu;
}
