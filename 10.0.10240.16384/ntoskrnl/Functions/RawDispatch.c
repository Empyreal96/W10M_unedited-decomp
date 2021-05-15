// RawDispatch 
 
int __fastcall RawDispatch(int a1, int a2)
{
  unsigned __int8 *v3; // r4
  int v4; // r2
  int v5; // r4
  unsigned int v6; // r2
  _DWORD *v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r0
  unsigned __int8 *v11; // r8
  int v12; // r9
  int v13; // r10
  unsigned int v14; // r2
  int v15; // r5
  unsigned int v16; // r1
  int v17; // r9
  unsigned int v18; // r1
  unsigned int v19; // r1
  __int16 v20; // r3

  v3 = *(unsigned __int8 **)(a2 + 96);
  if ( *(_WORD *)(a1 + 2) != 184 || (v4 = *v3, v4 == 13) && v3[1] == 1 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = (_DWORD *)(a1 + 184);
    switch ( *v3 )
    {
      case 0u:
        v8 = RawCreate(a1 + 184, a2, v3);
        goto LABEL_49;
      case 2u:
        v8 = RawClose(a1 + 184, a2, v3);
        goto LABEL_49;
      case 3u:
      case 4u:
      case 9u:
      case 0xEu:
        goto LABEL_45;
      case 5u:
        v8 = RawQueryInformation(a1 + 184, a2, v3);
        goto LABEL_49;
      case 6u:
        v8 = RawSetInformation(a1 + 184, a2, v3);
        goto LABEL_49;
      case 0xAu:
        v8 = RawQueryVolumeInformation(a1 + 184, a2, v3);
        goto LABEL_49;
      case 0xDu:
        v9 = v3[1];
        if ( v3[1] )
        {
          if ( v9 == 1 )
          {
            v10 = RawMountVolume(v3);
          }
          else
          {
            if ( v9 != 2 )
            {
              v5 = -1073741808;
              goto LABEL_23;
            }
            v10 = RawVerifyVolume((int)v3, a1 + 184);
          }
        }
        else
        {
          v10 = RawUserFsCtrl(a2, v3, a1 + 184);
        }
        v5 = v10;
LABEL_23:
        *(_DWORD *)(a2 + 24) = v5;
        v8 = IofCompleteRequest(a2, 1);
LABEL_50:
        v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v20 = *(_WORD *)(v19 + 0x134) + 1;
        *(_WORD *)(v19 + 308) = v20;
        if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
          KiCheckForKernelApcDelivery(v8);
        break;
      case 0x12u:
        v8 = RawCleanup(a1 + 184, a2, v3);
        goto LABEL_49;
      case 0x1Bu:
        if ( v3[1] == 1 )
        {
          v5 = -2147483631;
          *(_DWORD *)(a2 + 24) = -2147483631;
          v8 = IofCompleteRequest(a2, 1);
        }
        else
        {
          v11 = (unsigned __int8 *)(a1 + 344);
          v12 = KeAbPreAcquire(a1 + 344, 0, 0);
          v13 = KfRaiseIrql(1);
          do
            v14 = __ldrex(v11);
          while ( __strex(v14 & 0xFE, v11) );
          __dmb(0xBu);
          if ( (v14 & 1) == 0 )
            ExpAcquireFastMutexContended((int)(v7 + 40), v12);
          if ( v12 )
            *(_BYTE *)(v12 + 14) |= 1u;
          v7[41] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v7[47] = v13;
          if ( (v7[18] & 2) != 0 )
          {
            v5 = -1073741202;
            *(_DWORD *)(a2 + 24) = -1073741202;
            IofCompleteRequest(a2, 1);
            v7[41] = 0;
            v15 = v7[47];
            __dmb(0xBu);
            do
              v16 = __ldrex((unsigned int *)v11);
            while ( !v16 && __strex(1u, (unsigned int *)v11) );
            if ( v16 )
              ExpReleaseFastMutexContended(v7 + 40, v16);
            KfLowerIrql((unsigned __int8)v15);
            v8 = KeAbPostRelease((unsigned int)(v7 + 40));
          }
          else
          {
            ++v7[20];
            v7[41] = 0;
            v17 = v7[47];
            __dmb(0xBu);
            do
              v18 = __ldrex((unsigned int *)v11);
            while ( !v18 && __strex(1u, (unsigned int *)v11) );
            if ( v18 )
              ExpReleaseFastMutexContended(v7 + 40, v18);
            KfLowerIrql((unsigned __int8)v17);
            KeAbPostRelease((unsigned int)(v7 + 40));
LABEL_45:
            v8 = RawReadWriteDeviceControl(v7, a2, v3);
LABEL_49:
            v5 = v8;
          }
        }
        goto LABEL_50;
      default:
        KeBugCheckEx(34, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( !*v3 || v4 == 18 || v4 == 2 )
      v5 = 0;
    else
      v5 = -1073741808;
    *(_DWORD *)(a2 + 24) = v5;
    IofCompleteRequest(a2, 1);
  }
  return v5;
}
