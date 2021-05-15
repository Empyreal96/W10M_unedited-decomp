// WmipEnableCollectOrEvent 
 
int __fastcall WmipEnableCollectOrEvent(int a1, int a2, _BYTE *a3)
{
  int v5; // r6
  int v6; // r4
  BOOL v8; // r4
  _DWORD *i; // r3
  int v10; // r2

  *a3 = 0;
  if ( a2 == 2244924 )
  {
    v8 = 0;
    v5 = 0;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    for ( i = *(_DWORD **)(a1 + 32); i != (_DWORD *)(a1 + 32); i = (_DWORD *)*i )
    {
      v10 = i[2];
      if ( (v10 & 0x1000) == 0 && ((v10 & 0x8000) == 0 || !v8) )
        v8 = v8 || (v10 & 4) != 0;
    }
    KeReleaseMutex((int)&WmipSMMutex);
    if ( !v8 )
      return 0;
  }
  else
  {
    if ( a2 != 2244928 )
      return -1073741649;
    v5 = 1;
  }
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v6 = WmipSendEnableRequest(a1, v5);
  KeReleaseMutex((int)&WmipSMMutex);
  if ( v6 >= 0 )
    *a3 = 1;
  return v6;
}
