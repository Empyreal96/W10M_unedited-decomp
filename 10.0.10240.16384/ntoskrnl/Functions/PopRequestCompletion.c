// PopRequestCompletion 
 
int __fastcall PopRequestCompletion(int a1, int a2, int a3)
{
  void (__fastcall *v3)(_DWORD, int, _DWORD, _DWORD); // lr
  _DWORD *v4; // r5
  int v5; // r7
  int v6; // r8
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r1

  v3 = *(void (__fastcall **)(_DWORD, int, _DWORD, _DWORD))(a3 + 136);
  v4 = *(_DWORD **)(a3 + 128);
  v5 = *(unsigned __int8 *)(a3 + 133);
  v6 = *(unsigned __int8 *)(a3 + 112);
  if ( v3 )
    v3(*(_DWORD *)(a3 + 144), v6, *(_DWORD *)(a3 + 120), *(_DWORD *)(a3 + 140));
  if ( v6 )
  {
    PopDequeueQuerySetIrp(a2);
    if ( v4 && *(_BYTE *)(a3 + 112) == 2 && *(_DWORD *)(a3 + 116) == 1 && v5 )
    {
      if ( *(_DWORD *)(a3 + 120) == 1 )
      {
        __dmb(0xBu);
        v9 = v4 + 4;
        do
          v10 = __ldrex(v9);
        while ( __strex(v10 & 0xFFFFFFFD, v9) );
        __dmb(0xBu);
        v5 = (v10 & 2) != 0;
      }
      if ( v5 )
      {
        PopPepDeviceDState(v4[8], *(_DWORD *)(a3 + 120), 1, *(unsigned __int8 *)(a3 + 132));
        PopDiagTraceFxDevicePowerState(v4[7], *(_DWORD *)(a3 + 120));
      }
    }
LABEL_14:
    PopFreeIrp(a2);
    return -1073741802;
  }
  v12 = PopDiagTraceIrpFinish(a2);
  if ( *(int *)(a2 + 24) < 0 )
  {
    if ( v4 )
    {
      PopPepDeviceWaitWake(v4[8], 1);
      __dmb(0xBu);
      v13 = v4 + 28;
      do
      {
        v14 = __ldrex(v13);
        v15 = v14 - 1;
      }
      while ( __strex(v15, v13) );
      __dmb(0xBu);
      if ( !v15 )
        KeSetEvent((int)(v4 + 29), 0, 0);
    }
    goto LABEL_14;
  }
  return sub_54ACFC(v12);
}
