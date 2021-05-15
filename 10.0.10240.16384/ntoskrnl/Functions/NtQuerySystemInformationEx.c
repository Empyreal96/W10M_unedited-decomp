// NtQuerySystemInformationEx 
 
int __fastcall NtQuerySystemInformationEx(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r2

  v4 = a3;
  if ( !a2 || !a3 )
    return -1073741811;
  if ( a1 > 107 )
  {
    if ( a1 == 108 || a1 == 121 || a1 == 141 || a1 == 160 )
    {
LABEL_22:
      v5 = 2;
      goto LABEL_23;
    }
    if ( a1 == 165 )
    {
      v5 = 8;
      goto LABEL_23;
    }
    if ( a1 != 175 )
      return -1073741821;
  }
  else if ( a1 != 107 )
  {
    if ( a1 != 8 && a1 != 23 && a1 != 42 && a1 != 61 && a1 != 73 && a1 != 83 && a1 != 100 )
      return -1073741821;
    goto LABEL_22;
  }
  v5 = 4;
LABEL_23:
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( ((v5 - 1) & a2) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a2 + v4 > MmUserProbeAddress || a2 + v4 < a2 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  return ExpQuerySystemInformation(a1, a2, v4, a4);
}
