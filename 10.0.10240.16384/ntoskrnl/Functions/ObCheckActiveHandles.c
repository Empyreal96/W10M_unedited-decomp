// ObCheckActiveHandles 
 
int __fastcall ObCheckActiveHandles(int a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  int v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 - 16);
  v4 = KeAbPreAcquire(a1 - 16, 0, 0);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7E98D8(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v7 = *(_DWORD *)(a1 - 20);
  __pld(v3);
  v8 = *(_DWORD *)v3;
  if ( (*(_DWORD *)v3 & 0xFFFFFFF0) > 0x10 )
    v9 = v8 - 16;
  else
    v9 = 0;
  if ( (v8 & 2) != 0 )
    goto LABEL_18;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v3);
  while ( v10 == v8 && __strex(v9, (unsigned int *)v3) );
  if ( v10 != v8 )
LABEL_18:
    ExfReleasePushLock(v3, v8);
  v11 = KeAbPostRelease((unsigned int)v3);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return v7 != 0;
}
