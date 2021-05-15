// SeOperationAuditAlarm 
 
int __fastcall SeOperationAuditAlarm(int a1, int a2, int a3, unsigned __int16 *a4, int a5, int a6, int a7)
{
  unsigned int v7; // r4
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r6
  int v12; // r0
  int v13; // r7
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  unsigned int v22; // r0
  int result; // r0
  char v24[4]; // [sp+0h] [bp-2E8h] BYREF
  int v25[2]; // [sp+4h] [bp-2E4h] BYREF
  unsigned __int16 *v26; // [sp+Ch] [bp-2DCh] BYREF
  int v27; // [sp+10h] [bp-2D8h] BYREF
  int v28; // [sp+14h] [bp-2D4h]
  int v29; // [sp+18h] [bp-2D0h]
  int v30[2]; // [sp+20h] [bp-2C8h] BYREF
  int v31; // [sp+28h] [bp-2C0h]
  int v32[174]; // [sp+30h] [bp-2B8h] BYREF

  v7 = a7;
  v29 = a3;
  v9 = 0;
  v25[0] = a7;
  v25[1] = 0;
  v28 = a2;
  v26 = 0;
  v10 = 0;
  v24[0] = 0;
  v11 = SepAdtClassifyObjectIntoSubCategory(a2, a4, 1, 0);
  v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v27 = *(_DWORD *)(v12 + 176);
  v13 = SeLocateProcessImageName(v12);
  if ( v13 < 0 )
  {
LABEL_23:
    result = SepAuditFailed();
    goto LABEL_24;
  }
  memset(v32, 0, 664);
  v32[0] = 3;
  v32[1] = 4663;
  HIWORD(v32[4]) = 8;
  LOWORD(v32[4]) = v11;
  SeCaptureSubjectContext(v30, v14, v15, 8);
  v16 = v30[0];
  if ( !v30[0] )
    v16 = v31;
  v17 = **(_DWORD **)(v16 + 148);
  v32[6] = 4;
  v18 = *(unsigned __int8 *)(v17 + 1);
  v32[10] = v17;
  v32[7] = 4 * (v18 + 2);
  v32[11] = 1;
  v32[12] = 24;
  v32[15] = (int)&SeSubsystemName;
  v32[16] = 5;
  v32[17] = 8;
  if ( v30[0] )
  {
    v32[18] = *(_DWORD *)(v30[0] + 24);
    v19 = *(_DWORD *)(v30[0] + 28);
  }
  else
  {
    v32[18] = *(_DWORD *)(v31 + 24);
    v19 = *(_DWORD *)(v31 + 28);
  }
  v32[19] = v19;
  v32[21] = 1;
  v32[22] = 24;
  v32[25] = (int)&SeSubsystemName;
  v32[26] = 1;
  v32[27] = *a4 + 8;
  v32[30] = (int)a4;
  SepQueryNameString(v28, &v26);
  v9 = (unsigned int)v26;
  if ( v26 )
  {
    if ( v11 == 116 || v11 == 128 )
      v20 = 2;
    else
      v20 = 1;
    v32[31] = v20;
    v21 = *v26;
    v32[35] = (int)v26;
    v32[32] = v21 + 8;
  }
  v32[36] = 11;
  v32[37] = 4;
  v22 = ObNormalizeHandleValue(v29);
  v32[41] = 7;
  v32[42] = 4;
  v32[43] = a5;
  v32[44] = 4;
  v32[48] = a5;
  v32[51] = 11;
  v32[52] = 4;
  v32[46] = 10;
  v32[53] = v27;
  v32[56] = 2;
  v32[38] = v22;
  v32[57] = MEMORY[0] + 8;
  v32[2] = 11;
  v32[47] = 4;
  v32[60] = 0;
  if ( (v11 == 116 || v11 == 128) && a7 )
  {
    result = SepCheckAndCopySelfRelativeSD(a7, v25, &v27, v24);
    v13 = result;
    v7 = v25[0];
    if ( result < 0 )
    {
      v10 = (unsigned __int8)v24[0];
      goto LABEL_19;
    }
    v32[61] = 31;
    v32[62] = SepSecurityDescriptorStrictLength(v25[0]);
    v32[63] = 32;
    v10 = (unsigned __int8)v24[0];
    v32[64] = 0;
    v32[65] = v7;
  }
  v32[2] = 12;
  SepAdtLogAuditRecord((int)v32);
  result = SeReleaseSubjectContext((int)v30);
LABEL_19:
  if ( v10 && v7 )
    result = ExFreePoolWithTag(v7);
  if ( v13 < 0 )
    goto LABEL_23;
LABEL_24:
  if ( v9 )
    result = ExFreePoolWithTag(v9);
  return result;
}
