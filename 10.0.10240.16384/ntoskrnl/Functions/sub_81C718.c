// sub_81C718 
 
void __fastcall sub_81C718(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3

  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v8 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v9 = 0;
  else
    v9 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_9;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v10 == v8 && __strex(v9, (unsigned int *)&PopPowerRequestLock) );
  if ( v10 != v8 )
LABEL_9:
    ExfReleasePushLock(&PopPowerRequestLock, v8);
  v11 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  __asm { POP.W           {R4,R5,R11,PC} }
}
