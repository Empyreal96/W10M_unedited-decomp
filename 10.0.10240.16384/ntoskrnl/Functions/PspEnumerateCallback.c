// PspEnumerateCallback 
 
int __fastcall PspEnumerateCallback(int a1, int *a2, _DWORD *a3)
{
  _DWORD *v4; // r3
  int v5; // r2

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v4 = PspCreateProcessNotifyRoutine;
    }
    else
    {
      if ( a1 != 2 )
        return 0;
      v4 = PspLoadImageNotifyRoutine;
    }
  }
  else
  {
    v4 = PspCreateThreadNotifyRoutine;
  }
  v5 = *a2;
  if ( (unsigned int)*a2 < 0x40 )
  {
    *a3 = &v4[v5];
    *a2 = v5 + 1;
    return 1;
  }
  return 0;
}
