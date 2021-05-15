// PiCMCaptureEnumerateInputData 
 
int __fastcall PiCMCaptureEnumerateInputData(unsigned int a1, unsigned int a2, int a3, int a4)
{
  _BYTE *v4; // r5
  int v5; // r4

  v4 = (_BYTE *)a4;
  v5 = 0;
  if ( a1 && a2 >= 0x14 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    memmove(a4, a1, 0x14u);
    if ( *(_DWORD *)v4 != 20 )
      v5 = -1073741811;
  }
  else
  {
    v5 = -1073741811;
  }
  if ( v5 < 0 )
    memset(v4, 0, 20);
  return v5;
}
