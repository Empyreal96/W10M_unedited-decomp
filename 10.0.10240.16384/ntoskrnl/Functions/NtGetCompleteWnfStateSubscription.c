// NtGetCompleteWnfStateSubscription 
 
int __fastcall NtGetCompleteWnfStateSubscription(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, unsigned int a6)
{
  _DWORD *v6; // r5
  _DWORD *v7; // r6
  int v8; // r0
  int v9; // r4
  int v10; // r9
  unsigned int v11; // r1
  __int16 v12; // r3
  _DWORD _18[16]; // [sp+18h] [bp-28h] BYREF

  _18[12] = a1;
  _18[13] = a2;
  _18[15] = a4;
  _18[14] = a3;
  v6 = (_DWORD *)a2;
  v7 = a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 0x134);
  v9 = -1073741811;
  v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 724);
  __dmb(0xBu);
  if ( v10 )
  {
    if ( !v7 || !a2 )
      goto LABEL_12;
    if ( a3 && (!a4 || a4 == -1073741267) )
    {
      if ( (unsigned int)v7 >= MmUserProbeAddress )
        v7 = (_DWORD *)MmUserProbeAddress;
      _18[0] = *v7;
      _18[1] = v7[1];
      if ( a2 >= MmUserProbeAddress )
        v6 = (_DWORD *)MmUserProbeAddress;
      v8 = ExpWnfCompleteThreadSubscriptions(v10, _18, *v6, v6[1], a3, a4, a5, v10);
      v9 = v8;
      if ( v8 >= 0 )
      {
LABEL_12:
        if ( a6 )
        {
          if ( a6 >= 0x1030 )
          {
            ProbeForWrite(a5, a6, 8);
            v8 = ExpWnfDeliverThreadNotifications(v10, a5, a6);
            v9 = v8;
          }
          else
          {
            v9 = -1073741789;
          }
        }
      }
    }
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v9;
}
