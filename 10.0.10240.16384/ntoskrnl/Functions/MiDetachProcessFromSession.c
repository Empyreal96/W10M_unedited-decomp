// MiDetachProcessFromSession 
 
int __fastcall MiDetachProcessFromSession(int a1)
{
  char *v1; // r6
  unsigned int v2; // r5
  int v4; // r2
  int v5; // r3
  int v7; // r0
  unsigned int *v8; // r1
  int *v9; // r0
  int v10; // r4
  int v11; // r3
  int v12; // t1
  int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r0
  int v16[4]; // [sp+0h] [bp-38h] BYREF
  char v17[40]; // [sp+10h] [bp-28h] BYREF

  v1 = byte_63505C;
  v2 = (((unsigned int)dword_63389C >> 20) & 0xFFC) - 1070596096;
  KeAcquireInStackQueuedSpinLock(&dword_6342BC, v17);
  if ( a1 != 1 )
    goto LABEL_9;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_634980, v16, v4, v5);
  *(_BYTE *)(MmSessionSpace + 3361) = *(_BYTE *)(MmSessionSpace + 3361) & 0xF9 | 4;
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_51DD58();
  v7 = v16[0];
  if ( v16[0] )
  {
LABEL_18:
    v16[0] = 0;
    __dmb(0xBu);
    v14 = (unsigned int *)(v7 + 4);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 ^ 1, v14) );
    goto LABEL_9;
  }
  v8 = (unsigned int *)v16[1];
  __dmb(0xBu);
  do
    v9 = (int *)__ldrex(v8);
  while ( v9 == v16 && __strex(0, v8) );
  if ( v9 != v16 )
  {
    v7 = KxWaitForLockChainValid(v16);
    goto LABEL_18;
  }
LABEL_9:
  v10 = 512;
  do
  {
    v12 = (unsigned __int8)*v1++;
    v11 = v12;
    if ( v12 == 11 || v11 == 1 )
    {
      if ( v2 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v2 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v2 = 0;
        if ( v2 + 1070596096 <= 0xFFF )
        {
          v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v13, v13 + 4 * (v2 & 0xFFF), 0);
        }
      }
    }
    v2 += 4;
    --v10;
  }
  while ( v10 );
  return KeReleaseInStackQueuedSpinLock(v17);
}
