// sub_8DF7A4 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_8DF7A4(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r7
  __int64 *v5; // r8
  int *v6; // r9
  int *v7; // r10
  int v8; // r0
  int v9; // r0
  int v10; // r0
  unsigned int v11; // r5 OVERLAPPED
  unsigned int v12; // r6 OVERLAPPED
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  int *v18; // r3
  int v19; // r0
  int v20; // r3

  DbgPrintEx(101, 0, (int)"\n+--BGFX-REPORT-----------------+\n|                              |\n", a4);
  DbgPrintEx(101, 0, (int)"|  DisplayMode:  %4ux%4ux%2u  |\n", *v7);
  DbgPrintEx(101, 0, (int)"|  LogoSize:         %8u  |\n|                              |\n", v6[41]);
  if ( !*v5 )
    __brkdiv0();
  v8 = _rt_sdiv64(*v5, *(_QWORD *)&dword_64A5C0 * v4);
  DbgPrintEx(101, 0, (int)"|  ProgressProlog:   %8u  |\n", v8);
  DbgPrintEx(101, 0, (int)"|  ProgressFrames:   %8u  |\n", dword_64A5BC);
  DbgPrintEx(101, 0, (int)"|  ProgressMemory:   %8u  |\n", v6[30]);
  if ( !*v5 )
    __brkdiv0();
  v9 = _rt_sdiv64(*v5, qword_6180E8 * v4);
  DbgPrintEx(101, 0, (int)"|  ProgressLow:      %8u  |\n", v9);
  if ( !*v5 )
    __brkdiv0();
  v10 = _rt_sdiv64(*v5, qword_64A5A0 * v4);
  DbgPrintEx(101, 0, (int)"|  ProgressHigh:     %8u  |\n", v10);
  *(_QWORD *)&v11 = *v5;
  if ( !*v5 )
    __brkdiv0();
  _rt_sdiv64(*v5, qword_64A5D8 * v4);
  if ( !v11 && !v12 )
    __brkdiv0();
  v13 = _rt_sdiv64(__SPAIR64__(v12, v11), *(_QWORD *)&dword_64A5B0 * v4);
  DbgPrintEx(
    101,
    0,
    (int)"|  ProgressManual:   %8u  |\n|  ProgressTotal:    %8u  |\n|                              |\n",
    v13);
  if ( !*v5 )
    __brkdiv0();
  v14 = _rt_sdiv64(*v5, *(_QWORD *)&dword_64A5A8 * v4);
  DbgPrintEx(101, 0, (int)"|  FadeProlog:       %8u  |\n", v14);
  DbgPrintEx(101, 0, (int)"|  FadeFrames:       %8u  |\n", dword_64A5B8);
  DbgPrintEx(
    101,
    0,
    (int)"|  FadeMemory:       %8u  |\n|  FadeIo:           %8u  |\n|  FadeCpu:          %8u  |\n",
    v6[29]);
  if ( !*v5 )
    __brkdiv0();
  v15 = _rt_sdiv64(*v5, qword_6180F0 * v4);
  DbgPrintEx(101, 0, (int)"|  FadeLow:          %8u  |\n", v15);
  if ( !*v5 )
    __brkdiv0();
  v16 = _rt_sdiv64(*v5, qword_64A5C8 * v4);
  DbgPrintEx(101, 0, (int)"|  FadeHigh:         %8u  |\n", v16);
  if ( !*v5 )
    __brkdiv0();
  _rt_sdiv64(*v5, qword_64A588 * v4);
  DbgPrintEx(
    101,
    0,
    (int)"|  FadeOverlap:      %8u  |\n|  FadeTotal:        %8u  |\n|                              |\n",
    dword_641964);
  if ( !*v5 )
    __brkdiv0();
  v17 = _rt_sdiv64(*v5, qword_64A5D0 * v4);
  DbgPrintEx(101, 0, (int)"|  AnimationTotal:   %8u  |\n|                              |", v17);
  v18 = (int *)v6[34];
  if ( v18 )
    DbgPrintEx(101, 0, (int)"\n|  ResidentSize:     %8u  |\n|                              |", *v18);
  if ( !*v5 )
    __brkdiv0();
  v19 = _rt_sdiv64(*v5, *(_QWORD *)&dword_64A5E8 * v4);
  DbgPrintEx(101, 0, (int)"\n|  CompressBitmapsCPU: %8u|\n|                              |", v19);
  DbgPrintEx(101, 0, (int)"\n+------------------------------+\n\n", v20);
  JUMPOUT(0x8DDE66);
}
