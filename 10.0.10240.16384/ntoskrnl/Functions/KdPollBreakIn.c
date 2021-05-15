// KdPollBreakIn 
 
int __fastcall KdPollBreakIn(int a1, int a2)
{
  int v3; // r7
  int v4; // r10
  int v5; // r8
  _DWORD *v6; // r1
  _DWORD *v7; // r4
  __int64 v8; // r0
  int v9; // r1
  unsigned int v10; // r2
  int v11; // r0
  int *v12; // r2
  int *v13; // r6
  __int64 v14; // r0
  __int64 v15; // kr00_8
  int v16; // r2
  int v17; // [sp+8h] [bp-20h]
  int v18; // [sp+8h] [bp-20h]

  if ( KdPitchDebugger )
    return sub_54246C(a1, a2, (unsigned __int8)KdEventLoggingEnabled);
  v3 = 0;
  if ( KdDebuggerEnabled || KdEventLoggingEnabled )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v4 = 0;
    }
    else
    {
      __disable_irq();
      v4 = 1;
    }
    v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    v6 = (_DWORD *)KdLogBuffer[v5];
    if ( v6 )
    {
      v7 = &v6[4 * *v6 + 4];
      LODWORD(v8) = ReadTimeStampCounter();
      *(_QWORD *)v7 = v8;
      v7[2] = 4 * (KdDebuggerNotPresent & 1);
      v7[3] = 0;
    }
    v17 = KfRaiseIrql(15);
    if ( byte_62F974 )
    {
      LOBYTE(v3) = 1;
      byte_62F974 = 0;
    }
    else
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v11 = KiTryToAcquireSpinLockInstrumented(&KdDebuggerLock, v9);
      }
      else
      {
        do
          v10 = __ldrex((unsigned int *)&KdDebuggerLock);
        while ( __strex(1u, (unsigned int *)&KdDebuggerLock) );
        __dmb(0xBu);
        v11 = v10 == 0;
        if ( !v10 )
          goto LABEL_12;
        __dmb(0xAu);
        __yield();
      }
      if ( v11 )
      {
LABEL_12:
        if ( !KdReceivePacket_0(8, 0, 0) )
          LOBYTE(v3) = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&KdDebuggerLock);
        }
        else
        {
          __dmb(0xBu);
          KdDebuggerLock = 0;
        }
        goto LABEL_16;
      }
    }
LABEL_16:
    v3 = (unsigned __int8)(v3 & KdDebuggerEnabled);
    KdpControlCPressed |= v3;
    KfLowerIrql(v17);
    v12 = (int *)KdLogBuffer[v5];
    if ( v12 )
    {
      v18 = *v12;
      v13 = &v12[4 * *v12 + 4];
      LODWORD(v14) = ReadTimeStampCounter();
      v15 = v14 - *(_QWORD *)v13;
      v13[2] = v15 & 0xFFFFFFF0 | (2 * (KdDebuggerNotPresent & 1)) | v13[2] & 4;
      v13[3] = HIDWORD(v15);
      if ( v18 == 254 )
        v16 = 0;
      else
        v16 = v18 + 1;
      *(_DWORD *)KdLogBuffer[v5] = v16;
    }
    if ( v4 )
      __enable_irq();
  }
  return v3;
}
