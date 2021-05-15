// BiResolveLocateDevice 
 
int __fastcall BiResolveLocateDevice(int a1, _DWORD *a2)
{
  unsigned int v3; // r6
  unsigned __int16 *v5; // r8
  int v6; // r3
  unsigned int v7; // r1
  int v8; // r4
  int v9; // r0
  unsigned __int16 *v10; // r5
  __int16 v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  int v17; // [sp+0h] [bp-68h] BYREF
  int v18; // [sp+4h] [bp-64h]
  int v19[8]; // [sp+8h] [bp-60h] BYREF

  v17 = 0;
  v18 = 0;
  v3 = 0;
  v5 = (unsigned __int16 *)((char *)a2 + a2[6]);
  if ( *(_DWORD *)v5 != 2 )
    goto LABEL_13;
  v6 = a2[5];
  if ( !v6 )
  {
    v7 = a2[7];
    if ( (v7 & 0xF000000) == 0x2000000 )
    {
      v19[0] = 0;
      v8 = BcdGetElementData(a1, v7, 0, v19);
      if ( v8 != -1073741789 )
        goto LABEL_14;
      v9 = ExAllocatePoolWithTag(1, v19[0], 1262764866);
      v3 = v9;
      if ( !v9 )
      {
        v8 = -1073741670;
        goto LABEL_14;
      }
      BcdGetElementData(a1, a2[7], v9, v19);
      v10 = (unsigned __int16 *)v3;
      goto LABEL_10;
    }
LABEL_13:
    v8 = -1073741637;
    goto LABEL_14;
  }
  if ( v6 != 1 )
    goto LABEL_13;
  v10 = (unsigned __int16 *)(a2 + 8);
LABEL_10:
  v11 = wcslen(v5 + 10);
  HIWORD(v17) = 2 * (wcslen(v10) + v11 + 1);
  v18 = ExAllocatePoolWithTag(1, HIWORD(v17), 1262764866);
  if ( !v18 )
  {
    v8 = -1073741670;
    goto LABEL_16;
  }
  RtlAppendUnicodeToString((unsigned __int16 *)&v17, (int)(v5 + 10), v12, v13);
  RtlAppendUnicodeToString((unsigned __int16 *)&v17, (int)v10, v14, v15);
  v19[2] = 24;
  v19[3] = 0;
  v19[5] = 576;
  v19[4] = (int)&v17;
  v19[6] = 0;
  v19[7] = 0;
  v8 = ZwQueryAttributesFile();
LABEL_14:
  if ( v18 )
    ExFreePoolWithTag(v18);
LABEL_16:
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v8;
}
