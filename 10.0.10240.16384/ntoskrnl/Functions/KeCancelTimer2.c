// KeCancelTimer2 
 
int __fastcall KeCancelTimer2(int a1)
{
  int v1; // r4
  int v2; // r6
  int v4; // r9
  int v6; // r10

  v1 = 0;
  v2 = 2;
  v4 = 0;
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_52C4D0();
  v6 = KfRaiseIrql(2);
  if ( !KiAcquireTimer2LockUnlessDisabled(a1) )
  {
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
        goto LABEL_8;
      v4 = 4;
    }
    v1 = 1;
    v2 = 0;
LABEL_8:
    KiUpdateTimer2Flags(a1, v4, v2);
  }
  KfLowerIrql(v6);
  return v1;
}
