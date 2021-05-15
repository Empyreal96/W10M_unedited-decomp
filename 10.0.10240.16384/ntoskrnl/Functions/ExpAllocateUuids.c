// ExpAllocateUuids 
 
int __fastcall ExpAllocateUuids(int a1, unsigned int *a2, _DWORD *a3, int a4, char a5)
{
  __int64 v8; // kr00_8
  int v9; // r1
  unsigned int v10; // r2
  unsigned __int64 v11; // r0
  unsigned int v12; // r3
  int result; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  __int64 v19[6]; // [sp+8h] [bp-30h] BYREF

  if ( !ExpUuidSequenceNumberValid )
  {
    v14 = ExpUuidLoadSequenceNumber();
    if ( v14 < 0 )
      return sub_7D0EAC(v14, v15, v16, v17, a5);
    ++ExpUuidSequenceNumber;
    ExpUuidSequenceNumberValid = 1;
    ExpUuidSequenceNumberNotSaved = 1;
  }
  KeQuerySystemTime(v19);
  v8 = v19[0];
  v9 = (unsigned __int64)(v19[0] - ExpUuidLastTimeAllocated) >> 32;
  v10 = LODWORD(v19[0]) - ExpUuidLastTimeAllocated;
  if ( v9 < 0 )
  {
    ExpUuidSequenceNumberNotSaved = 1;
    v10 = 20000;
    ++ExpUuidSequenceNumber;
    LODWORD(ExpUuidLastTimeAllocated) = LODWORD(v19[0]) - 20000;
    HIDWORD(ExpUuidLastTimeAllocated) = LODWORD(v19[0]) - 20000;
    v9 = 0;
  }
  if ( v10 | v9 )
  {
    ExpUuidTimeSequenceNumber = 0;
    if ( v9 > 0 || v10 > (unsigned int)dword_989680 )
    {
      v10 = (unsigned int)dword_989680;
      v9 = 0;
    }
    if ( v10 <= 0x2710 )
    {
      v11 = 0i64;
      *a2 = v10;
    }
    else
    {
      v11 = __PAIR64__(v9, v10) - 10000;
      *a2 = 10000;
    }
    v12 = v8 - *a2 - v11;
    *(_QWORD *)a1 = v8 - *a2 - v11;
    ExpUuidLastTimeAllocated = __PAIR64__(*(_DWORD *)(a1 + 4), v12) + *a2;
    goto LABEL_11;
  }
  v18 = ExpUuidTimeSequenceNumber;
  if ( (unsigned int)ExpUuidTimeSequenceNumber < 0x1F )
  {
    *a2 = 10000;
    *(_QWORD *)a1 = v8 - 10000;
    ExpUuidTimeSequenceNumber = v18 + 1;
    ExpSetBorrowedTimeOnTimestamp(v18 + 1);
LABEL_11:
    result = 0;
    *a3 = ExpUuidSequenceNumber;
    return result;
  }
  return -1073741267;
}
