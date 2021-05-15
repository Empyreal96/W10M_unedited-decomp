// MiCreatePebOrTeb 
 
int __fastcall MiCreatePebOrTeb(int a1, int a2, unsigned int a3, int *a4)
{
  unsigned int v4; // r5
  int v7; // r6
  _BYTE *v8; // r0
  _DWORD *v9; // r4
  _BYTE *v10; // r0
  unsigned int v11; // r10
  unsigned int v13; // r8
  unsigned int v14; // r3
  unsigned int v15; // r6
  unsigned int v16; // r5
  unsigned int v17; // r2
  int v18; // r8
  int v19; // r5
  unsigned int v20; // r5
  int v21; // [sp+8h] [bp-30h]
  int v22; // [sp+Ch] [bp-2Ch]

  v4 = a3;
  v7 = __mrc(15, 0, 13, 0, 3);
  v22 = v7;
  v8 = (_BYTE *)ExAllocatePoolWithTag(512, 76, 1818517846);
  v9 = v8;
  if ( v8 )
  {
    v10 = memset(v8, 0, 76);
    v9[2] = -2;
    v11 = MEMORY[0xC0402138];
    if ( (v4 & 0xFFF) != 0 )
      return sub_803678(v10);
    v13 = v4 >> 12;
    v9[8] = (v4 >> 12) | 0x80000000;
    v14 = v9[7] & 0xFFFFFF27 | 0x8020;
    v9[7] = v14;
    if ( v4 == 4096 )
      v9[7] = v14 | 0x10000;
    v9[6] = 0;
    v21 = 1;
    if ( v4 == 592 )
    {
      v15 = MEMORY[0xC0402134];
      v20 = v15 - ((ExGenRandom(1) & 0xF) << 12) - (v13 << 12) - 4096;
      LOCK_ADDRESS_SPACE(v22 & 0xFFFFFFC0, a1);
      if ( (v20 >= 0x10000 || *(_DWORD *)(a1 + 780)) && !MiCheckForConflictingVadExistence() )
      {
        v21 = 0;
        *a4 = v20;
        goto LABEL_13;
      }
      if ( v11 >= v15 )
      {
LABEL_9:
        if ( v15 < v13 << 12
          || (v16 = v15 - (v13 << 12), v16 < 0x10000) && !*(_DWORD *)(a1 + 780)
          || MiCheckForConflictingVadExistence() )
        {
          v19 = MiFindEmptyAddressRangeDown(a1 + 636, v13 << 12, 4096);
          if ( v19 < 0 )
          {
            v18 = 0;
LABEL_20:
            UNLOCK_ADDRESS_SPACE(v22 & 0xFFFFFFC0, a1);
            if ( v19 < 0 )
            {
              if ( v18 )
                ExFreePoolWithTag(v18);
              ExFreePoolWithTag((unsigned int)v9);
            }
            return v19;
          }
        }
        else
        {
          *a4 = v16;
        }
LABEL_13:
        v9[3] = (unsigned int)*a4 >> 12;
        v17 = (*a4 + a3 - 1) >> 12;
        v9[4] = v17;
        v18 = MiAddSecureEntry((int)v9, *a4, (v17 << 12) | 0xFFF, -2147483647, 0);
        if ( v18 )
        {
          v19 = MiInsertVadCharges((int)v9, a1);
          if ( v19 >= 0 )
          {
            if ( v15 == v11 && v21 == 1 && !a2 )
              MEMORY[0xC0402138] = *a4;
            MiGetWsAndInsertVad(v9);
          }
        }
        else
        {
          v19 = -1073741670;
        }
        goto LABEL_20;
      }
    }
    else
    {
      LOCK_ADDRESS_SPACE(v7 & 0xFFFFFFC0, a1);
    }
    v15 = v11;
    goto LABEL_9;
  }
  return -1073741801;
}
