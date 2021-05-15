// IopKeepAliveWorker 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopKeepAliveWorker(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v5; // r1
  int v6; // r5
  int v7; // r6
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  int v10; // r3
  int v11; // r6
  int v12; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r6
  unsigned int v16; // r1
  unsigned int v17; // r1
  __int64 v19; // [sp+0h] [bp-28h] BYREF
  int v20; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  HIDWORD(v19) = a3;
  v20 = a4;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)dword_631A78);
  }
  else
  {
    do
      v5 = __ldrex(dword_631A78);
    while ( __strex(1u, dword_631A78) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(dword_631A78);
  }
  dword_631A94 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  while ( 1 )
  {
    v6 = dword_631A70;
    if ( (int *)dword_631A70 == &dword_631A70 )
      break;
    v7 = *(_DWORD *)(dword_631A70 + 16);
    *(_DWORD *)(dword_631A70 + 16) = 0;
    if ( v7 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(dword_631A78, vars4);
      }
      else
      {
        __dmb(0xBu);
        dword_631A78[0] = 0;
      }
      KfLowerIrql(v4);
      if ( v7 <= 0 )
      {
        if ( v7 != -1 )
        {
          v11 = -1 - v7;
          do
          {
            PspAdjustKeepAliveCountProcess(
              *(_DWORD *)(v6 + 12),
              -1,
              *(_DWORD *)(v6 + 20),
              *(unsigned __int8 *)(v6 + 10));
            ObfDereferenceObjectWithTag(*(_DWORD *)(v6 + 12));
            --v11;
          }
          while ( v11 );
        }
        v12 = *(_DWORD *)(v6 + 12);
        if ( *(_BYTE *)(v6 + 10) )
          v13 = *(_DWORD *)(v12 + 784) & 0x7FFFFFFF;
        else
          v13 = *(_DWORD *)(v12 + 788);
        if ( v13 == 1 )
        {
          v15 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented((int)dword_631A78);
          }
          else
          {
            do
              v16 = __ldrex(dword_631A78);
            while ( __strex(1u, dword_631A78) );
            __dmb(0xBu);
            if ( v16 )
              KxWaitForSpinLockAndAcquire(dword_631A78);
          }
          KeQuerySystemTime(&v19);
          if ( v19 < *(_QWORD *)(v6 + 24) )
          {
            --*(_DWORD *)(v6 + 16);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(dword_631A78, vars4);
            }
            else
            {
              __dmb(0xBu);
              dword_631A78[0] = 0;
            }
            KfLowerIrql(v15);
            KeDelayExecutionThread(0, 1, (unsigned int *)(v6 + 24));
            goto LABEL_42;
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(dword_631A78, vars4);
          }
          else
          {
            __dmb(0xBu);
            dword_631A78[0] = 0;
          }
          KfLowerIrql(v15);
          v14 = *(unsigned __int8 *)(v6 + 10);
          v12 = *(_DWORD *)(v6 + 12);
        }
        else
        {
          v14 = *(unsigned __int8 *)(v6 + 10);
        }
        PspAdjustKeepAliveCountProcess(v12, -1, *(_DWORD *)(v6 + 20), v14);
        ObfDereferenceObjectWithTag(*(_DWORD *)(v6 + 12));
      }
      else
      {
        do
        {
          ObfReferenceObjectWithTag(*(_DWORD *)(v6 + 12));
          PspAdjustKeepAliveCountProcess(*(_DWORD *)(v6 + 12), 1, *(_DWORD *)(v6 + 20), *(unsigned __int8 *)(v6 + 10));
          --v7;
        }
        while ( v7 );
      }
LABEL_42:
      v4 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)dword_631A78);
      }
      else
      {
        do
          v17 = __ldrex(dword_631A78);
        while ( __strex(1u, dword_631A78) );
        __dmb(0xBu);
        if ( v17 )
          KxWaitForSpinLockAndAcquire(dword_631A78);
      }
    }
    else
    {
      *(_QWORD *)&v8 = *(_QWORD *)v6;
      if ( *(_DWORD *)(*(_DWORD *)v6 + 4) != v6 || *v9 != v6 )
        __fastfail(3u);
      *v9 = v8;
      *(_DWORD *)(v8 + 4) = v9;
      v10 = *(unsigned __int8 *)(v6 + 9);
      *(_BYTE *)(v6 + 8) = 0;
      if ( v10 == 1 )
        ExFreePoolWithTag(v6);
    }
  }
  byte_631A90 = 0;
  dword_631A94 = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(dword_631A78, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_631A78[0] = 0;
  }
  return KfLowerIrql(v4);
}
