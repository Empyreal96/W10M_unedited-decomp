// IopInitDumpCapsuleSupport 
 
int IopInitDumpCapsuleSupport()
{
  _BYTE *v0; // r0

  if ( CapsuleTriageDumpBlockInitialized || IopIsBitlockerOn() )
    return 0;
  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 137216);
  CapsuleTriageDumpBlock = (int)v0;
  if ( v0 )
  {
    memset(v0, 0, 137216);
    CapsuleTriageDumpBlockInitialized = 1;
    return 0;
  }
  return -1073741670;
}
