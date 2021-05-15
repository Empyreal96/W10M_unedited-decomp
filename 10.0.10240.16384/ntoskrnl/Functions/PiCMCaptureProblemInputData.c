// PiCMCaptureProblemInputData 
 
int __fastcall PiCMCaptureProblemInputData(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r4

  v4 = a4;
  v5 = 0;
  if ( a1 && a2 >= 0x1A0 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    memmove(a4, a1, 0x1A0u);
    if ( *(_DWORD *)v4 == 416 )
      *(_WORD *)(v4 + 406) = 0;
    else
      v5 = -1073741811;
  }
  else
  {
    v5 = -1073741811;
  }
  if ( v5 < 0 )
    memset((_BYTE *)v4, 0, 416);
  return v5;
}
