// PipSetDevNodeFlags 
 
int __fastcall PipSetDevNodeFlags(int result, int a2)
{
  int v2; // r5
  int v3; // r4
  int v4; // r1

  v2 = *(_DWORD *)(result + 268);
  v3 = result;
  *(_DWORD *)(result + 268) = v2 | a2;
  if ( (((v2 | a2) ^ v2) & 0x307000) != 0 )
  {
    v4 = *(_DWORD *)(result + 24);
    if ( v4 )
    {
      result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v4, 11);
      if ( ((*(_DWORD *)(v3 + 268) ^ v2) & 0x4000) != 0 )
      {
        result = sub_7CB4BC(result);
      }
      else if ( ((*(_DWORD *)(v3 + 268) ^ v2) & 0x2000) != 0 )
      {
        result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v3 + 24), 27);
      }
    }
  }
  return result;
}
