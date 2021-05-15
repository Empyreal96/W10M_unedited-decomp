// MiCopyTopLevelMappings 
 
_BYTE *__fastcall MiCopyTopLevelMappings(int a1, int a2)
{
  unsigned int v2; // r7
  unsigned int v3; // r8
  int v4; // r5
  unsigned int v5; // r5
  int v6; // r1
  unsigned int v7; // r6
  __int16 v8; // r8
  _DWORD *v9; // r4
  int v10; // r3
  unsigned int v11; // r4
  int v13; // r4
  int v14; // r0
  int v15; // r0
  int v16; // [sp+0h] [bp-40h]
  int v18; // [sp+Ch] [bp-34h]
  char v20[40]; // [sp+18h] [bp-28h] BYREF

  v18 = *(_DWORD *)(a1 + 32) + 4 * (a2 & 0xFFF);
  v2 = ((unsigned int)dword_63389C >> 20) & 0xFFC;
  v16 = *(_DWORD *)(a1 + 324);
  v3 = (unsigned int)dword_63389C >> 22;
  v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
  KeAcquireInStackQueuedSpinLock(&dword_6342BC, v20);
  memmove(v18 + 16 * v3, v4 + 4 * (v2 & 0xFFF), 16 * (1024 - v3));
  v5 = a2 + 4 * v3;
  memmove(v5, v2 - 1070596096, 4 * (1024 - v3));
  v6 = v16;
  v7 = 0;
  v8 = 4 * v5;
  v9 = (_DWORD *)(v16 + 0x2000);
  while ( 1 )
  {
    v10 = *((unsigned __int8 *)&MiState[2423] + v7);
    if ( v10 != 11 && v10 != 1 )
      goto LABEL_4;
    if ( !v6 )
    {
      MiArmWriteConvertedHardwarePde(*(_DWORD *)(a1 + 32), (v8 & 0x3FFC) + *(_DWORD *)(a1 + 32), 0);
      if ( v5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v5 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v5 = 0;
        if ( v5 + 1070596096 <= 0xFFF )
        {
          v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v15, v15 + 4 * (v5 & 0xFFF), 0);
        }
      }
      goto LABEL_10;
    }
    v13 = *(_DWORD *)(*v9 + 4 * v7);
    v14 = MiArmWriteConvertedHardwarePde(*(_DWORD *)(a1 + 32), (v8 & 0x3FFC) + *(_DWORD *)(a1 + 32), v13);
    if ( v5 >= 0xC0000000 )
      return (_BYTE *)sub_510784(v14);
    *(_DWORD *)v5 = v13;
    v9 = (_DWORD *)(v16 + 0x2000);
LABEL_10:
    v6 = v16;
LABEL_4:
    ++v7;
    v5 += 4;
    v8 += 16;
    if ( v7 >= 0x200 )
    {
      KeReleaseInStackQueuedSpinLock(v20);
      v11 = ((unsigned int)dword_633894 >> 22) - 769;
      memset((_BYTE *)(v18 + 12320), 0, 16 * v11);
      return memset((_BYTE *)(a2 + 3080), 0, 4 * v11);
    }
  }
}
