// VfSettingsCheckForChanges 
 
int __fastcall VfSettingsCheckForChanges(__int16 a1, __int16 a2, __int16 a3, _BYTE *a4)
{
  int v8; // r0
  int v9; // r0

  VfKeCheckForChanges(a4);
  if ( (a2 & 8) != 0 )
  {
    if ( (a1 & 8) == 0 )
      MmTrackLockedPages = 1;
  }
  else if ( (a3 & 8) != 0 && (a1 & 8) != 0 )
  {
    MmTrackLockedPages |= 0x10000000u;
  }
  v8 = ViSettingsIoCheckForChanges(a4);
  if ( (a2 & 0x20) != 0 )
  {
    if ( (a1 & 0x20) != 0 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( (a3 & 0x20) != 0 && (a1 & 0x20) != 0 )
LABEL_12:
    ViDeadlockDetectionApplySettings(v8);
LABEL_13:
  if ( (a2 & 0x80) != 0 )
  {
    if ( (a1 & 0x80) != 0 )
      goto LABEL_19;
    goto LABEL_18;
  }
  if ( (a3 & 0x80) != 0 && (a1 & 0x80) != 0 )
LABEL_18:
    ViHalApplySettings();
LABEL_19:
  if ( (a2 & 0x800) != 0 )
  {
    if ( (a1 & 0x800) == 0 )
    {
      v9 = 1;
LABEL_25:
      ViSettingsEnableKernelHandleChecking(v9);
      VfSettingsApplyMiscellaneousChecks((a1 | a2) & ~a3);
      return VfPendingCheckForChanges((int)a4);
    }
  }
  else if ( (a3 & 0x800) != 0 && (a1 & 0x800) != 0 )
  {
    v9 = 0;
    goto LABEL_25;
  }
  return VfPendingCheckForChanges((int)a4);
}
