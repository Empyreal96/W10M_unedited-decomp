// MiMakeImageReadOnly 
 
int __fastcall MiMakeImageReadOnly(int result)
{
  int v1; // r7
  int v2; // r5
  int v3; // r6
  __int16 v4; // r2
  unsigned int v5; // r4
  unsigned int v6; // r9
  int v7; // r10
  int v8; // r1
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r2
  int v14; // r7
  int v15; // r0
  int v16; // r7
  int v17; // r0
  char v18[4]; // [sp+0h] [bp-30h] BYREF
  int v19; // [sp+4h] [bp-2Ch]
  unsigned int v20; // [sp+8h] [bp-28h]
  int v21; // [sp+Ch] [bp-24h]
  unsigned int v22; // [sp+10h] [bp-20h]

  v1 = 0;
  v2 = 17;
  v3 = result + 80;
  v21 = result + 80;
  v19 = 0;
  v18[0] = 17;
  if ( result != -80 )
  {
    v20 = 0x3FFFFF;
    do
    {
      v4 = *(_WORD *)(v3 + 16);
      if ( (v4 & 0x3E) != 2 )
      {
        v5 = *(_DWORD *)(v3 + 4);
        *(_WORD *)(v3 + 16) = v4 & 0xFFC1 | 2;
        v22 = v5 + 4 * *(_DWORD *)(v3 + 28);
        if ( v5 < v22 )
        {
          v6 = v5 + 1070596096;
          while ( 1 )
          {
            v7 = v5 & 0xFFF;
            if ( v2 == 17 || (v5 & 0xFFF) == 0 )
            {
              if ( v2 != 17 )
                return sub_51AB3C();
              while ( 1 )
              {
                v19 = MiLockProtoPoolPage(v5, v18);
                if ( v19 )
                  break;
                MmAccessFault(1, v5, 0, 0);
              }
              v2 = (unsigned __int8)v18[0];
            }
            result = MiLockLeafPage(v5, 0);
            v8 = *(_DWORD *)v5;
            v9 = result;
            if ( result )
            {
              if ( (v8 & 2) == 0 )
              {
                v10 = v8 & 0xFFFFFC1F | 0x20;
                if ( v6 + 3145728 <= v20 )
                {
                  v16 = 0;
                  __dmb(0xBu);
                  *(_DWORD *)v5 = v10;
                  if ( (v8 & 2) == 0 && (v10 & 2) != 0 )
                    v16 = 1;
                  if ( v6 <= 0xFFF )
                  {
                    v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v17, v17 + 4 * v7, v10);
                  }
                  if ( v16 == 1 )
                  {
                    __dsb(0xFu);
                    __isb(0xFu);
                  }
                }
                else
                {
                  *(_DWORD *)v5 = v10;
                }
                v11 = *(_DWORD *)(v9 + 8);
                if ( (v11 & 0x400) == 0 )
                  *(_DWORD *)(v9 + 8) = v11 & 0xFFFFFC1F | 0x20;
              }
              __dmb(0xBu);
              v12 = (unsigned int *)(v9 + 12);
              do
                result = __ldrex(v12);
              while ( __strex(result & 0x7FFFFFFF, v12) );
            }
            else if ( (v8 & 0x400) == 0 && v8 )
            {
              result = v20;
              v13 = v8 & 0xFFFFFC1F | 0x20;
              if ( v6 + 3145728 > v20 )
              {
                *(_DWORD *)v5 = v13;
              }
              else
              {
                v14 = 0;
                __dmb(0xBu);
                *(_DWORD *)v5 = v13;
                if ( (v8 & 2) == 0 && (v13 & 2) != 0 )
                  v14 = 1;
                if ( v6 <= 0xFFF )
                {
                  v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  result = MiArmWriteConvertedHardwarePde(v15, v15 + 4 * v7, v13);
                }
                if ( v14 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
            }
            v5 += 4;
            v6 += 4;
            if ( v5 >= v22 )
            {
              v3 = v21;
              v1 = v19;
              break;
            }
          }
        }
        if ( v2 != 17 )
        {
          result = MiUnlockProtoPoolPage(v1, v2);
          v2 = 17;
          v18[0] = 17;
        }
      }
      v3 = *(_DWORD *)(v3 + 8);
      v21 = v3;
    }
    while ( v3 );
  }
  return result;
}
