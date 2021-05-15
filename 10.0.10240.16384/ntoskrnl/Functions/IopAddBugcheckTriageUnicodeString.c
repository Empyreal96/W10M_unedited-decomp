// IopAddBugcheckTriageUnicodeString 
 
int __fastcall IopAddBugcheckTriageUnicodeString(int a1, int a2)
{
  int v2; // r6
  int v3; // r4

  v2 = HIWORD(a1);
  v3 = 0;
  if ( HIWORD(a1) )
  {
    if ( HIWORD(a1) > 0x100u )
    {
      if ( IopIsAddressRangeValid(a2, 256, a2) )
      {
        IoAddTriageDumpDataBlock(a2, 256);
        v3 = -2147483643;
      }
    }
    else if ( IopIsAddressRangeValid(a2, 8 * (((unsigned int)HIWORD(a1) + 7) >> 3), a2) )
    {
      IoAddTriageDumpDataBlock(a2, 8 * ((unsigned int)(v2 + 7) >> 3));
    }
    else
    {
      v3 = -1073741823;
    }
  }
  return v3;
}
