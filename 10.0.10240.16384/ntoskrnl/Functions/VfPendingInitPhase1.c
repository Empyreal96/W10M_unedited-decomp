// VfPendingInitPhase1 
 
int VfPendingInitPhase1()
{
  int *v0; // r5
  unsigned int i; // r4
  int result; // r0
  unsigned int v3; // r1
  int v4; // [sp+10h] [bp-30h] BYREF
  int v5; // [sp+14h] [bp-2Ch] BYREF
  int v6[10]; // [sp+18h] [bp-28h] BYREF

  v0 = &ViPendingWorkers;
  for ( i = 0; i < 8; ++i )
  {
    KeInitializeEvent((int)(v0 + 2), 1, 0);
    v6[0] = 24;
    v6[1] = 0;
    v6[3] = 512;
    v6[2] = 0;
    v6[4] = 0;
    v6[5] = 0;
    result = PsCreateSystemThread((int)&v4, 0, (int)v6);
    if ( result < 0 )
      break;
    ObReferenceObjectByHandle(v4, 0, PsThreadType, 0, (int)&v5, 0);
    *v0 = v5;
    v0 += 7;
    result = ZwClose();
  }
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&ViPendingWorkersCount);
  while ( __strex(i, (unsigned int *)&ViPendingWorkersCount) );
  __dmb(0xBu);
  return result;
}
