// MiCaptureUlongPtrArray 
 
int __fastcall MiCaptureUlongPtrArray(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r2

  v3 = 4 * a3;
  if ( v3 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( v3 + a2 > MmUserProbeAddress || v3 + a2 < a2 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  memmove(a1, a2, v3);
  return 0;
}
