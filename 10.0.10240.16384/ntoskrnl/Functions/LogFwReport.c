// LogFwReport 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall LogFwReport(int a1, int a2, int a3)
{
  unsigned int v3; // r5 OVERLAPPED
  unsigned int v4; // r6 OVERLAPPED
  int v5; // r0
  _DWORD v6[10]; // [sp+8h] [bp-28h] BYREF

  if ( (dword_619018 & 0x80) != 0 )
  {
    dword_619018 &= 0xFFFFFF7F;
    BgpFwQueryPerformanceCounter(v6, (int)&dword_617930, a3, dword_619018);
    BgpGetResolution(v6);
    dword_641950 = v6[0];
    dword_641954 = v6[1];
    unk_641958 = v6[2];
    dword_641984 = BgpGetBitsPerPixel();
    *(_QWORD *)&v3 = *(_QWORD *)&dword_617930;
    dword_641980 = dword_619018;
    if ( !*(_QWORD *)&dword_617930 )
      __brkdiv0();
    dword_641964 = _rt_sdiv64(*(__int64 *)&dword_617930, 1000000 * qword_641978);
    if ( !v3 && !v4 )
      __brkdiv0();
    dword_64195C = _rt_sdiv64(__SPAIR64__(v4, v3), 1000000i64 * *(_QWORD *)&dword_64A590);
    if ( !v3 && !v4 )
      __brkdiv0();
    dword_641960 = _rt_sdiv64(__SPAIR64__(v4, v3), 1000000i64 * *(_QWORD *)&dword_64A598);
    dword_649E30 = (int)LogFwpRegisterWorker;
    dword_649E34 = 0;
    dword_649E28 = 0;
    v5 = ExQueueWorkItem(&dword_649E28, 1);
    if ( (dword_619018 & 0x10000) != 0 )
      sub_8DF7A4(v5);
  }
}
