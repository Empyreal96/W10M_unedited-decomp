// IovpPacketFromIrp 
 
int __fastcall IovpPacketFromIrp(int a1)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r3
  int v5; // r3
  unsigned int v6; // r3

  v2 = *(_DWORD *)(a1 + 8);
  result = 0;
  v4 = v2 & 0xC0000000;
  if ( !v4 )
  {
    result = VfIrpDatabaseEntryFindAndLock(a1);
    if ( result )
    {
      v5 = *(_DWORD *)(a1 + 8);
    }
    else
    {
      result = VfPacketCreateAndLock(a1);
      v5 = *(_DWORD *)(a1 + 8);
      if ( !result )
      {
        v6 = v5 | 0x80000000;
        goto LABEL_9;
      }
    }
    v6 = v5 | 0x40000000;
LABEL_9:
    *(_DWORD *)(a1 + 8) = v6;
    return result;
  }
  if ( v4 == 0x40000000 )
    result = VfIrpDatabaseEntryFindAndLock(a1);
  return result;
}
