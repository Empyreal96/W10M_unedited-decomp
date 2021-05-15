// VfIrpDatabaseEntryInsertAndLock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfIrpDatabaseEntryInsertAndLock(unsigned int a1, int a2, unsigned int *a3, int a4)
{
  unsigned int *v6; // r7
  _QWORD *v7; // r5
  int v8; // r8
  int *v9; // r2 OVERLAPPED
  int v10; // r1 OVERLAPPED
  __int64 v11; // r0
  int v12; // r2
  int v13; // r3
  int result; // r0
  unsigned int v15; // r2
  int v16[6]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a4;
  *a3 = a1;
  a3[1] = 0;
  v6 = a3 + 3;
  __dmb(0xBu);
  a3[3] = 1;
  a3[4] = 1;
  a3[5] = 0;
  v7 = a3 + 6;
  a3[6] = (unsigned int)(a3 + 6);
  a3[7] = (unsigned int)(a3 + 6);
  a3[8] = (unsigned int)ViPacketNotificationCallback;
  v8 = (unsigned __int8)(-125 * (a1 >> 12));
  ViIrpDatabaseAcquireLockExclusive(v16);
  v9 = (int *)(ViIrpDatabase + 8 * v8);
  v10 = *v9;
  *v7 = *(_QWORD *)&v10;
  if ( *(int **)(v10 + 4) != v9 )
    __fastfail(3u);
  *(_DWORD *)(v10 + 4) = v7;
  *v9 = (int)v7;
  VfUtilAddressRangeAdd((unsigned int *)(ViIrpDatabaseAddressRanges + 8 * v8), a1, 112);
  v11 = ViIrpDatabaseReleaseLockExclusive(LOBYTE(v16[0]));
  result = VfIrpDatabaseEntryFindAndLock(a1, SHIDWORD(v11), v12, v13);
  __dmb(0xBu);
  do
    v15 = __ldrex(v6);
  while ( __strex(v15 - 1, v6) );
  __dmb(0xBu);
  --a3[4];
  return result;
}
