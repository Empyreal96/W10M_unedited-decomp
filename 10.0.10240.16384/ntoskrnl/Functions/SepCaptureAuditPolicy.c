// SepCaptureAuditPolicy 
 
int __fastcall SepCaptureAuditPolicy(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int *a7)
{
  int v7; // r4
  int v8; // r0

  v7 = a1;
  if ( (_BYTE)a2 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 + 30 > MmUserProbeAddress || a1 + 30 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v8 = ExAllocatePoolWithTag(1, 30, 1632658771);
  *a7 = v8;
  if ( !v8 )
    return -1073741670;
  memmove(v8, v7, 0x1Eu);
  return 0;
}
