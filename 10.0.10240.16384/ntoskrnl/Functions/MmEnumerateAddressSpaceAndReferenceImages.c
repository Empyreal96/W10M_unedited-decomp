// MmEnumerateAddressSpaceAndReferenceImages 
 
int __fastcall MmEnumerateAddressSpaceAndReferenceImages(_DWORD *a1, char a2)
{
  char v2; // r7
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r10
  unsigned int v9; // r3
  _DWORD *v10; // r4
  unsigned int v11; // r2
  int v12; // r1
  unsigned int v13; // r1
  int v14; // r8
  _DWORD *v15; // r3
  _DWORD *v16; // r5
  _DWORD *v17; // r3
  int v18; // r6
  _DWORD *v19; // r2
  int v20; // r0
  int v21; // r3
  int v22; // r3
  unsigned int v23; // r2
  char v24; // r2
  int v25; // [sp+0h] [bp-40h]
  _DWORD *v26; // [sp+4h] [bp-3Ch]
  char v27[56]; // [sp+8h] [bp-38h] BYREF

  v2 = (a2 & 1) != 0;
  if ( (a2 & 2) != 0 )
    return sub_802DF8();
  if ( (a2 & 4) != 0 )
    v2 |= 4u;
  v10 = 0;
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD **)(v14 + 0x74) == a1 )
  {
    v25 = 0;
  }
  else
  {
    KiStackAttachProcess((int)a1, 0, (int)v27);
    v25 = 1;
  }
  LOCK_ADDRESS_SPACE_SHARED(v14, (int)a1);
  v12 = a1[161];
  if ( v12 )
  {
    v13 = v12 + 1;
    if ( v13 <= 0x7FFFFFF )
    {
      v10 = (_DWORD *)ExAllocatePoolWithTag(1, 32 * v13, 808546381);
      v26 = v10;
      if ( v10 )
      {
        v15 = (_DWORD *)a1[159];
        v16 = 0;
        while ( v15 )
        {
          v16 = v15;
          v15 = (_DWORD *)*v15;
        }
        if ( !v16 )
        {
LABEL_18:
          *v10 = 0;
          v10 = v26;
          goto LABEL_27;
        }
        while ( 1 )
        {
          v17 = (_DWORD *)v16[1];
          v18 = (int)v16;
          v19 = v16;
          if ( v17 )
          {
            do
            {
              v16 = v17;
              v17 = (_DWORD *)*v17;
            }
            while ( v17 );
          }
          else
          {
            while ( 1 )
            {
              v16 = (_DWORD *)(v16[2] & 0xFFFFFFFC);
              if ( !v16 || (_DWORD *)*v16 == v19 )
                break;
              v19 = v16;
            }
          }
          MiLockVad(v14, v18);
          if ( MiVadDeleted(v18) || v5 == 1 )
          {
LABEL_20:
            MiUnlockVad(v14, v18);
            goto LABEL_17;
          }
          if ( (v6 & 0x8000) != 0 )
            break;
          if ( v5 == 2 )
          {
            v7 = v6 & 0xF8;
            if ( v7 == 56 && (v2 & 1) != 0 )
            {
              v8 = **(_DWORD **)(v18 + 44);
              *v10 = MI_REFERENCE_CONTROL_AREA_FILE(v8);
              v10[1] = *(_DWORD *)(v18 + 12) << 12;
              v10[2] = *(_DWORD *)(*(_DWORD *)v8 + 24);
              v10[3] = (*(_DWORD *)(v18 + 16) - *(_DWORD *)(v18 + 12) + 1) << 12;
              v10[5] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v8 + 36) + 44);
              if ( (*(_DWORD *)(v18 + 40) & 0x10000000) != 0 )
              {
                v9 = v10[1] & 0xFFFFE03F;
              }
              else
              {
                v11 = v10[1] & 0xFFFFFC3F | (4 * (*(_BYTE *)(*(_DWORD *)v8 + 11) & 0xF0));
                v10[1] = v11;
                v9 = ((unsigned __int16)v11 ^ (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)v8 + 11) << 9)) & 0x1C00 ^ v11;
              }
              v10[1] = v9;
              if ( (v2 & 2) != 0 )
              {
                v23 = v10[1] & 0xFFFFFFFE | *(_BYTE *)(v18 + 43) & 1;
                v10[1] = v23;
                v10[1] = ((unsigned __int8)v23 ^ (unsigned __int8)(*(_DWORD *)(v18 + 28) >> 2)) & 0x3E ^ v23;
                v10[4] = *(_DWORD *)(v18 + 32) << 12;
              }
              goto LABEL_16;
            }
          }
          if ( (v2 & 2) == 0 )
            goto LABEL_20;
          MiFillMapFileInfo(v18, v10, v6, v7);
          v24 = 1;
LABEL_56:
          *v10 = *v10 & 0xFFFFFFFC | v24 & 3;
LABEL_16:
          MiUnlockVad(v14, v18);
          v10 += 8;
LABEL_17:
          if ( !v16 )
            goto LABEL_18;
        }
        if ( (v2 & 4) == 0 )
          goto LABEL_20;
        *v10 = *(_DWORD *)(v18 + 12) << 12;
        v10[1] = (*(_DWORD *)(v18 + 16) - *(_DWORD *)(v18 + 12) + 1) << 12;
        v20 = *(_DWORD *)(v18 + 32);
        if ( (v20 & 0x7FFFFFFFu) < 0x7FFFE )
          v21 = v20 << 12;
        else
          v21 = 0;
        v10[4] = v21;
        v10[2] = a1[44];
        v10[3] = 0x2000;
        switch ( v5 )
        {
          case 3:
            v22 = (int)L"AppPatch\\drvmain.sdb";
            break;
          case 4:
            v22 = 2105344;
            break;
          case 5:
            v22 = 536879104;
            break;
          case 6:
            v22 = (int)&dword_802000;
            break;
          default:
LABEL_55:
            v24 = 2;
            goto LABEL_56;
        }
        v10[3] = v22;
        goto LABEL_55;
      }
    }
  }
LABEL_27:
  UNLOCK_ADDRESS_SPACE_SHARED(v14, (int)a1);
  if ( v25 == 1 )
    KiUnstackDetachProcess((unsigned int)v27, 0);
  return (int)v10;
}
