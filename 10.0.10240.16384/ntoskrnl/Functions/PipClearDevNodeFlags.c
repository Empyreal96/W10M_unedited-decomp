// PipClearDevNodeFlags 
 
int __fastcall PipClearDevNodeFlags(int result, int a2)
{
  int v2; // r6
  int v3; // r4
  int v4; // r3
  int v5; // r1

  v2 = *(_DWORD *)(result + 268);
  v3 = result;
  v4 = v2 & ~a2;
  *(_DWORD *)(result + 268) = v4;
  if ( ((v4 ^ v2) & 0x307000) != 0 )
  {
    v5 = *(_DWORD *)(result + 24);
    if ( v5 )
    {
      result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v5, 11);
      if ( ((*(_DWORD *)(v3 + 268) ^ v2) & 0x4000) != 0 )
      {
        result = sub_7CB4CC(result);
      }
      else if ( ((*(_DWORD *)(v3 + 268) ^ v2) & 0x2000) != 0 )
      {
        result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v3 + 24), 27);
      }
    }
  }
  return result;
}
