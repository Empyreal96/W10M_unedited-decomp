// PspLocateInPEManifest 
 
int __fastcall PspLocateInPEManifest(int a1, int a2)
{
  int v3; // r0
  int v4; // r2
  int v6; // [sp+10h] [bp-18h] BYREF
  int v7[4]; // [sp+18h] [bp-10h] BYREF

  v7[0] = 24;
  v7[1] = 1;
  v7[2] = 0;
  v6 = 0;
  v3 = LdrResSearchResource(*(_DWORD *)(a1 + 296), v7, 3, 48, a2 + 180, &v6, 0, 0);
  if ( v3 >= 0 )
  {
    v4 = *(_DWORD *)(a2 + 120);
    *(_DWORD *)(a2 + 184) = v6;
    *(_BYTE *)(a2 + 8) |= 0x20u;
    *(_DWORD *)(v4 + 8) |= 0x2000u;
    return 0;
  }
  if ( v3 == -1073741687 || v3 == -1073741686 )
    return 0;
  return sub_7E7814();
}
