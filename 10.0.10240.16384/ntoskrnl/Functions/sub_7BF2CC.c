// sub_7BF2CC 
 
void __fastcall sub_7BF2CC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r3

  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v10 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v11 = 0;
  else
    v11 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_9;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v12 == v10 && __strex(v11, (unsigned int *)&PopPowerRequestLock) );
  if ( v12 != v10 )
LABEL_9:
    ExfReleasePushLock(&PopPowerRequestLock, v10);
  v13 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  __asm { POP.W           {R4-R7,R11,PC} }
}
