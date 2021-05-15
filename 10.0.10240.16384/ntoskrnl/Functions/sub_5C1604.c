// sub_5C1604 
 
int __fastcall sub_5C1604(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r0
  int v7; // r5
  int v9[3]; // [sp+Ch] [bp-34h] BYREF
  char v10[8]; // [sp+18h] [bp-28h] BYREF
  char v11[8]; // [sp+20h] [bp-20h] BYREF

  v9[0] = 0;
  v6 = RtlInitUnicodeString(
         (unsigned int)v11,
         L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CommonGlobUserSettings\\");
  v7 = sub_5C16F0(v6, a2, v11, a4, v9);
  if ( v7 >= 0 && v9[0] == 2 )
  {
    v9[1] = 0;
    RtlInitUnicodeString((unsigned int)v10, L"RedirectedKey");
    ZwQueryValueKey();
    v7 = 0;
  }
  return v7;
}
