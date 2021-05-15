// RtlPinAtomInAtomTable 
 
int __fastcall RtlPinAtomInAtomTable(_DWORD *a1, unsigned int a2)
{
  int v3; // r6
  int v4; // r4
  int v5; // r0
  _DWORD *v6; // r0
  unsigned int *v7; // r5
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  unsigned int _24; // [sp+24h] [bp+Ch]

  _24 = a2;
  v3 = (int)a1;
  if ( !RtlpLockAtomTable(a1) )
    return -1073741811;
  v4 = -1073741816;
  if ( a2 < 0xC000 )
  {
    if ( a2 )
      v4 = 0;
  }
  else
  {
    v5 = RtlpAtomMapAtomToHandleEntry(v3, a2 & 0x3FFF);
    if ( v5 )
    {
      if ( *(unsigned __int16 *)(v5 + 6) == a2 )
      {
        v6 = RtlpLookupLowBox(v3, v5);
        if ( v6 )
        {
          v4 = 0;
          *((_WORD *)v6 + 7) |= 1u;
        }
      }
    }
  }
  v7 = (unsigned int *)(v3 + 8);
  __dmb(0xBu);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 - 1, v7) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v3 + 8));
  v9 = KeAbPostRelease(v3 + 8);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v4;
}
