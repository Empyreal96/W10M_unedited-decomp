// IopTimerDispatch 
 
signed int __fastcall IopTimerDispatch(signed int result, int a2, int a3, int a4)
{
  int *v4; // r8
  BOOL v5; // r6
  char v6; // r6
  int v7; // lr
  unsigned int v8; // r2
  int v9; // r10
  int i; // r4
  __int64 v11; // r0
  BOOL v12; // [sp+70h] [bp-100h]
  int v13; // [sp+70h] [bp-100h]
  unsigned __int64 v14; // [sp+EAh] [bp-86h]
  unsigned int v15; // [sp+122h] [bp-4Eh]
  unsigned int v16; // [sp+126h] [bp-4Ah]
  char v17; // [sp+132h] [bp-3Eh]
  _BYTE v18[48]; // [sp+140h] [bp-30h] BYREF
  __int64 savedregs; // [sp+170h] [bp+0h]

  v4 = (int *)a2;
  v5 = (dword_682608 & 0x800000) != 0;
  v12 = v5;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)result = 0;
    *(_DWORD *)(result + 16) = (unsigned __int64)a4 >> 8;
    v17 = a3;
    v6 = 64 - (a3 & 0x3F);
    LODWORD(v14) = ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F))) | ((unsigned int)a2 >> v6) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | (a2 << (a3 & 0x3F));
    HIDWORD(v14) = ((unsigned int)(a2 >> 31) >> v6) | ((unsigned __int64)((__int64)a2 << (a3 & 0x3F)) >> 32);
    v15 = (result << v6) | ((unsigned __int64)result >> (a3 & 0x3F));
    v16 = (result << (32 - (a3 & 0x3F))) | (result >> 31 << v6) | ((unsigned int)result >> ((a3 & 0x3F) - 32)) | ((unsigned int)(result >> 31) >> (a3 & 0x3F));
    *(_DWORD *)(result + 20) ^= a4;
    *(_DWORD *)(result + 24) ^= a3;
    KiCustomAccessRoutine1((unsigned int *)a2);
    v7 = (v15 >> (64 - (v17 & 0x3F))) | (v16 << ((v17 & 0x3F) - 32)) | (v16 >> (32 - (v17 & 0x3F))) | (v15 << (v17 & 0x3F));
    result = (HIDWORD(v14) << (64 - (v17 & 0x3F))) | ((unsigned int)v14 >> ((v17 & 0x3F) - 32)) | ((_DWORD)v14 << (32 - (v17 & 0x3F)));
    v4 = (int *)(((_DWORD)v14 << (64 - (v17 & 0x3F))) | (v14 >> (v17 & 0x3F)));
    *(_DWORD *)(v7 + 16) = v4;
    *(_BYTE *)v7 = 19;
    v5 = v12;
  }
  if ( *v4 )
  {
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&IopTimerLock);
    }
    else
    {
      do
        v8 = __ldrex((unsigned int *)&IopTimerLock);
      while ( __strex(1u, (unsigned int *)&IopTimerLock) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&IopTimerLock);
    }
    v9 = *v4;
    for ( i = IopTimerQueueHead; (int *)i != &IopTimerQueueHead; i = *(_DWORD *)i )
    {
      if ( !v9 )
        break;
      if ( *(_WORD *)(i - 2) )
      {
        if ( v5 )
        {
          HIDWORD(v11) = 1082130432;
          LODWORD(v11) = v18;
          EtwGetKernelTraceTimestamp(v11);
          (*(void (__fastcall **)(_DWORD, _DWORD))(i + 8))(*(_DWORD *)(i + 16), *(_DWORD *)(i + 12));
          EtwTraceTimedEvent(3910, 0x40800000u, i + 8, 4, 4196866, (int)v18);
        }
        else
        {
          (*(void (__fastcall **)(_DWORD, _DWORD))(i + 8))(*(_DWORD *)(i + 16), *(_DWORD *)(i + 12));
        }
        --v9;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&IopTimerLock, SHIDWORD(savedregs));
    }
    else
    {
      __dmb(0xBu);
      IopTimerLock = 0;
    }
    result = KfLowerIrql(v13);
  }
  return result;
}
