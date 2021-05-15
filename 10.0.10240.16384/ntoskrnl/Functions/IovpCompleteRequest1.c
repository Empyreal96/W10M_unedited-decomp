// IovpCompleteRequest1 
 
int __fastcall IovpCompleteRequest1(int a1, char a2, _DWORD *a3)
{
  char v6; // r8
  int result; // r0
  int v8; // r4
  int v9; // r8
  int v10; // r7
  int v11; // r10
  int v12; // r3
  int v13; // r1
  int v14[8]; // [sp+10h] [bp-20h] BYREF

  v6 = KeGetCurrentIrql(a1);
  result = VfIrpDatabaseEntryFindAndLock(a1);
  v8 = result;
  if ( result )
  {
    *(_BYTE *)(result + 41) = v6;
    *(_BYTE *)(result + 40) = v6;
    v9 = *(_DWORD *)(result + 140);
    v10 = 0;
    *a3 = v9;
    a3[1] = result;
    v11 = *(_DWORD *)(a1 + 96);
    if ( v9 )
    {
      if ( (*(_DWORD *)(result + 36) & 0x10) != 0 )
        VfErrorReport1(521, a3[5], a1);
      v12 = *(_DWORD *)(v8 + 128);
      *(_BYTE *)(v8 + 109) = a2;
      if ( v12 && *(int *)(v8 + 36) >= 0 )
      {
        v10 = VfPendingStartLogging(a1);
        *(_BYTE *)(*(_DWORD *)(a1 + 96) + 3) |= 1u;
      }
      *(_DWORD *)(v9 + 24) = 0;
      v13 = *(unsigned __int8 *)(v8 + 110) - *(char *)(a1 + 35);
      a3[3] = v13;
      IovpAdvanceStackDownwards(v9 + 40, *(_BYTE *)(a1 + 35), v11, v11 + 40 * v13, v13, 0, 0, v14);
      result = VfIrpDatabaseEntryReleaseLock(v8);
      if ( v10 )
        result = VfPendingFinishLogging(v10);
    }
    else
    {
      result = VfIrpDatabaseEntryReleaseLock(result);
    }
  }
  else
  {
    *a3 = 0;
  }
  return result;
}
