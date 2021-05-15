// VfIrpDatabaseEntryReleaseLock 
 
int __fastcall VfIrpDatabaseEntryReleaseLock(unsigned int *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r3
  _DWORD *v9; // r2
  __int64 v10; // r0
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  BOOL v13; // r5
  int v14; // r6
  int result; // r0
  unsigned int v16; // r1
  _DWORD var18[8]; // [sp+0h] [bp-18h] BYREF

  var18[0] = a3;
  var18[1] = a4;
  if ( !a1[4] )
  {
    ViIrpDatabaseAcquireLockExclusive(var18);
    v5 = *a1;
    if ( *a1 )
    {
      ((void (__fastcall *)(unsigned int *, unsigned int, int))a1[8])(a1, *a1, 1);
      v6 = ViIrpDatabaseAddressRanges;
      *a1 = 0;
      VfUtilAddressRangeRemoveCheckEmpty((_DWORD *)(v6 + 8 * (unsigned __int8)(-125 * (v5 >> 12))), v5);
    }
    ViIrpDatabaseReleaseLockExclusive(LOBYTE(var18[0]));
  }
  v7 = a1[3];
  __dmb(0xBu);
  if ( !v7 )
  {
    ViIrpDatabaseAcquireLockExclusive(var18);
    v8 = a1[3];
    __dmb(0xBu);
    if ( !v8 )
    {
      v9 = a1 + 6;
      v10 = *((_QWORD *)a1 + 3);
      v11 = (_DWORD *)a1[6];
      if ( *(unsigned int **)(v10 + 4) != a1 + 6 || *(_DWORD **)HIDWORD(v10) != v9 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v10) = v10;
      *(_DWORD *)(v10 + 4) = HIDWORD(v10);
      *v9 = v9;
      a1[7] = (unsigned int)(a1 + 6);
      if ( (_DWORD *)*v11 == v11 )
      {
        v12 = (_DWORD *)(ViIrpDatabaseAddressRanges + 8 * (((int)v11 - ViIrpDatabase) >> 3));
        *v12 = 0;
        v12[1] = 0;
      }
    }
    ViIrpDatabaseReleaseLockExclusive(LOBYTE(var18[0]));
  }
  v13 = a1[6] == (_DWORD)(a1 + 6);
  v14 = *((unsigned __int8 *)a1 + 8);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 1, var18[7]);
  }
  else
  {
    __dmb(0xBu);
    a1[1] = 0;
  }
  result = KfLowerIrql(v14);
  if ( v13 )
  {
    v16 = *a1;
    a1[5] |= 0x80000000;
    result = ((int (__fastcall *)(unsigned int *, unsigned int, int))a1[8])(a1, v16, 2);
  }
  return result;
}
