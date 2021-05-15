// RtlDeleteAtomFromAtomTable 
 
int __fastcall RtlDeleteAtomFromAtomTable(_DWORD *a1, unsigned int a2)
{
  int v4; // r4
  int v5; // r0
  int v6; // r6
  _DWORD *v7; // r0
  unsigned int *v8; // r5
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

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
    v5 = RtlpAtomMapAtomToHandleEntry((int)a1, a2 & 0x3FFF);
    v6 = v5;
    if ( v5 )
    {
      if ( *(unsigned __int16 *)(v5 + 6) == a2 )
      {
        v7 = RtlpLookupLowBox((int)a1, v5);
        if ( v7 )
        {
          v4 = 0;
          if ( (*((_WORD *)v7 + 7) & 1) != 0 )
            v4 = 1073741849;
          else
            RtlpDereferenceAtom(v6, (int)v7, (int)a1);
        }
      }
    }
  }
  v8 = a1 + 2;
  __dmb(0xBu);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 - 1, v8) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 2);
  v10 = KeAbPostRelease((unsigned int)(a1 + 2));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v4;
}
