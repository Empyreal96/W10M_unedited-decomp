// BiAddBootEntryToEfiBootManagerDisplayOrder 
 
int __fastcall BiAddBootEntryToEfiBootManagerDisplayOrder(int a1, _DWORD *a2)
{
  int v3; // r4
  int v4; // r8
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r5
  unsigned int v9; // r7
  _DWORD *v10; // r0
  unsigned int v11; // r5
  int v12; // r2
  unsigned int v14; // [sp+8h] [bp-28h] BYREF
  unsigned int v15[9]; // [sp+Ch] [bp-24h] BYREF

  v14 = 0;
  v15[0] = 0;
  v3 = BcdOpenObject(a1, &GUID_FIRMWARE_BOOTMGR, &v14);
  v4 = v14;
  if ( v3 < 0 )
    goto LABEL_15;
  v5 = BiGetElement(v14, 603979777, (int *)v15, &v14);
  v3 = v5;
  v6 = v15[0];
  if ( v5 == -1073741275 )
  {
    v7 = 0;
    goto LABEL_6;
  }
  if ( v5 >= 0 )
  {
    v7 = v14;
LABEL_6:
    v8 = 0;
    v9 = v15[0];
    if ( v7 >> 4 )
    {
      while ( memcmp((unsigned int)(a2 + 2), v9, 16) )
      {
        ++v8;
        v9 += 16;
        if ( v8 >= v7 >> 4 )
          goto LABEL_9;
      }
      v3 = 0;
    }
    else
    {
LABEL_9:
      v10 = (_DWORD *)ExAllocatePoolWithTag(1, v7 + 16, 1262764866);
      v11 = (unsigned int)v10;
      if ( v10 )
      {
        *v10 = a2[2];
        v10[1] = a2[3];
        v10[2] = a2[4];
        v10[3] = a2[5];
        memmove((int)(v10 + 4), v6, v7);
        v3 = BcdSetElementDataWithFlags(v4, 0x24000001u, v12, v11, v7 + 16);
        ExFreePoolWithTag(v11);
      }
      else
      {
        v3 = -1073741801;
      }
    }
  }
  if ( v6 )
    ExFreePoolWithTag(v6);
LABEL_15:
  if ( v4 )
    BcdCloseObject(v4);
  return v3;
}
