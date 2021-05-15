// MmGetChannelInformation 
 
int __fastcall MmGetChannelInformation(unsigned int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v6; // r8
  _DWORD *v7; // r4
  unsigned int v8; // r7
  unsigned int *v9; // r6
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r2
  unsigned int v14; // r2
  int v15; // r0
  __int16 v16; // r3
  int v17; // [sp+8h] [bp-28h] BYREF
  int v18; // [sp+Ch] [bp-24h] BYREF
  int v19[8]; // [sp+10h] [bp-20h] BYREF

  if ( a1 >= (unsigned __int16)KeNumberNodes )
    return -1073741585;
  v6 = (_DWORD *)(dword_63F718 + 104 * a1);
  *a3 = 40;
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, 40, 1750101325);
  if ( !v7 )
    return -1073741670;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 310);
  v9 = v6 + 23;
  v10 = KeAbPreAcquire((unsigned int)(v6 + 23), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v6 + 23, v10, (unsigned int)(v6 + 23));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  *v7 = 0;
  if ( (v6[22] & 1) != 0 )
  {
    v13 = 0;
    while ( *((_BYTE *)v6 + v13 + 97) )
    {
      if ( ++v13 )
        goto LABEL_19;
    }
    v7[1] = v13;
  }
  else
  {
    v7[1] = -1;
  }
LABEL_19:
  v7[2] = v6[16];
  v7[3] = 0;
  MiGetNodeChannelPageCounts(a1, 0, &v17, &v18, v19);
  v7[4] = v17;
  v7[5] = 0;
  v7[6] = v18;
  v7[7] = 0;
  v7[8] = v19[0];
  v7[9] = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex(v9);
  while ( v14 == 17 && __strex(0, v9) );
  if ( v14 != 17 )
    ExfReleasePushLockShared(v6 + 23);
  v15 = KeAbPostRelease((unsigned int)(v6 + 23));
  v16 = *(_WORD *)(v8 + 310) + 1;
  *(_WORD *)(v8 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    KiCheckForKernelApcDelivery(v15);
  *a2 = v7;
  return 0;
}
