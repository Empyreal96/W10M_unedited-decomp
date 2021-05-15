// PiControlCopyUserModeCallersBuffer 
 
int __fastcall PiControlCopyUserModeCallersBuffer(int a1, unsigned int a2, unsigned int a3, int a4, char a5, int a6)
{
  unsigned int v9; // r2

  if ( a5 )
  {
    if ( a6 )
    {
      if ( a3 )
      {
        if ( ((a4 - 1) & a2) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        v9 = a2 + a3;
        if ( a2 + a3 > MmUserProbeAddress || v9 < a2 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
    }
    else
    {
      ProbeForWrite(a1, a3, a4);
    }
    memmove(a1, a2, a3);
  }
  else
  {
    memmove(a1, a2, a3);
  }
  return 0;
}
