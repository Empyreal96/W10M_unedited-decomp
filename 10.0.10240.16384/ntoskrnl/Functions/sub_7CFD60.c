// sub_7CFD60 
 
int sub_7CFD60()
{
  int v0; // r6
  int (__fastcall *v2)(int); // [sp-4h] [bp-4h]

  *(_DWORD *)(v0 + 160) = 1;
  *(_DWORD *)(v0 + 164) = 0;
  *(_DWORD *)(v0 + 168) = 0;
  KeInitializeEvent(v0 + 172, 1, 0);
  *(_DWORD *)(v0 + 192) = 1;
  *(_DWORD *)(v0 + 196) = 0;
  *(_DWORD *)(v0 + 200) = 0;
  KeInitializeEvent(v0 + 204, 1, 0);
  *(_BYTE *)(v0 + 4) |= 0x40u;
  *(_BYTE *)(v0 + 6) |= 2u;
  *(_BYTE *)(v0 + 7) = *(_BYTE *)(v0 + 7) & 0xF | 0x30;
  *(_DWORD *)(v0 + 44) = v0 + 44;
  *(_DWORD *)(v0 + 48) = v0 + 44;
  if ( v0 != -192 )
    *(_DWORD *)(v0 + 40) = v0 + 192;
  *(_DWORD *)(v0 + 52) = 0;
  *(_DWORD *)(v0 + 56) = 0;
  *(_DWORD *)(v0 + 60) = 0;
  *(_DWORD *)(v0 + 64) = 0;
  *(_DWORD *)(v0 + 72) |= 0x10u;
  return v2(-1073741670);
}
