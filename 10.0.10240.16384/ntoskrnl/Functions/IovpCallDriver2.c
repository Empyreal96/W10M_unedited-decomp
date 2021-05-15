// IovpCallDriver2 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall IovpCallDriver2(_DWORD *result, int *a2)
{
  int v2; // r9
  _DWORD *v4; // r4
  int v5; // r10
  unsigned int *v6; // r5
  int v7; // r0
  char v8; // r6
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r5
  int v13; // r6
  int v14; // r2
  int v15; // r0
  int v16; // r1
  int v17; // r3
  int v18; // r2
  int v19; // r3
  int v20; // r0
  int v21; // r1
  int v22; // r1 OVERLAPPED
  _DWORD *v23; // r2 OVERLAPPED
  int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r1

  v2 = *result;
  v4 = result;
  if ( !*result )
    return result;
  v5 = result[2];
  v6 = (unsigned int *)(v5 + 4);
  v7 = KfRaiseIrql(2);
  v8 = v7;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v7 = KiAcquireSpinLockInstrumented(v5 + 4);
  }
  else
  {
    do
      v9 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v9 )
      v7 = KxWaitForSpinLockAndAcquire((unsigned int *)(v5 + 4));
  }
  v10 = *(_DWORD *)(v5 + 128);
  *(_BYTE *)(v5 + 8) = v8;
  if ( v10 && (v4[3] & 0x2000000) != 0 )
    *a2 = 259;
  v11 = v4[3];
  v12 = v4[24];
  if ( (v11 & 0x20000000) != 0 && *a2 != 259 && (v11 & 0x1000000) == 0 )
  {
    v7 = IovUtilGetLowerDeviceObject(v4[24]);
    v13 = v7;
    if ( (v4[3] & 0x10000000) != 0 || (v7 = PpvUtilGetDevnodeRemovalOption(v4[9])) == 0 )
    {
      if ( !v13 )
        goto LABEL_29;
      v17 = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 40);
      if ( v17 && *(_DWORD *)(v17 + 52) )
        goto LABEL_27;
      v15 = 541;
    }
    else
    {
      if ( v7 != 1 )
        goto LABEL_27;
      if ( v12 == v14 )
      {
        v7 = IovUtilIsDeviceObjectMarked(v12, 0);
        if ( !v7 )
          goto LABEL_27;
        v15 = 545;
      }
      else
      {
        v7 = IovUtilIsDeviceObjectMarked(v12, 0);
        if ( v7 || (v7 = IovUtilIsDeviceObjectMarked(v12, v16)) == 0 )
        {
LABEL_27:
          if ( v13 )
            v7 = ObfDereferenceObject(v13);
          goto LABEL_29;
        }
        v15 = 547;
      }
    }
    v7 = VfErrorReport2(v15, v4[6], v4 + 10, v12);
    goto LABEL_27;
  }
LABEL_29:
  v18 = v4[3];
  if ( (v18 & 0x40000000) == 0 || (*(_DWORD *)(v2 + 16) & 2) != 0 )
    goto LABEL_39;
  v19 = *a2;
  if ( (v18 & 0x2000000) != 0 )
  {
    if ( v19 == 259 || (v18 & 0x1000000) != 0 )
      goto LABEL_39;
    v20 = 574;
  }
  else
  {
    if ( v19 != 259 && (v18 & 0x1000000) == 0 )
      goto LABEL_39;
    v20 = 588;
  }
  v7 = VfErrorReport3(v20, v4[6], v4 + 10);
  *(_DWORD *)(v2 + 16) |= 2u;
LABEL_39:
  if ( (v4[3] & 0x40000000) != 0 )
  {
    v21 = *a2;
    if ( *a2 == v4[7] || v21 == 259 )
    {
      if ( v21 == -1 )
        VfErrorReport3(549, v4[6], v4 + 10);
    }
    else
    {
      if ( (*(_DWORD *)(v2 + 16) & 1) == 0 )
        VfErrorReport4(v7, v4[6], v4 + 10);
      *(_DWORD *)(v2 + 16) |= 1u;
    }
  }
  else
  {
    if ( *a2 != 259 )
    {
      if ( (*(_DWORD *)(v5 + 36) & 0x400000) == 0 )
        VfErrorReport5(v7, v4[6], v4 + 10);
      *(_DWORD *)(v5 + 36) |= 0x400000u;
    }
    *(_DWORD *)(v4[1] + 4) |= 0x4000000u;
    *(_QWORD *)&v22 = *((_QWORD *)v4 + 2);
    if ( *(_DWORD **)(v22 + 4) != v4 + 4 || (_DWORD *)*v23 != v4 + 4 )
      __fastfail(3u);
    *v23 = v22;
    *(_DWORD *)(v22 + 4) = v23;
  }
  v24 = v4[3];
  if ( (v24 & 0x8000000) != 0 && *a2 != 259 && (v24 & 0x1000000) == 0 )
    *a2 = v4[8];
  IovpSessionDataDereference(v2);
  __dmb(0xBu);
  v25 = (unsigned int *)(v5 + 12);
  do
    v26 = __ldrex(v25);
  while ( __strex(v26 - 1, v25) );
  __dmb(0xBu);
  return (_DWORD *)VfIrpDatabaseEntryReleaseLock(v5);
}
