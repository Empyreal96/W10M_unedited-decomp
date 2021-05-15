// RtlpMuiRegAddAlternateCodePage 
 
int __fastcall RtlpMuiRegAddAlternateCodePage(int a1, int a2)
{
  int result; // r0
  int v4; // [sp+8h] [bp-38h] BYREF
  int v5[3]; // [sp+Ch] [bp-34h] BYREF
  char v6[40]; // [sp+18h] [bp-28h] BYREF

  v5[0] = 7;
  v4 = 0;
  v5[1] = 0;
  RtlInitUnicodeString((unsigned int)v6, L"AlternateCodePage");
  result = ((int (__fastcall *)(int, char *, int *, _DWORD, int *))LdrpQueryValueKey)(a2, v6, v5, 0, &v4);
  if ( result != -1073741772 )
    result = sub_54DE1C();
  return result;
}
