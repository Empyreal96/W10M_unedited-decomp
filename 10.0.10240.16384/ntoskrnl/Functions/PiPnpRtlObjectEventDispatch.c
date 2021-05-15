// PiPnpRtlObjectEventDispatch 
 
int __fastcall PiPnpRtlObjectEventDispatch(int result)
{
  int v1; // r4
  int v2; // r3

  v1 = result;
  v2 = *(_DWORD *)(result + 4);
  if ( (v2 & 1) != 0 || (v2 & 2) != 0 || (v2 & 8) != 0 || *(_DWORD *)(result + 44) )
  {
    PiDcHandleObjectEvent(result);
    result = PiDqGetObjectManagerForPnpObjectType(*(_DWORD *)(*(_DWORD *)(v1 + 8) + 20));
    if ( result )
      result = PiDqObjectManagerHandleObjectEvent(result, v1);
  }
  return result;
}
