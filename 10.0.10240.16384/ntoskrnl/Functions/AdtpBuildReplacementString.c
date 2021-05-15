// AdtpBuildReplacementString 
 
int __fastcall AdtpBuildReplacementString(int a1, unsigned __int16 *a2)
{
  int v3; // r2
  int v4; // r5
  int v5; // r3
  unsigned __int16 v7[2]; // [sp+0h] [bp-28h] BYREF
  char *v8; // [sp+4h] [bp-24h]
  char v9; // [sp+8h] [bp-20h] BYREF

  v8 = &v9;
  v7[1] = 20;
  v7[0] = 0;
  v4 = RtlIntegerToUnicodeString(a1, 10, v7);
  if ( v4 >= 0 )
  {
    v5 = *a2;
    if ( *a2 )
      RtlAppendUnicodeToString(a2, (int)L", ", v3, v5);
    RtlAppendUnicodeToString(a2, (int)L"%%", v3, v5);
    RtlAppendUnicodeStringToString(a2, v7);
  }
  return v4;
}
