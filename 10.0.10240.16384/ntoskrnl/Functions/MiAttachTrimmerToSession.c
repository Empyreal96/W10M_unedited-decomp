// MiAttachTrimmerToSession 
 
int __fastcall MiAttachTrimmerToSession(int a1)
{
  char *v1; // r7
  unsigned int v2; // r6
  unsigned int v4; // r4
  _DWORD *v5; // r2
  int v6; // r3
  int v7; // t1
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r5
  int v13; // r0
  int v14; // r0
  _DWORD *v15; // [sp+0h] [bp-30h]
  char v16[40]; // [sp+8h] [bp-28h] BYREF

  v1 = byte_63505C;
  v2 = (((unsigned int)dword_63389C >> 20) & 0xFFC) - 1070596096;
  KeAcquireInStackQueuedSpinLock(&dword_6342BC, v16);
  v4 = 0;
  v5 = (_DWORD *)(a1 + 0x2000);
  v15 = (_DWORD *)(a1 + 0x2000);
  do
  {
    v7 = (unsigned __int8)*v1++;
    v6 = v7;
    if ( v7 == 11 || v6 == 1 )
    {
      v9 = v2 + 1070596096;
      v10 = *(_DWORD *)(v4 + *v5);
      if ( (v10 & 2) != 0 )
      {
        if ( v2 + 0x40000000 > 0x3FFFFF )
        {
LABEL_18:
          *(_DWORD *)v2 = v10;
        }
        else
        {
          v11 = *(_DWORD *)v2;
          v12 = 0;
          __dmb(0xBu);
          *(_DWORD *)v2 = v10;
          if ( (v11 & 2) == 0 )
            v12 = 1;
          if ( v9 <= 0xFFF )
          {
            v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v13, v13 + 4 * (v2 & 0xFFF), v10);
          }
          if ( v12 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
LABEL_14:
        v5 = v15;
        goto LABEL_4;
      }
      if ( v2 + 0x40000000 > 0x3FFFFF )
        goto LABEL_18;
      __dmb(0xBu);
      *(_DWORD *)v2 = v10;
      if ( v9 > 0xFFF )
        goto LABEL_14;
      v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v14, v14 + 4 * (v2 & 0xFFF), v10);
      v5 = v15;
    }
LABEL_4:
    v4 += 4;
    v2 += 4;
  }
  while ( v4 < 0x800 );
  return KeReleaseInStackQueuedSpinLock(v16);
}
