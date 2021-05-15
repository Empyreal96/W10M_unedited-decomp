// KdpSendWaitContinue 
 
int __fastcall KdpSendWaitContinue(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int result; // r0
  int v9; // r0
  int v10; // r0
  __int16 v11[2]; // [sp+18h] [bp-108h] BYREF
  void *v12; // [sp+1Ch] [bp-104h]
  int v13; // [sp+20h] [bp-100h]
  int v14; // [sp+24h] [bp-FCh]
  int v15; // [sp+28h] [bp-F8h] BYREF
  int v16; // [sp+2Ch] [bp-F4h] BYREF
  __int16 v17; // [sp+32h] [bp-EEh]
  int *v18; // [sp+34h] [bp-ECh]
  __int16 v19; // [sp+38h] [bp-E8h]
  int *v20; // [sp+3Ch] [bp-E4h]
  __int16 v21; // [sp+40h] [bp-E0h]
  int *v22; // [sp+44h] [bp-DCh]
  int v23[2]; // [sp+48h] [bp-D8h] BYREF
  __int16 v24; // [sp+50h] [bp-D0h]
  int *v25; // [sp+54h] [bp-CCh]
  __int16 v26; // [sp+58h] [bp-C8h]
  int *v27; // [sp+5Ch] [bp-C4h]
  __int16 v28; // [sp+60h] [bp-C0h]
  int *v29; // [sp+64h] [bp-BCh]
  int v30[2]; // [sp+68h] [bp-B8h] BYREF
  __int16 v31; // [sp+70h] [bp-B0h]
  int *v32; // [sp+74h] [bp-ACh]
  __int16 v33; // [sp+78h] [bp-A8h]
  int *v34; // [sp+7Ch] [bp-A4h]
  __int16 v35; // [sp+80h] [bp-A0h]
  int *v36; // [sp+84h] [bp-9Ch]
  __int16 v37; // [sp+88h] [bp-98h]
  int *v38; // [sp+8Ch] [bp-94h]
  __int16 v39; // [sp+90h] [bp-90h]
  int *v40; // [sp+94h] [bp-8Ch]
  __int16 v41; // [sp+98h] [bp-88h]
  int *v42; // [sp+9Ch] [bp-84h]
  __int16 v43; // [sp+A0h] [bp-80h]
  int *v44; // [sp+A4h] [bp-7Ch]
  __int16 v45; // [sp+A8h] [bp-78h]
  int *v46; // [sp+ACh] [bp-74h]
  __int16 v47; // [sp+B0h] [bp-70h]
  int *v48; // [sp+B4h] [bp-6Ch]
  char v49[8]; // [sp+C0h] [bp-60h] BYREF
  int v50; // [sp+C8h] [bp-58h] BYREF
  int v51[21]; // [sp+CCh] [bp-54h] BYREF

  v50 = 0;
  v13 = a3;
  v14 = a2;
  memset(v51, 0, 52);
  v18 = &v50;
  v11[1] = 4096;
  v17 = 56;
  v12 = &KdpMessageBuffer;
  KdpContextSent = 0;
  KdSendPacket_0();
  while ( !KdDebuggerNotPresent )
  {
    while ( 1 )
    {
      if ( KeNumberProcessors_0 == 1 )
        KeQueryPerformanceCounter(v49, 0);
      ReadTimeStampCounter();
      v5 = KdReceivePacket_0();
      if ( v5 == 2 )
        break;
      if ( v5 != 1 )
      {
        v7 = v50 - 12592;
        switch ( v50 )
        {
          case 12592:
            KdpReadVirtualMemory(&v50, v11);
            continue;
          case 12593:
            v9 = KdpCopyMemoryChunks(v51[3], v51[4], (int)v12, (unsigned __int16)v11[0], 0, 5, &v51[6]);
            v37 = 56;
            v38 = &v50;
            goto LABEL_21;
          case 12594:
            v45 = 56;
            v46 = &v50;
            v10 = KdpGetContext(&v50, v11);
            if ( v51[1] )
              JUMPOUT(0x903BA2);
            return sub_903B9C(v10);
          case 12595:
            KdpSetContext(&v50, v11, a4);
            continue;
          case 12596:
            KdpWriteBreakpoint(&v50);
            continue;
          case 12597:
            v28 = 56;
            v29 = &v50;
            if ( KdpDeleteBreakpoint(v51[3]) )
              v51[1] = 0;
            else
              v51[1] = -1073741823;
            goto LABEL_13;
          case 12598:
          case 12604:
            return v51[3] >= 0;
          case 12599:
            KdpReadControlSpace(&v50, v11);
            continue;
          case 12600:
            v31 = 56;
            v32 = &v50;
            v51[1] = KdpSysWriteControlSpace(HIWORD(v51[0]), v6, v51[3], v51[4], v12, (unsigned __int16)v11[0], &v16);
            v51[6] = v16;
            goto LABEL_13;
          case 12601:
            v19 = 56;
            v20 = &v50;
            v51[6] = 0;
            v9 = HvlQueryActiveProcessors();
            goto LABEL_21;
          case 12602:
            v35 = 56;
            v36 = &v50;
            v9 = HvlQueryActiveProcessors();
            goto LABEL_21;
          case 12603:
            off_617AFC(0);
            HalReturnToFirmware(3);
            return result;
          case 12605:
            KdpReadPhysicalMemory(&v50, v11);
            continue;
          case 12606:
            KdpWritePhysicalMemory(&v50, v11);
            continue;
          case 12608:
          case 12609:
          case 12610:
          case 12634:
            continue;
          case 12612:
            v41 = 56;
            v42 = &v50;
            v51[9] = 0;
            v9 = HvlQueryActiveProcessors();
            goto LABEL_21;
          case 12613:
            v21 = 56;
            v22 = &v50;
            v9 = HvlQueryActiveProcessors();
            goto LABEL_21;
          case 12614:
            v47 = 56;
            v48 = &v50;
            memmove((int)&v51[3], (int)&KdVersionBlock, 0x28u);
            v51[1] = 0;
            v50 = 12614;
            goto LABEL_13;
          case 12615:
            if ( !KdpWriteBreakPointEx(&v50, v11) )
              continue;
            return 0;
          case 12616:
            KdpRestoreBreakPointEx(&v50, v11);
            continue;
          case 12617:
            KdExitDebugger(0, v6, v7, v50);
            KeBugCheckEx(226, 0, 0, 0, 0);
          case 12624:
            return KeSwitchFrozenProcessor(HIWORD(v51[0]), v6, v7, v50);
          case 12625:
            v33 = 56;
            v34 = &v50;
            goto LABEL_41;
          case 12626:
            v26 = 56;
            v27 = &v50;
            v9 = KdpSysReadMsr(v51[3], v23);
            v51[4] = v23[0];
            v51[5] = v23[1];
            goto LABEL_21;
          case 12627:
            v39 = 56;
            v40 = &v50;
            v30[1] = v51[5];
            v30[0] = v51[4];
            v9 = KdpSysWriteMsr(v51[3], v30);
            goto LABEL_21;
          case 12630:
            KdpSearchMemory(&v50, v11);
            continue;
          case 12631:
            KdpGetBusData(&v50, v11);
            continue;
          case 12632:
            v43 = 56;
            v44 = &v50;
            v9 = KdpSysWriteBusData(v51[3], v51[4], v51[5], v51[6], v12, v51[7], &v15);
            v51[7] = v15;
            goto LABEL_21;
          case 12633:
            v24 = 56;
            v25 = &v50;
            v9 = KdpSysCheckLowMemory(4);
LABEL_21:
            v51[1] = v9;
            goto LABEL_13;
          case 12635:
            KdpFillMemory(&v50, v11);
            continue;
          case 12636:
            KdpQueryMemory(&v50);
            continue;
          case 12639:
            KdpGetContextEx(&v50, v11, a4, v50);
            continue;
          case 12640:
            KdpSetContextEx((int)&v50, (int)v11, a4);
            continue;
          case 12641:
            KdpWriteCustomBreakpoint((int)&v50, v6);
            continue;
          case 12642:
            KdpReadPhysicalMemoryLong(&v50, v11);
            continue;
          default:
            v11[0] = 0;
LABEL_41:
            v51[1] = -1073741823;
LABEL_13:
            KdSendPacket_0();
            break;
        }
      }
    }
    KdSendPacket_0();
  }
  return 1;
}
