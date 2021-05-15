// BiBindEfiBootManager 
 
int __fastcall BiBindEfiBootManager(int a1, int a2)
{
  unsigned int v4; // r7
  int v5; // r2
  int v6; // r3
  int v7; // r4
  int v8; // r6
  int v9; // r2
  unsigned int v10; // r8
  int v11; // r3
  int v12; // r0
  unsigned int v13; // r5
  int v15; // r1
  int v16; // r2
  int v17; // [sp+8h] [bp-50h] BYREF
  unsigned int v18; // [sp+Ch] [bp-4Ch] BYREF
  unsigned int v19[4]; // [sp+10h] [bp-48h] BYREF
  int v20[2]; // [sp+20h] [bp-38h] BYREF
  char v21[48]; // [sp+28h] [bp-30h] BYREF

  v18 = 0;
  v19[0] = 0;
  v17 = 0;
  v4 = 0;
  if ( BcdOpenObject(a1, &GUID_FIRMWARE_BOOTMGR, &v17) >= 0 )
  {
    BcdDeleteObject(v17);
    v17 = 0;
  }
  v20[0] = 1;
  v20[1] = 269484033;
  v7 = BcdCreateObject(a1, (int)&GUID_FIRMWARE_BOOTMGR, (int)v20, (int)&v17);
  v8 = v17;
  if ( v7 < 0 )
    goto LABEL_20;
  v7 = BiQueryBootEntryOrder((int *)&v18, &v17, v5, v6);
  v10 = v18;
  if ( v7 >= 0 )
  {
    v11 = v17;
    if ( !v17 )
    {
LABEL_9:
      v7 = BiQueryBootOptions((int *)v19, &v18, v9, v11);
      v13 = v19[0];
      if ( v7 >= 0 )
      {
        if ( *(_DWORD *)(v19[0] + 8) != -1 )
          return sub_8146C0();
        v15 = *(_DWORD *)(v19[0] + 16);
        if ( v15 == -2
          || BiTranslateBootEntryId(a2, v15, v21) < 0
          || (v7 = BcdSetElementDataWithFlags(v8, 0x24000002u, v16, (int)v21, 16), v7 >= 0) )
        {
          v7 = 0;
        }
      }
      if ( v13 )
        ExFreePoolWithTag(v13);
      goto LABEL_16;
    }
    v12 = ExAllocatePoolWithTag(1, 16 * v17, 1262764866);
    v4 = v12;
    if ( v12 )
    {
      BiTranslateBootOrder(a2, v10, v12, &v17);
      v11 = v17;
      if ( !v17 )
        goto LABEL_9;
      v7 = BcdSetElementDataWithFlags(v8, 0x24000001u, v9, v4, 16 * v17);
      if ( v7 >= 0 )
        goto LABEL_9;
    }
    else
    {
      v7 = -1073741670;
    }
  }
LABEL_16:
  if ( v10 )
    ExFreePoolWithTag(v10);
  if ( v4 )
    ExFreePoolWithTag(v4);
LABEL_20:
  if ( v8 )
  {
    if ( v7 < 0 )
      BcdDeleteObject(v8);
    else
      BcdCloseObject(v8);
  }
  return v7;
}
