// MiIsRangeFullyCommitted 
 
int __fastcall MiIsRangeFullyCommitted(int a1, unsigned int a2, unsigned int *a3, unsigned int *a4)
{
  _DWORD *v6; // r4
  int v8; // r6
  int v9; // r9
  unsigned int v10; // r8
  int v11; // r2
  unsigned int *v12; // r7
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  unsigned int *v16; // r1
  unsigned int v17; // r2
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r3
  unsigned int *v22; // [sp+0h] [bp-20h] BYREF
  unsigned int *v23; // [sp+4h] [bp-1Ch] BYREF

  v22 = a3;
  v23 = a4;
  v6 = (_DWORD *)MiGetProtoPteAddress((_DWORD *)a1, a2 >> 12, 5, &v23);
  if ( !v6 )
    return sub_800F4C();
  v8 = MiGetProtoPteAddress((_DWORD *)a1, (unsigned int)a3 >> 12, 5, &v22);
  if ( !v8 )
    return sub_800F4C();
  v9 = 1;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = ***(_DWORD ***)(a1 + 44);
  --*(_WORD *)(v10 + 310);
  v12 = (unsigned int *)(v11 + 28);
  v13 = KeAbPreAcquire(v11 + 28, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex(v12);
  while ( !v15 && __strex(0x11u, v12) );
  __dmb(0xBu);
  if ( v15 )
    ExfAcquirePushLockSharedEx(v12, v13, (unsigned int)v12);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = v23;
  while ( 1 )
  {
    if ( v16 == v22 )
      v17 = v8;
    else
      v17 = v16[1] + 4 * v16[7] - 4;
    if ( (unsigned int)v6 <= v17 )
    {
      while ( *v6++ )
      {
        if ( (unsigned int)v6 > v17 )
          goto LABEL_17;
      }
      v9 = 0;
    }
LABEL_17:
    if ( v16 == v22 )
      break;
    v16 = (unsigned int *)v16[2];
    v6 = (_DWORD *)v16[1];
    if ( !v6 )
    {
      v9 = 0;
      break;
    }
  }
  __dmb(0xBu);
  do
    v19 = __ldrex(v12);
  while ( v19 == 17 && __strex(0, v12) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(v12);
  v20 = KeAbPostRelease((unsigned int)v12);
  v21 = (__int16)(*(_WORD *)(v10 + 310) + 1);
  *(_WORD *)(v10 + 310) = v21;
  if ( !v21 && *(_DWORD *)(v10 + 100) != v10 + 100 )
    KiCheckForKernelApcDelivery(v20);
  return v9;
}
