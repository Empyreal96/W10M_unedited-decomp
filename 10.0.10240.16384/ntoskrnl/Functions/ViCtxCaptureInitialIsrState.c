// ViCtxCaptureInitialIsrState 
 
char *ViCtxCaptureInitialIsrState()
{
  unsigned int v0; // r1
  int v1; // r0
  unsigned int v2; // r1
  unsigned int v3; // r1
  int v4; // r4
  unsigned int *v5; // r2
  unsigned int v6; // r1
  char *v7; // r4
  unsigned int v8; // r2

  do
    v0 = __ldrex(&ViCtxInterrupts);
  while ( __strex(v0 + 1, &ViCtxInterrupts) );
  v1 = 0;
  while ( 1 )
  {
    __dmb(0xBu);
    do
    {
      v2 = __ldrex(&ViCtxHintIndex);
      v3 = v2 + 1;
    }
    while ( __strex(v3, &ViCtxHintIndex) );
    v4 = v3 & 0xF;
    __dmb(0xBu);
    v5 = (unsigned int *)((char *)&ViCtxIsrStateBlocks + 12 * v4);
    do
      v6 = __ldrex(v5);
    while ( !v6 && __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    if ( (unsigned int)++v1 >= 0x10 )
    {
      v7 = 0;
      goto LABEL_12;
    }
  }
  v7 = (char *)&ViCtxIsrStateBlocks + 12 * v4;
LABEL_12:
  if ( v7 )
  {
    v7[8] = KeGetCurrentIrql(v1);
    do
      v8 = __ldrex(&ViCtxInterruptsChecked);
    while ( __strex(v8 + 1, &ViCtxInterruptsChecked) );
  }
  return v7;
}
