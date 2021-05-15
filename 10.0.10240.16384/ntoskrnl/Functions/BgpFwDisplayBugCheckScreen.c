// BgpFwDisplayBugCheckScreen 
 
int __fastcall BgpFwDisplayBugCheckScreen(unsigned int a1, _DWORD *a2, int a3, _DWORD *a4, char a5)
{
  int v6; // r6
  int v7; // r0
  int *v8; // r6
  int v9; // r7
  int v10; // r2
  int v11; // r2
  int v12; // r2
  unsigned __int16 *v13; // r0
  int v14; // r3
  int v15; // r0
  __int64 v20; // [sp+18h] [bp-30h] BYREF
  __int64 v21[5]; // [sp+20h] [bp-28h] BYREF

  if ( (dword_619018 & 4) != 0 && (dword_619018 & 0x400000) == 0 )
    return BcpDisplayEarlyBugCheckScreen(a1, a2, (int)a4);
  if ( (dword_619018 & 0x400000) != 0 || (dword_619018 & 0x10) == 0 )
  {
    BgpClearScreen(-16777216);
    v6 = 0;
  }
  else
  {
    v7 = BcpGetDisplayType(dword_618FC8, dword_618FC4, dword_618FCC, (int)a2);
    v8 = &dword_616150[14 * v7];
    v9 = v7;
    BgpClearScreen(*(_DWORD *)(*(_DWORD *)(dword_641660 + 20) + 28));
    BcpSetCursorPosition(*(_QWORD *)(v8 + 3), v8 + 4);
    if ( (dword_619018 & 0x20000) == 0 )
      BcpDisplayCriticalString((unsigned __int16 *)&dword_405C88, v8[2], v10, v9);
    v11 = v8[8];
    BcpCursor = v8[3] + v8[7];
    dword_653570 = dword_653574 + v11;
    BcpDisplayCriticalString(word_641610, v8[1], v11, v9);
    BcpDisplayCriticalCharacter(32, v8[1]);
    if ( (a5 & 1) == 0 )
    {
      if ( (a5 & 2) != 0 )
      {
        if ( (a5 & 4) != 0 )
          v13 = (unsigned __int16 *)&unk_641638;
        else
          v13 = (unsigned __int16 *)&unk_641628;
      }
      else if ( (a5 & 4) != 0 )
      {
        v13 = (unsigned __int16 *)&unk_641630;
      }
      else
      {
        v13 = (unsigned __int16 *)&unk_641620;
      }
      BcpDisplayCriticalString(v13, v8[1], v12, v9);
    }
    BcpDisplayCriticalCharacter(32, v8[1]);
    v14 = a5 & 4;
    LODWORD(v20) = v14;
    if ( (a5 & 4) == 0 )
      v14 = 1;
    if ( (a5 & 4) != 0 )
      v14 = 0;
    v6 = BcpGetMessageOffsets((unsigned int *)&ProgressOffset, &ErrorMessageOffset, v9, v14);
    if ( v6 >= 0 )
    {
      BcpSetCursorPosition(ErrorMessageOffset, (int *)&unk_618F18);
      BcpDisplayErrorInformation(v9, a1, (int)a2, a3, (int)a4, a5);
      if ( (_DWORD)v20 )
      {
        if ( (a5 & 2) == 0 )
        {
          KeQueryPerformanceCounter(&v20, v21);
          if ( !v21[0] )
            __brkdiv0();
          v15 = _rt_sdiv64(v21[0], v21[0] * (unsigned int)dword_989680);
          KeStallExecutionProcessor(v15);
        }
      }
      else
      {
        BcpSetCursorPosition(ProgressOffset, &dword_618F68);
        BcpDisplayProgress(0, v9);
        KeQueryPerformanceCounter(&v20, 0);
        BcpStartTicks = v20;
        BcpLastProgressUpdateTicks = v20;
        BcpLastProgressDisplayed = 0;
      }
      *a4 = word_641610;
      a4[1] = word_641618;
    }
  }
  return v6;
}
