// MiFlushTbAsNeeded 
 
int __fastcall MiFlushTbAsNeeded(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // lr
  int v5; // r6
  unsigned int v6; // r5
  unsigned int v8; // r1
  unsigned int v10; // r7
  int v11; // r2
  int v12; // r6
  int v13; // r2
  unsigned int v14; // r3
  int v15; // r0
  char v16; // r3
  char v17; // r3
  int v18; // [sp+4h] [bp-C8h]
  unsigned int v19; // [sp+8h] [bp-C4h]
  int v20; // [sp+14h] [bp-B8h] BYREF
  char v21; // [sp+18h] [bp-B4h]
  char v22; // [sp+19h] [bp-B3h]
  int v23; // [sp+1Ch] [bp-B0h]
  int v24; // [sp+20h] [bp-ACh]
  int v25; // [sp+24h] [bp-A8h]
  int v26; // [sp+28h] [bp-A4h]

  v18 = 0;
  v19 = 0;
  v3 = 0;
  v21 = 0;
  v20 = a3;
  v5 = 0;
  v6 = 0;
  v23 = 33;
  v24 = 0;
  v22 = 0;
  v25 = 0;
  v26 = 0;
  if ( !a2 )
    goto LABEL_20;
  do
  {
    v8 = *(_DWORD *)a1;
    if ( (*(_DWORD *)a1 & 0xC02) != 0 )
      JUMPOUT(0x542A7E);
    if ( ((v8 >> 5) & 0x1F) != 0 )
      return sub_542A78();
    v10 = v8 >> 12;
    v11 = *(_DWORD *)a1 & 0xFFF;
    if ( a1 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)a1 = v11;
    }
    else
    {
      v12 = 0;
      __dmb(0xBu);
      *(_DWORD *)a1 = v11;
      if ( (v8 & 2) == 0 && (v11 & 2) != 0 )
        v12 = 1;
      if ( a1 >= 0xC0300000 && a1 <= 0xC0300FFF )
      {
        v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * (a1 & 0xFFF)), v11);
        v3 = v18;
      }
      if ( v12 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    if ( !v10 )
    {
      v19 = 0;
      v3 = 0;
LABEL_17:
      v18 = v3;
      goto LABEL_18;
    }
    if ( v10 != v19 )
    {
      while ( 1 )
      {
        __dmb(0xFu);
        v13 = KiTbFlushTimeStamp;
        __dmb(0xBu);
        v14 = (v13 - v10) & 0xFFFFF;
        if ( v14 > 2 || (v10 & 1) == 0 && v14 >= 2 )
        {
LABEL_22:
          v3 = 0;
          v19 = v10;
          goto LABEL_17;
        }
        if ( (v13 & 1) == 0 )
          break;
        __dmb(0xFu);
        v16 = KiTbFlushTimeStamp;
        __dmb(0xBu);
        if ( (v16 & 1) != 0 )
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v17 = KiTbFlushTimeStamp;
            __dmb(0xBu);
          }
          while ( (v17 & 1) != 0 );
        }
        if ( (v10 & 1) == 0 )
          goto LABEL_22;
      }
      MiInsertTbFlushEntry(&v20, a1 << 10, 1);
      v3 = 1;
      v19 = v10;
      goto LABEL_17;
    }
    if ( v3 == 1 )
    {
      MiInsertTbFlushEntry(&v20, a1 << 10, 1);
      v3 = v18;
    }
LABEL_18:
    ++v6;
    a1 += 4;
  }
  while ( v6 < a2 );
  v5 = v24;
LABEL_20:
  MiFlushTbList(&v20);
  return v5;
}
