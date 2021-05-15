// PnpNotifyUserModeDeviceRemoval 
 
int __fastcall PnpNotifyUserModeDeviceRemoval(_DWORD *a1, unsigned __int16 *a2, _DWORD *a3, int a4, int a5)
{
  int v5; // r8
  int v8; // r7
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r0
  unsigned int v13; // r0
  int v15; // [sp+0h] [bp-1D0h]
  int v18; // [sp+10h] [bp-1C0h]
  int v19; // [sp+14h] [bp-1BCh]
  int v20; // [sp+18h] [bp-1B8h]
  int v21; // [sp+1Ch] [bp-1B4h]
  unsigned __int16 v22[216]; // [sp+20h] [bp-1B0h] BYREF

  v18 = a1[16];
  v19 = a1[17];
  v20 = a1[18];
  v21 = a1[19];
  v5 = a1[6];
  v15 = a1[7];
  v8 = RtlStringCchCopyW(v22, 0xC8u, (int)(a1 + 25));
  if ( !v8 )
  {
    v9 = a3[1];
    v10 = a3[2];
    v11 = a3[3];
    a1[16] = *a3;
    a1[17] = v9;
    a1[18] = v10;
    a1[19] = v11;
    a1[6] = a4;
    a1[7] = a5;
    while ( *a2 )
    {
      v12 = wcslen(a2);
      memmove((int)(a1 + 25), (int)a2, 2 * (v12 + 1));
      v8 = PiUEventNotifyUserMode(a1);
      if ( v8 < 0 )
        break;
      a2 += wcslen(a2) + 1;
    }
    a1[16] = v18;
    a1[17] = v19;
    a1[18] = v20;
    a1[19] = v21;
    a1[6] = v5;
    a1[7] = v15;
    v13 = wcslen(v22);
    memmove((int)(a1 + 25), (int)v22, 2 * (v13 + 1));
  }
  return v8;
}
