// VfIrpDatabaseCheckExFreePool 
 
void __fastcall __spoils<R2,R3,R12> VfIrpDatabaseCheckExFreePool(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r1
  __int64 v6; // r2
  int v7; // r4
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  if ( !VfIrpDatabaseInitialized )
    return;
  v5 = a1 + 1;
  v6 = *(_QWORD *)(ViIrpDatabaseAddressRanges + 8 * (unsigned __int8)(-125 * (a1 >> 12)));
  __dmb(0xBu);
  if ( (unsigned int)v6 >= HIDWORD(v6) )
    return;
  if ( a1 > (unsigned int)v6 )
    goto LABEL_6;
  if ( v5 >= HIDWORD(v6) )
    goto LABEL_9;
  if ( a1 >= (unsigned int)v6 )
  {
LABEL_6:
    if ( a1 >= HIDWORD(v6) )
      goto LABEL_7;
LABEL_9:
    ViIrpDatabaseAcquireLockShared(v8);
    v7 = ViIrpDatabaseFindPointer(a1);
    ViIrpDatabaseReleaseLockShared(LOBYTE(v8[0]));
    if ( v7 )
      VerifierBugCheckIfAppropriate(196, 261, a1, 0, 0);
    return;
  }
LABEL_7:
  if ( v5 > (unsigned int)v6 && v5 <= HIDWORD(v6) )
    goto LABEL_9;
}
