// sub_8AA82C 
 
int __fastcall sub_8AA82C(int a1, int a2, int a3)
{
  int v3; // r5
  _WORD *v4; // r9
  unsigned int v5; // r10
  int v6; // r0
  int v11[8]; // [sp+20h] [bp-188h] BYREF
  int v12; // [sp+4Ch] [bp-15Ch]
  _WORD v13[32]; // [sp+168h] [bp-40h] BYREF

  v3 = a1;
  v4 = 0;
  v5 = 0;
  if ( a2 )
  {
    if ( sub_8AB264(a2, 4259840, 0, 0) < 0 )
      return 0;
    v6 = RtlStringCbPrintfW(v13, 0x1Au, (int)L"%04x%08x", (unsigned __int16)v12);
    if ( v6 < 0 )
      return 0;
    v4 = v13;
    v5 = 26;
  }
  else
  {
    v6 = PnpGetDeviceInstanceRegistryValue(*(_DWORD *)(a3 + 8));
    if ( v6 < 0 )
      return 0;
    if ( MEMORY[4] == 1 && MEMORY[0xC] <= 0x1Au )
    {
      v5 = MEMORY[0xC];
      v4 = (_WORD *)MEMORY[8];
    }
    else
    {
      v6 = -1073741823;
    }
  }
  if ( v6 < 0 )
    return 0;
  if ( !*(_BYTE *)(v3 + 12) )
  {
    memset(v11, 0, sizeof(v11));
    LOBYTE(v11[1]) = 2;
    v11[3] = 139472938;
    v11[4] = 1339732804;
    v11[5] = 1469114779;
    v11[6] = -263811733;
    v3 = a1;
    HIWORD(v11[1]) = *(_WORD *)(a3 + 28);
    BYTE1(v11[1]) = *(_BYTE *)(a3 + 30);
    v11[2] = *(_DWORD *)(a3 + 32);
  }
  return sub_8AA490((__int64 *)v3, (int)v11, (int)v4, v5);
}
