// KdSetDbgPrintBufferSize 
 
int __fastcall KdSetDbgPrintBufferSize(unsigned int a1)
{
  unsigned int v1; // r7
  char *v3; // r5
  unsigned __int64 v4; // r2
  int v5; // r1
  unsigned __int64 v6; // r2
  unsigned int v7; // r6
  int v8; // r2
  char *v9; // r8
  unsigned int v10; // r4
  int v11; // r3
  int v12; // r3
  int v13; // r3
  unsigned int i; // r2
  unsigned int v15; // r2
  unsigned int v16; // r2
  int v17; // [sp+0h] [bp-20h]

  v1 = a1;
  if ( KdPitchDebugger )
    return -1073740972;
  if ( a1 > 0x1000000 )
    return -1073741585;
  if ( a1 <= 0x1000 )
  {
    v1 = 4096;
    v3 = &KdPrintDefaultCircularBuffer;
    while ( 1 )
    {
LABEL_9:
      v4 = __PAIR64__(KdpPrintSpinLock, *(unsigned int *)algn_641D64);
      __dmb(0xBu);
      if ( !v4 )
      {
        v5 = KfRaiseIrql(15);
        v17 = v5;
        __dmb(0xBu);
        do
          v6 = __ldrexd((unsigned __int64 *)&KdpPrintSpinLock);
        while ( !v6 && __strexd(1ui64, (unsigned __int64 *)&KdpPrintSpinLock) );
        __dmb(0xBu);
        if ( !v6 )
        {
          dword_641D68 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
          v7 = 0;
          v8 = KdPrintBufferSize;
          v9 = KdPrintCircularBuffer;
          if ( v1 > KdPrintBufferSize )
          {
            v10 = KdPrintWritePointer - KdPrintCircularBuffer;
            if ( KdPrintWritePointer - KdPrintCircularBuffer >= (unsigned int)KdPrintBufferSize )
            {
              v10 = 0;
              __dmb(0xBu);
              KdPrintRolloverCount = 0;
            }
            v11 = KdPrintRolloverCount;
            __dmb(0xBu);
            if ( v11 )
            {
              v7 = v8 - v10;
              memmove((int)v3, (int)&v9[v10], v8 - v10);
            }
            memmove((int)&v3[v7], (int)v9, v10);
            v7 += v10;
            v12 = KdPrintRolloverCount;
            __dmb(0xBu);
            if ( v12 )
            {
              v13 = (unsigned __int8)*v3;
              for ( i = 0; v13 && i < v7; v13 = (unsigned __int8)v3[i] )
                ++i;
              v15 = i + 1;
              if ( v15 < v7 )
              {
                v7 -= v15;
                memmove((int)v3, (int)&v3[v15], v7);
              }
            }
          }
          memset(&v3[v7], 0, v1 - v7);
          KdPrintCircularBuffer = v3;
          KdPrintBufferSize = v1;
          KdPrintWritePointer = &v3[v7];
          __dmb(0xBu);
          KdPrintRolloverCount = 0;
          ++KdPrintBufferChanges;
          dword_641D68 = 0;
          __dmb(0xBu);
          do
            v16 = __ldrex((unsigned int *)&KdpPrintSpinLock);
          while ( __strex(0, (unsigned int *)&KdpPrintSpinLock) );
          __dmb(0xBu);
          KfLowerIrql(v17);
          if ( v9 )
          {
            if ( v9 != &KdPrintDefaultCircularBuffer )
              ExFreePoolWithTag(v9);
          }
          return 0;
        }
        KfLowerIrql(v5);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v3 = (char *)ExAllocatePoolWithTag(512, a1);
  if ( v3 )
    goto LABEL_9;
  return -1073741801;
}
