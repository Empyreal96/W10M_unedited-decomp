// MiInitializeApiSets 
 
int __fastcall MiInitializeApiSets(int a1)
{
  int v2; // r4
  int v3; // r5
  int v5; // r4
  int v6; // [sp+10h] [bp-20h] BYREF
  int v7; // [sp+14h] [bp-1Ch] BYREF
  int v8[6]; // [sp+18h] [bp-18h] BYREF

  v8[0] = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 2208);
  v8[1] = 0;
  v2 = MmCreateSection((int)&v7, 983071, 0, (int)v8, 4, 0x8000000, 0, 0);
  if ( v2 >= 0 )
  {
    v3 = v7;
    v6 = 0;
    if ( MmMapViewInSystemSpace(v7, (int)v8, (int)&v6) < 0 )
      return sub_96A8BC();
    v5 = v8[0];
    memmove(v8[0], *(_DWORD *)(*(_DWORD *)(a1 + 132) + 2204), *(_DWORD *)(*(_DWORD *)(a1 + 132) + 2208));
    dword_632ED0 = v3;
    dword_632ED4 = v5;
    v2 = 0;
    dword_632ED8 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 2208);
  }
  return v2;
}
