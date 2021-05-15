// PopCheckForIdleness 
 
void PopCheckForIdleness()
{
  int v0; // r4
  int v1; // r6
  int v2; // r7
  unsigned int v3; // r9
  unsigned int v4; // r10
  int v5; // r6
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2
  int v12; // [sp+0h] [bp-30h]
  int v13; // [sp+8h] [bp-28h] BYREF
  int v14; // [sp+Ch] [bp-24h]

  v12 = KeNumberProcessors_0;
  v0 = KfRaiseIrql(2);
  v1 = unk_61E830;
  v14 = unk_61E834;
  KeQueryTickCount(&v13);
  KfLowerIrql(v0);
  if ( dword_61E80C )
  {
    v2 = v13;
    if ( byte_61E829 )
    {
      v3 = v13 - v1;
      if ( v13 - v1 <= 0 )
      {
        byte_61E829 = 0;
        goto LABEL_5;
      }
      v4 = dword_681D78[0];
      v5 = 0;
      v6 = 100;
      while ( v4 )
      {
        v7 = __clz(__rbit(v4));
        v4 &= ~(1 << v7);
        v8 = 100
           * (*(_DWORD *)(*((_DWORD *)*(&KiProcessorBlock + v7) + 3) + 404)
            - *((_DWORD *)*(&KiProcessorBlock + v7) + 779));
        if ( !v3 )
          __brkdiv0();
        if ( (int)(v8 / v3) < v6 )
          v6 = v8 / v3;
        v5 += v8 / v3;
      }
      if ( v6 <= 100 )
      {
        if ( v6 < 0 )
          v6 = 0;
      }
      else
      {
        v6 = 100;
      }
      if ( !v12 )
        __brkdiv0();
      v9 = v5 / v12;
      if ( v5 / v12 <= 100 )
      {
        if ( v9 < 0 )
          v9 = 0;
      }
      else
      {
        v9 = 100;
      }
      PopSIdle = v9;
      dword_61E804 = v6;
      dword_61E808 += PopIdleScanInterval;
      PopDiagTraceIdleCheck(v9, v6, v9);
    }
    unk_61E830 = v2;
    unk_61E834 = v14;
    v10 = dword_681D78[0];
    byte_61E829 = 1;
    while ( v10 )
    {
      v11 = __clz(__rbit(v10));
      v10 &= ~(1 << v11);
      *((_DWORD *)*(&KiProcessorBlock + v11) + 779) = *(_DWORD *)(*((_DWORD *)*(&KiProcessorBlock + v11) + 3) + 404);
    }
  }
LABEL_5:
  PopGetPolicyWorker(8);
  PopCheckForWork();
}
