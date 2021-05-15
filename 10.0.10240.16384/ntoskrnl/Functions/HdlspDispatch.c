// HdlspDispatch 
 
int __fastcall HdlspDispatch(int a1, unsigned __int16 *a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v6; // r4
  int v7; // r6
  __int64 v8; // r0
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r0
  bool v16; // r3
  unsigned int v17; // r7
  int v18; // r3
  char v19; // r0
  int v20; // r3
  unsigned int v21; // r3
  int v22; // r2
  int v23; // r3
  const char *v24; // r0
  char var70[116]; // [sp+10h] [bp-70h] BYREF
  int vars4; // [sp+84h] [bp+4h]

  v6 = a1;
  v7 = 0;
  HIDWORD(v8) = 0;
  if ( a1 == 17 || a1 == 14 || a1 == 20 || a1 == 15 )
  {
    v10 = HeadlessGlobals;
  }
  else
  {
    v10 = HeadlessGlobals;
    if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
    {
      v11 = 255;
    }
    else
    {
      v11 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v10);
      }
      else
      {
        do
          v12 = __ldrex((unsigned int *)v10);
        while ( __strex(1u, (unsigned int *)v10) );
        __dmb(0xBu);
        if ( v12 )
          KxWaitForSpinLockAndAcquire((unsigned int *)v10);
      }
      v10 = HeadlessGlobals;
      HIDWORD(v8) = 0;
    }
    v13 = *(_DWORD *)(v10 + 24);
    if ( (v13 & 0x40) != 0 )
    {
      if ( v11 != 255 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)v10, vars4);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v10 = 0;
        }
        KfLowerIrql(v11);
      }
      return -1073741823;
    }
    *(_DWORD *)(v10 + 24) = v13 | 0x40;
    if ( v11 != 255 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)v10, vars4);
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v10 = 0;
      }
      v8 = KfLowerIrql(v11);
      v10 = HeadlessGlobals;
    }
    v6 = a1;
  }
  v14 = v6 - 1;
  switch ( v6 )
  {
    case 1:
      if ( !a2 || a3 != 1 )
        goto LABEL_130;
      v15 = HdlspEnableTerminal(*(unsigned __int8 *)a2);
      goto LABEL_117;
    case 2:
      if ( !a4 || !a5 || *a5 != 1 )
        goto LABEL_130;
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_68;
      if ( HdlspGetLine(var70, 80) )
      {
        v16 = !strcmp((int)var70, (unsigned int *)"reboot") || !strcmp((int)var70, (unsigned int *)"shutdown");
        *(_BYTE *)a4 = v16;
      }
      goto LABEL_44;
    case 3:
      if ( !a2 )
        goto LABEL_130;
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_45;
      HdlspPutString(a2, HIDWORD(v8));
      goto LABEL_44;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_45;
      switch ( v6 )
      {
        case 4:
          v24 = "\x1B[2J";
          goto LABEL_113;
        case 5:
          v24 = "\x1B[0J";
          goto LABEL_113;
        case 6:
          v24 = "\x1B[0K";
          goto LABEL_113;
        case 7:
          v24 = "\x1B[0m";
          goto LABEL_113;
        case 8:
          v24 = "\x1B[7m";
          goto LABEL_113;
        case 9:
          if ( a2 && a3 == 8 )
          {
            sprintf_s((int)var70, 80, (int)"\x1B[%d;%dm", *((_DWORD *)a2 + 1), *(_DWORD *)a2);
            goto LABEL_107;
          }
LABEL_103:
          v7 = -1073741811;
          goto LABEL_135;
        case 10:
          if ( a2 && a3 == 8 )
          {
            sprintf_s((int)var70, 80, (int)"\x1B[%d;%dH", *((_DWORD *)a2 + 1) + 1, *(_DWORD *)a2 + 1);
LABEL_107:
            v24 = var70;
LABEL_113:
            HdlspSendStringAtBaud(v24);
LABEL_44:
            v10 = HeadlessGlobals;
LABEL_45:
            v7 = 0;
            goto LABEL_131;
          }
          goto LABEL_103;
      }
LABEL_130:
      v7 = -1073741811;
LABEL_131:
      if ( v6 != 17 && v6 != 14 && v6 != 20 && v6 != 15 )
LABEL_135:
        *(_DWORD *)(v10 + 24) &= 0xFFFFFFBF;
      return v7;
    case 11:
      if ( !a4 || !a5 || *a5 != 1 )
        goto LABEL_130;
      v18 = *(_DWORD *)(v10 + 24);
      if ( (v18 & 1) == 0 )
        goto LABEL_68;
      v19 = InbvPortPollOnly(*(_DWORD *)(v10 + 32), SHIDWORD(v8), v14, v18);
      goto LABEL_60;
    case 12:
      if ( !a4 || !a5 || *a5 != 1 )
        goto LABEL_130;
      v20 = *(_DWORD *)(v10 + 24);
      if ( (v20 & 1) == 0 )
        goto LABEL_68;
      if ( InbvPortPollOnly(*(_DWORD *)(v10 + 32), SHIDWORD(v8), v14, v20) )
      {
        InbvPortGetByte(*(_DWORD *)(HeadlessGlobals + 32), a4);
        goto LABEL_44;
      }
      v10 = HeadlessGlobals;
LABEL_68:
      *(_BYTE *)a4 = 0;
      goto LABEL_45;
    case 13:
      if ( !a4 || !a5 || *a5 < 2u )
        goto LABEL_130;
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_68;
      v19 = HdlspGetLine(a4 + 1, *a5 - 1);
LABEL_60:
      *(_BYTE *)a4 = v19;
      goto LABEL_44;
    case 14:
      *(_DWORD *)(v10 + 24) = *(_DWORD *)(v10 + 24) & 0xFFFFFFBF | 2;
      goto LABEL_45;
    case 15:
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_45;
      HdlspBugCheckProcessing();
      goto LABEL_44;
    case 16:
      if ( !a4 || !a5 || *a5 < 0x18u )
        goto LABEL_130;
      *(_DWORD *)a4 = 1;
      *(_BYTE *)(a4 + 4) = 1;
      *(_BYTE *)(a4 + 5) = (*(_DWORD *)(v10 + 24) & 8) != 0;
      *(_DWORD *)(a4 + 16) = *(_DWORD *)(v10 + 28);
      v21 = *(_DWORD *)(v10 + 24);
      v22 = (v21 >> 9) & 7;
      if ( v22 || (v21 & 8) != 0 )
      {
        *(_DWORD *)(a4 + 8) = v22;
        v23 = *(_DWORD *)(v10 + 36);
      }
      else
      {
        v23 = 0;
        *(_DWORD *)(a4 + 8) = 0;
      }
      *(_DWORD *)(a4 + 12) = v23;
      *(_BYTE *)(a4 + 20) = *(_BYTE *)(v10 + 52);
      goto LABEL_45;
    case 17:
      if ( !a2 )
        goto LABEL_130;
      HdlspAddLogEntry(a2);
      goto LABEL_87;
    case 18:
      if ( !a2 || a3 != 1 )
        goto LABEL_130;
      HdlspProcessDumpCommand(*(unsigned __int8 *)a2);
LABEL_87:
      v7 = 0;
      goto LABEL_88;
    case 19:
      if ( !a2 )
        return -1073741811;
      v15 = HdlspSetBlueScreenInformation(a2, a3);
LABEL_117:
      v7 = v15;
      goto LABEL_88;
    case 20:
      if ( (*(_DWORD *)(v10 + 24) & 3) != 3 )
        goto LABEL_131;
      if ( !a2 || a3 != 4 )
        return -1073741811;
      HdlspSendBlueScreenInfo(*(_DWORD *)a2);
      HdlspSendStringAtBaud("\n\r!SAC>");
LABEL_88:
      v10 = HeadlessGlobals;
      goto LABEL_131;
    case 21:
      if ( !a4 || !a5 || *a5 < 0x10u )
        goto LABEL_130;
      *(_DWORD *)a4 = *(_DWORD *)(v10 + 64);
      *(_DWORD *)(a4 + 4) = *(_DWORD *)(v10 + 68);
      *(_DWORD *)(a4 + 8) = *(_DWORD *)(v10 + 72);
      *(_DWORD *)(a4 + 12) = *(_DWORD *)(v10 + 76);
      goto LABEL_45;
    case 22:
      if ( !a2 || !a3 )
        goto LABEL_130;
      if ( (*(_DWORD *)(v10 + 24) & 1) != 0 )
      {
        v17 = 0;
        do
        {
          InbvPortPutByte(*(_DWORD *)(v10 + 32));
          ++v17;
          v10 = HeadlessGlobals;
        }
        while ( v17 < a3 );
      }
      goto LABEL_45;
    case 23:
      if ( !a2 )
        goto LABEL_130;
      if ( (*(_DWORD *)(v10 + 24) & 1) == 0 )
        goto LABEL_45;
      HdlspPutWideString(a2, HIDWORD(v8));
      goto LABEL_44;
    case 24:
      if ( !a4 || !a5 || *a5 < 0xCu )
        goto LABEL_130;
      *(_DWORD *)a4 = *(_DWORD *)(v10 + 82);
      *(_DWORD *)(a4 + 4) = *(_DWORD *)(v10 + 86);
      *(_DWORD *)(a4 + 8) = *(_DWORD *)(v10 + 90);
      goto LABEL_45;
    default:
      goto LABEL_130;
  }
}
