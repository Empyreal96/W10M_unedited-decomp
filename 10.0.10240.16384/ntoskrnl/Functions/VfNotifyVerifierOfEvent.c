// VfNotifyVerifierOfEvent 
 
int __fastcall VfNotifyVerifierOfEvent(int result)
{
  unsigned int v1; // r1
  int v2; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1

  switch ( result )
  {
    case 0:
      do
        v8 = __ldrex(ViNotifyEvent);
      while ( __strex(v8 + 1, ViNotifyEvent) );
      return result;
    case 1:
      v3 = &ViNotifyEvent[1];
      do
LABEL_20:
        v7 = __ldrex(v3);
      while ( __strex(v7 + 1, v3) );
      return result;
    case 2:
      do
        v4 = __ldrex(&ViNotifyEvent[2]);
      while ( __strex(v4 + 1, &ViNotifyEvent[2]) );
      __dmb(0xBu);
      result = 1;
      do
        v5 = __ldrex((unsigned int *)&ViKeTrackIrqlDisabled);
      while ( __strex(1u, (unsigned int *)&ViKeTrackIrqlDisabled) );
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned int *)&ViFaultsDisabled);
      while ( __strex(1u, (unsigned int *)&ViFaultsDisabled) );
      __dmb(0xBu);
      return result;
    case 3:
      v3 = &ViNotifyEvent[3];
      goto LABEL_20;
    case 4:
      v3 = &ViNotifyEvent[4];
      goto LABEL_20;
    case 5:
      do
        v1 = __ldrex(&ViNotifyEvent[5]);
      while ( __strex(v1 + 1, &ViNotifyEvent[5]) );
      if ( (VfOptionFlags & 0x10) != 0 )
      {
        v2 = VfUtilDbgPrint((int)"Driver Verifier: VERIFIER_OPTION_ONEBOOT set before boot. Clearing Verifier options from Registry.\n");
        VfUtilClearOneBootSettings(v2);
      }
      result = VfNotifyVerifierExtensions(0, 2);
      break;
  }
  return result;
}
