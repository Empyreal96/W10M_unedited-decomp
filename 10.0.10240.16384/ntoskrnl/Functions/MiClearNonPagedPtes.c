// MiClearNonPagedPtes 
 
int __fastcall MiClearNonPagedPtes(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r5
  _DWORD *v3; // r2
  int v4; // r4
  unsigned int v5; // r6
  int v6; // r10
  int v7; // r4
  int v8; // r0
  int result; // r0
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r4
  int v13; // r4
  int v14; // r3
  unsigned int v15; // r2
  int v16; // r0
  char v17[4]; // [sp+0h] [bp-D0h] BYREF
  int v18; // [sp+4h] [bp-CCh]
  _DWORD *v19; // [sp+8h] [bp-C8h]
  unsigned int v20; // [sp+Ch] [bp-C4h]
  int v21; // [sp+10h] [bp-C0h]
  int v22; // [sp+18h] [bp-B8h] BYREF
  char v23; // [sp+1Ch] [bp-B4h]
  char v24; // [sp+1Dh] [bp-B3h]
  int v25; // [sp+20h] [bp-B0h]
  int v26; // [sp+24h] [bp-ACh]
  int v27; // [sp+28h] [bp-A8h]
  int v28; // [sp+2Ch] [bp-A4h]

  v2 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = (_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  v20 = a2;
  v21 = MmProtectFreedNonPagedPool;
  v22 = 0;
  v24 = 0;
  v4 = 0;
  v5 = 0;
  v25 = 33;
  v26 = 0;
  v18 = 0;
  v19 = v3;
  v23 = 0;
  v27 = 0;
  v28 = 0;
  v6 = 1;
  if ( a2 )
  {
    do
    {
      if ( v6 != 1 && (v2 & 0xFFF) != 0 )
        goto LABEL_4;
      if ( !v6 )
        v19 = ++v3;
      v6 = 0;
      if ( (*v3 & 0x400) != 0 )
      {
        v15 = (4096 - (v2 & 0xFFF)) >> 2;
        if ( v15 + v5 > a2 )
          v15 = a2 - v5;
        v5 += v15;
        v2 += 4 * v15;
      }
      else
      {
LABEL_4:
        v7 = MiLockNonPagedPoolPte(v2, v17);
        v8 = v18;
        *(_BYTE *)(v7 + 18) = *(_BYTE *)(v7 + 18) & 0xF8 | 5;
        *(_DWORD *)v7 = v8;
        v18 = v7;
        if ( v2 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v2 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v2 = 0;
          if ( v2 >= 0xC0300000 )
            return sub_54BDEC();
        }
        v10 = (unsigned __int8)v17[0];
        if ( v17[0] != 17 )
        {
          __dmb(0xBu);
          v11 = (unsigned int *)(v7 + 12);
          do
            v12 = __ldrex(v11);
          while ( __strex(v12 & 0x7FFFFFFF, v11) );
          KfLowerIrql(v10);
        }
        v13 = 0;
        if ( !v21 )
        {
          __dmb(0xFu);
          v14 = KiTbFlushTimeStamp;
          __dmb(0xBu);
          v13 = v14 << 12;
          if ( v2 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v2 = v13;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v2 = v13;
            if ( v2 >= 0xC0300000 && v2 <= 0xC0300FFF )
            {
              v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v2 & 0xFFF)), v13);
            }
          }
        }
        if ( (v13 & 0xFFFFF000) == 0 )
          MiInsertTbFlushEntry((int)&v22, v2 << 10, 1, 0);
        a2 = v20;
        ++v5;
        v2 += 4;
      }
      v3 = v19;
    }
    while ( v5 < a2 );
    v4 = v18;
  }
  MiFlushTbList((unsigned int)&v22, a2);
  result = v4;
  if ( (dword_682604 & 1) != 0 )
  {
    if ( v4 )
    {
      MiLogNonPagedPoolReleaseEvent(v4);
      result = v4;
    }
  }
  return result;
}
