// MiZeroAndFlushPtes 
 
unsigned int __fastcall MiZeroAndFlushPtes(unsigned int result, unsigned int a2)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r3
  int v5; // r4
  int v6; // r7
  int v7; // r5
  _QWORD *v8; // r2
  int v9; // r3
  int *v10; // r5
  _DWORD *v11; // r3
  unsigned int v12; // r9
  unsigned int v13; // r8
  int v14; // r6
  int v15; // r0
  _QWORD *v16; // r3
  _QWORD *v17; // r2
  int v18; // r3
  int *v19; // r4
  int v20; // r6
  int v21; // r0
  int *v22; // r4
  int v23; // r5
  int v24; // [sp+8h] [bp-138h] BYREF
  char v25; // [sp+Ch] [bp-134h]
  char v26; // [sp+Dh] [bp-133h]
  int v27; // [sp+10h] [bp-130h]
  int v28; // [sp+14h] [bp-12Ch]
  int v29; // [sp+18h] [bp-128h]
  int v30; // [sp+1Ch] [bp-124h]
  _DWORD v31[40]; // [sp+A0h] [bp-A0h] BYREF

  v2 = ((result >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = ((result >> 20) & 0xFFC) - 1070596096;
  v4 = *(_DWORD *)v3;
  if ( !*(_DWORD *)v3 )
    return result;
  v28 = 0;
  v29 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 33;
  v30 = 0;
  v5 = 0;
  v6 = a2;
  if ( (v4 & 0x400) == 0 )
    goto LABEL_3;
  v6 = a2 & 0x3FF;
  v12 = v3 + 4 * (a2 >> 10);
  if ( v3 >= v12 )
  {
LABEL_27:
    v2 = v3 << 10;
LABEL_3:
    while ( v6 )
    {
      v7 = *(_DWORD *)v2 >> 12;
      if ( v2 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v2 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v2 = 0;
        if ( v2 >= 0xC0300000 && v2 <= 0xC0300FFF )
        {
          v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v21, v21 + 4 * (v2 & 0xFFF), 0);
        }
      }
      MiInsertTbFlushEntry(&v24, v2 << 10, 1);
      if ( !MI_IS_PFN(v7) )
      {
        if ( v5 && (v8 = &v31[2 * v5], v9 = *((_DWORD *)v8 - 1), v9 == v7) )
        {
          *((_DWORD *)v8 - 1) = v9 + 1;
        }
        else
        {
          v11 = &v31[2 * v5];
          *v11 = v7;
          ++v5;
          v11[1] = v7 + 1;
          if ( v5 == 16 )
          {
            MiFlushTbList(&v24);
            v22 = v31;
            v23 = 16;
            do
            {
              MiDereferenceIoPages(1, *v22, v22[1] - *v22);
              v22 += 2;
              --v23;
            }
            while ( v23 );
            v5 = 0;
          }
        }
      }
      v2 += 4;
      --v6;
    }
    result = MiFlushTbList(&v24);
    if ( v5 )
    {
      v10 = v31;
      do
      {
        result = MiDereferenceIoPages(1, *v10, v10[1] - *v10);
        v10 += 2;
        --v5;
      }
      while ( v5 );
    }
    return result;
  }
  v13 = (result >> 20) & 0xFFC;
  while ( 1 )
  {
    v14 = *(_DWORD *)v3 >> 12;
    if ( v13 + 3145728 > 0x3FFFFF )
      return sub_513DD8();
    __dmb(0xBu);
    *(_DWORD *)v3 = 0;
    if ( v13 <= 0xFFF )
    {
      v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v15, v15 + 4 * (v3 & 0xFFF), 0);
    }
    MiInsertTbFlushEntry(&v24, v3 << 20, 1);
    if ( !MI_IS_PFN(v14) )
    {
      if ( v5 && (v17 = &v31[2 * v5], v18 = *((_DWORD *)v17 - 1), v18 == v14) )
      {
        *((_DWORD *)v17 - 1) = v18 + 1024;
      }
      else
      {
        v31[2 * v5] = v14;
        v16 = &v31[2 * v5++];
        *((_DWORD *)v16 + 1) = v14 + 1024;
        if ( v5 == 16 )
        {
          MiFlushTbList(&v24);
          v19 = v31;
          v20 = 16;
          do
          {
            MiDereferenceIoPages(1, *v19, v19[1] - *v19);
            v19 += 2;
            --v20;
          }
          while ( v20 );
          v5 = 0;
        }
      }
    }
    v3 += 4;
    v13 += 4;
    if ( v3 >= v12 )
      goto LABEL_27;
  }
}
