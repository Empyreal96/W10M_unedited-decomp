// ViSettingsIoCheckForChanges 
 
int __fastcall ViSettingsIoCheckForChanges(unsigned int a1)
{
  unsigned int v1; // r4
  int v2; // r3
  int v3; // r0
  unsigned int v4; // r1

  v1 = a1;
  if ( !VfIrpDatabaseInitialized )
    v1 = a1 & 0xFFFFFFEF;
  if ( (v1 & 0x10) != 0 )
  {
    v3 = 0;
  }
  else
  {
    v2 = VfIoDisabled;
    v3 = 1;
    __dmb(0xBu);
    if ( !v2 )
    {
      __dmb(0xBu);
      do
        v4 = __ldrex((unsigned int *)&VfIoSwitchedOffNoReboot);
      while ( __strex(1u, (unsigned int *)&VfIoSwitchedOffNoReboot) );
      __dmb(0xBu);
    }
  }
  __dmb(0xBu);
  VfIoDisabled = v3;
  IoVerifierCheckForSettingsChange(v1);
  return VfWdCheckForSettingsChange(v1);
}
