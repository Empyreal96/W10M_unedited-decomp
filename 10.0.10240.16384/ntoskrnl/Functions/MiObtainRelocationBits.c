// MiObtainRelocationBits 
 
int __fastcall MiObtainRelocationBits(_BYTE **a1, unsigned int a2, unsigned int a3, int a4)
{
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r4
  unsigned int v10; // r0
  int v11; // r0
  int v12; // r3
  _BYTE *v13; // r0
  unsigned int v16; // [sp+8h] [bp-20h]

  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v16 + 310);
  v6 = KeAbPreAcquire((unsigned int)algn_632EC4, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)algn_632EC4);
  while ( __strex(v7 | 1, (unsigned __int8 *)algn_632EC4) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(algn_632EC4, v6, (unsigned int)algn_632EC4);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = RtlFindClearBitsAndSet((unsigned int *)*a1, a2, a3);
  if ( v8 != -1 )
  {
    if ( a1[1] )
      return sub_7D5144();
    if ( a4 == 1 )
    {
      RtlClearBits(*a1, a3 - a2, a2);
      v13 = a1[1];
      if ( v13 )
        RtlClearBits(v13, a3 - a2, a2);
    }
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)algn_632EC4);
  while ( __strex(v10 - 1, (unsigned int *)algn_632EC4) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)algn_632EC4);
  v11 = KeAbPostRelease((unsigned int)algn_632EC4);
  v12 = (__int16)(*(_WORD *)(v16 + 310) + 1);
  *(_WORD *)(v16 + 310) = v12;
  if ( !v12 && *(_DWORD *)(v16 + 100) != v16 + 100 )
    KiCheckForKernelApcDelivery(v11);
  return v8;
}
