// KeDisableTimer2 
 
int __fastcall KeDisableTimer2(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r8
  int v7; // r10
  int v9; // r7
  int v10; // r9
  int v11; // r1
  int v12; // [sp+0h] [bp-78h]
  int v14; // [sp+10h] [bp-68h]
  int v15; // [sp+14h] [bp-64h]
  int v17; // [sp+1Ch] [bp-5Ch]
  __int16 v18[2]; // [sp+38h] [bp-40h] BYREF
  int v19; // [sp+3Ch] [bp-3Ch]
  int v20; // [sp+40h] [bp-38h]

  v15 = 0;
  v6 = 0;
  v7 = 0;
  v14 = 32;
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_523CB8();
  if ( a4 )
  {
    v11 = KiWaitNever;
    v7 = __ROR4__(bswap32(KiWaitAlways ^ *a4) ^ a1, v11) ^ v11;
    v15 = __ROR4__(bswap32(KiWaitAlways ^ a4[1]) ^ a1, v11) ^ v11;
  }
  v17 = KfRaiseIrql(2);
  if ( !KiAcquireTimer2LockUnlessDisabled(a1) )
  {
    if ( a4 )
    {
      *(_DWORD *)(a1 + 72) = v7;
      *(_DWORD *)(a1 + 76) = v15;
    }
    if ( !a2 )
      goto LABEL_11;
    if ( KiAcquireTimer2CollectionLockIfInserted(a1) )
    {
      KiRemoveTimer2(a1);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
      }
      else
      {
        __dmb(0xBu);
        KiTimer2CollectionLock = 0;
      }
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 1) & 0xA) == 0 )
      {
LABEL_11:
        v9 = 6;
        goto LABEL_12;
      }
      v14 = 36;
    }
    v6 = 1;
    v9 = 4;
LABEL_12:
    v10 = KiUpdateTimer2Flags(a1, v14, v9);
    KfLowerIrql(v17);
    if ( !v10 )
    {
      if ( a3 )
      {
        v18[0] = 1;
        v18[1] = 1;
        v19 = 0;
        v20 = 1 << KiClockTimerOwner;
        KeGenericProcessorCallback(v18, (int)PopPoCoalescinCallback, 0, 2, v12);
      }
    }
    return v6;
  }
  KfLowerIrql(v17);
  return v6;
}
