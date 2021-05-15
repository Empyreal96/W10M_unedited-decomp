// RtlLookupAtomInAtomTable 
 
int __fastcall RtlLookupAtomInAtomTable(_DWORD *a1, unsigned __int16 *a2, _WORD *a3, int a4)
{
  int v7; // r4
  __int16 v8; // r3
  int v9; // r6
  unsigned int *v10; // r5
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  _DWORD *v16; // [sp+10h] [bp-28h] BYREF
  unsigned __int16 *v17; // [sp+14h] [bp-24h]
  int _18[14]; // [sp+18h] [bp-20h] BYREF

  _18[11] = (int)a2;
  _18[12] = (int)a3;
  _18[13] = a4;
  v16 = a1;
  v17 = a2;
  _18[0] = (int)a3;
  _18[1] = a4;
  _18[10] = (int)a1;
  if ( !RtlpLockAtomTable(a1) )
    return -1073741811;
  if ( RtlGetIntegerAtom((unsigned int)a2, &v16) )
  {
    v8 = (__int16)v16;
    if ( (unsigned __int16)v16 < 0xC000u )
    {
      v7 = 0;
    }
    else
    {
      v8 = 0;
      LOWORD(v16) = 0;
      v7 = -1073741811;
    }
    v17 = (unsigned __int16 *)v7;
    if ( !a3 )
      goto LABEL_20;
LABEL_17:
    *a3 = v8;
    goto LABEL_20;
  }
  if ( *a2 )
  {
    v7 = RtlpHashStringToAtom((int)a1, a2, 1, 0, 0, _18, (int *)&v16);
    v17 = (unsigned __int16 *)v7;
    if ( v7 < 0 )
      goto LABEL_20;
    v9 = (int)v16;
    if ( v16 )
    {
      if ( RtlpAtomMapAtomToHandleEntry((int)a1, *((_WORD *)v16 + 2)) )
      {
        v7 = 0;
        v17 = 0;
        if ( !a3 )
          goto LABEL_20;
        v8 = *(_WORD *)(v9 + 6);
        goto LABEL_17;
      }
      v7 = -1073741816;
    }
    else
    {
      v7 = -1073741772;
    }
  }
  else
  {
    v7 = -1073741773;
  }
  v17 = (unsigned __int16 *)v7;
LABEL_20:
  v10 = a1 + 2;
  __dmb(0xBu);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 2);
  v12 = KeAbPostRelease((unsigned int)(a1 + 2));
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return v7;
}
