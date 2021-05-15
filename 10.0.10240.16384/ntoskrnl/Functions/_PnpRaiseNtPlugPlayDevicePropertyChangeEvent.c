// _PnpRaiseNtPlugPlayDevicePropertyChangeEvent 
 
int __fastcall PnpRaiseNtPlugPlayDevicePropertyChangeEvent(int result, int a2, int a3)
{
  int v4; // r4
  unsigned int v5; // r6

  v4 = result;
  if ( (unsigned int)(a3 - 1) <= 0x1D )
  {
    v5 = dword_40BBA0[a3];
    result = CmMapPropertyKeyToRegProp(result, v5);
    if ( result )
    {
      result = sub_7CB5D0();
    }
    else if ( *(_DWORD *)(v4 + 156) )
    {
      result = PnpDeviceRaisePropertyChangeEventWorker(
                 v4,
                 a2,
                 0,
                 0,
                 v5,
                 *(int (__fastcall **)(int, int, int, int, int))(v4 + 156));
    }
  }
  return result;
}
