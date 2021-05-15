// WmipQueryWmiRegInfo 
 
int __fastcall WmipQueryWmiRegInfo(int a1, int a2, unsigned __int16 *a3, _DWORD *a4)
{
  int v5; // r3
  unsigned __int16 v7; // [sp+0h] [bp-10h] BYREF
  unsigned __int16 *v8; // [sp+4h] [bp-Ch]
  _DWORD *v9; // [sp+8h] [bp-8h]

  v8 = a3;
  v9 = a4;
  *a4 = &WmipRegistryPath;
  RtlInitAnsiString((unsigned int)&v7, (unsigned int)"SMBiosData");
  return RtlAnsiStringToUnicodeString(a3, &v7, 1, v5);
}
