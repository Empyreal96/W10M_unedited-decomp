// MmStoreProbeAndLockPages 
 
int __fastcall MmStoreProbeAndLockPages(_DWORD *a1)
{
  int *v2; // r1
  int v3; // r0
  int v4; // r7
  int v5; // r6
  int v6; // r5
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned __int8 *v9; // r1
  int v10; // r3
  unsigned int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r0
  int *v14; // r1
  int v15; // r2
  unsigned int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v20[2]; // [sp+10h] [bp-50h] BYREF
  int v21; // [sp+18h] [bp-48h]
  unsigned int v22; // [sp+1Ch] [bp-44h]
  int *v23; // [sp+20h] [bp-40h]
  int v24; // [sp+44h] [bp-1Ch]

  MiProbeAndLockPrepare(v20, (unsigned int)a1, a1[4] + a1[6], a1[5], 1, 1u, 0);
  v2 = v23;
  while ( 1 )
  {
    *v2 = -1;
    v3 = MiProbeLeafFrame((int)v20);
    v4 = v24;
    v5 = v3;
    v6 = MmPfnDatabase + 24 * v24;
    v7 = (unsigned __int8 *)(v6 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
    {
      v9 = (unsigned __int8 *)(v6 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v10 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( v10 < 0 );
        do
          v11 = __ldrex(v9);
        while ( __strex(v11 | 0x80, v9) );
        __dmb(0xBu);
      }
      while ( v11 >> 7 );
    }
    if ( (*(_BYTE *)(v6 + 18) & 8) != 0 )
      break;
    MiReferencePageForModifiedWrite(v6, 13);
    __dmb(0xBu);
    v12 = (unsigned int *)(v6 + 12);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0x7FFFFFFF, v12) );
    v14 = v23;
    v15 = v21;
    v20[0] += 4096;
    v16 = v22;
    *v23 = v4;
    v2 = v14 + 1;
    v23 = v2;
    v21 = v15 + 4;
    if ( v15 + 4 > v16 )
      goto LABEL_17;
  }
  __dmb(0xBu);
  v17 = (unsigned int *)(v6 + 12);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
  v5 = -1073740749;
LABEL_17:
  MiUnlockProbePacketWorkingSet((int)v20);
  if ( v5 >= 0 )
    MiStoreMarkLockedPagesModified(a1);
  else
    MiUnlockStoreLockedPages(a1);
  return v5;
}
