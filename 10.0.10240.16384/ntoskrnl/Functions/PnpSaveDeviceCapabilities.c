// PnpSaveDeviceCapabilities 
 
int __fastcall PnpSaveDeviceCapabilities(_DWORD *a1, int a2)
{
  int v4; // r7
  int v5; // r1
  int v7; // [sp+10h] [bp-20h] BYREF
  unsigned int v8; // [sp+14h] [bp-1Ch]

  v4 = PnpDeviceObjectToDeviceInstance(a1[4], &v7, 983103);
  if ( v4 >= 0 )
  {
    if ( (a1[67] & 0x40) != 0 )
      *(_DWORD *)(a2 + 4) &= 0xFFFFFDFF;
    a1[92] = *(_DWORD *)(a2 + 4);
    v8 = ((*(_DWORD *)(a2 + 4) >> 4) & 0xC00 | ((*(_DWORD *)(a2 + 4) >> 13) & 8 | (unsigned __int16)*(_DWORD *)(a2 + 4)) & 0x3FCu) >> 2;
    CmSetDeviceRegProp(PiPnpRtlCtx, a1[6], v7);
    v5 = a1[6];
    v8 = *(_DWORD *)(a2 + 12);
    CmSetDeviceRegProp(PiPnpRtlCtx, v5, v7);
    ZwClose();
  }
  return v4;
}
