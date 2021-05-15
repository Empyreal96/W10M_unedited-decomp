// MiReferencePageForModifiedWrite 
 
int __fastcall MiReferencePageForModifiedWrite(int a1, char a2)
{
  int v3; // r4
  int v4; // r6
  char v5; // r3
  int result; // r0

  v3 = a1;
  if ( (a2 & 1) != 0 )
  {
    v4 = 1;
  }
  else
  {
    a1 = MiChargeForWriteInProgressPage(MiSystemPartition);
    v4 = a1;
    if ( !a1 )
      return 0;
  }
  if ( (a2 & 4) == 0 )
  {
    a1 = MiUnlinkPageFromList(v3, 0);
    *(_DWORD *)(v3 + 12) &= 0xC0000000;
  }
  ++*(_WORD *)(v3 + 16);
  v5 = *(_BYTE *)(v3 + 18) | 8;
  *(_BYTE *)(v3 + 18) = v5;
  if ( (a2 & 8) == 0 )
    *(_BYTE *)(v3 + 18) = v5 & 0xEF;
  if ( (*(_DWORD *)(v3 + 8) & 0x400) != 0 )
    result = v4;
  else
    result = sub_53A084(a1);
  return result;
}
