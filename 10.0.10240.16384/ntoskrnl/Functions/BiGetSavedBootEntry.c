// BiGetSavedBootEntry 
 
int __fastcall BiGetSavedBootEntry(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  int v5; // r4
  _DWORD *v6; // r0
  int result; // r0
  _DWORD *v8; // [sp+8h] [bp-10h] BYREF
  unsigned int v9[3]; // [sp+Ch] [bp-Ch] BYREF

  v9[0] = a4;
  v8 = 0;
  v5 = BiGetRegistryValue(a1, L"FirmwareVariable", (int)L"Description", 3, (int *)&v8, v9);
  v6 = v8;
  if ( v5 < 0 || (v9[0] < 0x1C || v8[1] < 0x1Cu || !*v8 ? (v5 = -1073741811) : (*a2 = v8), v5 < 0) )
    result = sub_814678(v6);
  else
    result = v5;
  return result;
}
