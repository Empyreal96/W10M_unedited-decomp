// IopRaiseHardError 
 
int __fastcall IopRaiseHardError(_DWORD *a1, int a2, int a3)
{
  int v6; // r8
  int v7; // r0
  int v8; // r3
  unsigned int v9; // r4
  int v10; // r6
  int v11; // r2
  int v12; // r2
  int v13; // r1
  int v14; // r3
  int v15; // r6
  _BYTE *v17; // r2
  unsigned int v18; // [sp+8h] [bp-58h] BYREF
  int v19; // [sp+Ch] [bp-54h] BYREF
  __int16 v20[2]; // [sp+10h] [bp-50h] BYREF
  int v21; // [sp+14h] [bp-4Ch]
  char v22[24]; // [sp+18h] [bp-48h] BYREF
  __int16 *v23; // [sp+30h] [bp-30h]
  unsigned int v24; // [sp+34h] [bp-2Ch]
  int v25; // [sp+38h] [bp-28h]

  v18 = 0;
  v6 = 0;
  ObQueryNameStringMode(a3, 0, 0, &v18, 0);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v8 = 40;
    else
      v8 = 32;
    v7 = ExAllocatePoolWithTagPriority(1, v18, 538996553, v8);
  }
  else
  {
    v7 = ExAllocatePoolWithTag(1, v18, 538996553);
  }
  v9 = v7;
  if ( !v7 )
  {
    v10 = -1073741670;
LABEL_42:
    a1[6] = v10;
LABEL_43:
    a1[7] = 0;
    return IofCompleteRequest((int)a1, 1);
  }
  v10 = ObQueryNameStringMode(a3, v7, v18, &v19, 0);
  if ( v10 < 0 )
  {
    ExFreePoolWithTag(v9);
    goto LABEL_42;
  }
  if ( a2 && (*(_WORD *)(a2 + 4) & 1) != 0 )
  {
    v21 = a2 + 24;
    v20[0] = *(_WORD *)(a2 + 6);
    v20[1] = 64;
  }
  else
  {
    RtlInitUnicodeString((unsigned int)v20, 0);
  }
  v11 = a1[20];
  if ( *(_DWORD *)(v11 + 336) != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
  {
    KiStackAttachProcess(*(_DWORD *)(a1[20] + 336), 0, (int)v22);
    v6 = 1;
  }
  v12 = a1[6];
  if ( v12 == -1073741806 )
    goto LABEL_24;
  if ( v12 <= -1073741806 )
    goto LABEL_23;
  if ( v12 > -1073741804 )
  {
    if ( v12 != -1073741662 )
    {
      if ( v12 == -1073741661 || v12 == -1073741643 )
        goto LABEL_22;
LABEL_23:
      v13 = 0;
      goto LABEL_26;
    }
LABEL_24:
    v13 = 3;
    v23 = v20;
    v24 = v9;
    v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
    goto LABEL_25;
  }
LABEL_22:
  v13 = 2;
  v23 = (__int16 *)v9;
  v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
  v14 = 0;
LABEL_25:
  v25 = v14;
LABEL_26:
  if ( ExReadyForErrors )
  {
    v15 = ExRaiseHardError(a1[6], v13);
  }
  else
  {
    v15 = -1073741823;
    v19 = 0;
  }
  if ( v6 )
    KiUnstackDetachProcess((unsigned int)v22, 0);
  ExFreePoolWithTag(v9);
  if ( v15 >= 0 && v19 == 9 )
    return (*(int (__fastcall **)(_DWORD, _DWORD *))(*(_DWORD *)(*(_DWORD *)(a1[24] + 24) + 8)
                                                   + 4 * *(unsigned __int8 *)a1[24]
                                                   + 56))(
             *(_DWORD *)(a1[24] + 24),
             a1);
  if ( v19 == 3 )
  {
    v17 = (_BYTE *)a1[24];
    if ( *v17 == 13 && v17[1] == 1 )
      a1[7] = 1;
    else
      a1[6] = -1073741248;
  }
  if ( (a1[2] & 0x40) != 0 )
    goto LABEL_43;
  return IofCompleteRequest((int)a1, 1);
}
