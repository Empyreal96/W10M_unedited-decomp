// sub_7CB8D0 
 
void sub_7CB8D0()
{
  int v0; // r4
  int v1; // r5
  int v2; // r1

  v2 = *(_DWORD *)(v0 + 24);
  if ( v2 )
  {
    PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v2, 11);
    if ( ((*(_DWORD *)(v0 + 272) ^ v1) & 0x40) != 0 )
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v0 + 24), 29);
    if ( ((*(_DWORD *)(v0 + 272) ^ v1) & 4) != 0 )
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v0 + 24), 30);
  }
  JUMPOUT(0x76DB58);
}
