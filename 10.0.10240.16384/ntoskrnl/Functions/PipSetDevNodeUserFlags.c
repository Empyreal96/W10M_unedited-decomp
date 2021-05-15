// PipSetDevNodeUserFlags 
 
int __fastcall PipSetDevNodeUserFlags(int result, int a2)
{
  int v2; // r5
  int v3; // r4
  int v4; // r1

  v2 = *(_DWORD *)(result + 272);
  v3 = result;
  *(_DWORD *)(result + 272) = v2 | a2;
  if ( (((unsigned __int8)(v2 | a2) ^ (unsigned __int8)v2) & 0x47) != 0 )
  {
    v4 = *(_DWORD *)(result + 24);
    if ( v4 )
    {
      result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v4, 11);
      if ( ((*(_DWORD *)(v3 + 272) ^ v2) & 0x40) != 0 )
      {
        result = sub_818230(result);
      }
      else if ( ((*(_DWORD *)(v3 + 272) ^ v2) & 4) != 0 )
      {
        result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v3 + 24), 30);
      }
    }
  }
  return result;
}
