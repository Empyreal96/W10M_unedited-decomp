// SepInitializationPhase0 
 
BOOL SepInitializationPhase0()
{
  int v0; // r3
  unsigned int *v1; // r2
  unsigned int v2; // r0
  int v3; // r0
  int v4; // r0

  if ( !SepVariableInitialization() || !SepRmDbInitialization() || !SepTokenInitialization() || !SepInitializeWorkList() )
    return 0;
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x388) = 0;
  v0 = __mrc(15, 0, 13, 0, 3);
  __dmb(0xBu);
  v1 = (unsigned int *)((v0 & 0xFFFFFFC0) + 960);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0xFFFFFFF7, v1) );
  __dmb(0xBu);
  v3 = ObInitializeFastReference(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244, 0);
  v4 = SeMakeSystemToken(v3);
  ObInitializeFastReference(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244, v4);
  SepDefaultMandatorySid = SeMediumMandatorySid;
  SepMandatoryObjectTypePolicyLock = 0;
  return *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244) != 0;
}
