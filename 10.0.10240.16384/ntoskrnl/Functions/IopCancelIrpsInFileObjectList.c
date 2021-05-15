// IopCancelIrpsInFileObjectList 
 
int __fastcall IopCancelIrpsInFileObjectList(int a1, int a2, int a3, int a4, char a5, char a6)
{
  _DWORD *v7; // r10
  unsigned int *v8; // r5
  int v9; // r7
  unsigned int v11; // r2
  _DWORD *v12; // r9
  BOOL v13; // r6
  int v14; // r0
  _DWORD *v15; // r4
  int v16; // r6
  unsigned int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r4
  unsigned int v21; // r2
  int v22; // [sp+8h] [bp-48h] BYREF
  int v23; // [sp+Ch] [bp-44h]
  int v24; // [sp+10h] [bp-40h]
  int v25; // [sp+14h] [bp-3Ch]
  int v26; // [sp+18h] [bp-38h]
  int v27; // [sp+1Ch] [bp-34h]
  int v28; // [sp+20h] [bp-30h]
  int v29; // [sp+24h] [bp-2Ch]
  __int64 v30[5]; // [sp+28h] [bp-28h] BYREF

  v25 = a4;
  v26 = a3;
  v22 = 0;
  v24 = 0;
  v27 = a2;
  v28 = a1;
  v7 = 0;
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 112);
  v29 = 0;
  v23 = 1;
  v30[0] = -10000i64;
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_529B28();
  do
    v11 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForSpinLockAndAcquire(v8);
  if ( a6 )
    *(_DWORD *)(a1 + 44) |= 0x400u;
  v12 = (_DWORD *)(a1 + 116);
  while ( (_DWORD *)*v12 != v12 )
  {
    v13 = v7 != 0;
    v14 = IopCheckListForCancelableIrp(v12, v27, v26, v25, v7, &v22);
    v15 = (_DWORD *)v22;
    v7 = 0;
    if ( v22 )
    {
      if ( !*(_BYTE *)(v22 + 36) )
      {
        v24 = 1;
        *(_BYTE *)(v22 + 36) = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v8);
        }
        else
        {
          __dmb(0xBu);
          *v8 = 0;
        }
        KfLowerIrql(v9);
        IoCancelIrp(v15);
        v16 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v8);
        }
        else
        {
          do
            v17 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( v17 )
            KxWaitForSpinLockAndAcquire(v8);
        }
        v9 = v16;
      }
      if ( (v15[2] & 0x2000) != 0 )
        v7 = (_DWORD *)v15[4];
      if ( !sub_456A04(v15 + 12, -1) )
        pIoFreeIrp(v15);
      if ( v7 == v12 )
      {
        if ( !a5 )
          break;
        v7 = 0;
      }
    }
    else
    {
      if ( !a5 )
        break;
      if ( v14 )
      {
        if ( !v13 )
          break;
      }
      else
      {
        v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v28 + 4) + 8) + 44);
        __dmb(0xBu);
        v29 = v18;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v8);
        }
        else
        {
          __dmb(0xBu);
          *v8 = 0;
        }
        KfLowerIrql(v9);
        KeDelayExecutionThread(0, 0, (unsigned int *)v30);
        v19 = v23;
        if ( v23 < 100 )
        {
          v23 *= 2;
          v30[0] = -20000 * v19;
        }
        v20 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v8);
        }
        else
        {
          do
            v21 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( v21 )
            KxWaitForSpinLockAndAcquire(v8);
        }
        v9 = v20;
      }
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  KfLowerIrql(v9);
  return v24;
}
