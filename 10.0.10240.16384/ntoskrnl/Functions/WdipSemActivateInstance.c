// WdipSemActivateInstance 
 
int __fastcall WdipSemActivateInstance(int a1)
{
  unsigned int v2; // r2
  int v3; // r5
  int v4; // r1
  int v5; // r0
  unsigned int v6; // r5
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&dword_61B74C, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_61B74C);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_61B74C) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61B74C, v3, (unsigned int)&dword_61B74C);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_DWORD *)(a1 + 32) = 0;
  __pld(&dword_61B74C);
  v5 = dword_61B74C;
  v6 = dword_61B74C - 16;
  if ( (dword_61B74C & 0xFFFFFFF0) <= 0x10 )
    v6 = 0;
  if ( (dword_61B74C & 2) != 0 )
    goto LABEL_14;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_61B74C);
  while ( v4 == v5 && __strex(v6, (unsigned int *)&dword_61B74C) );
  if ( v4 != v5 )
LABEL_14:
    ExfReleasePushLock(&dword_61B74C, v4);
  result = KeAbPostRelease((unsigned int)&dword_61B74C);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
