// SepAdtSecurityDescriptorChangedAuditAlarm 
 
int __fastcall SepAdtSecurityDescriptorChangedAuditAlarm(int *a1, unsigned __int16 *a2, unsigned __int16 *a3, unsigned __int16 *a4, int a5, int a6, int a7, int a8, int a9)
{
  int v12; // r0
  int result; // r0
  int v14; // r7
  int v15; // r3
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r0
  int v23; // r0
  int v25; // [sp+8h] [bp-2C0h]
  int v26[174]; // [sp+10h] [bp-2B8h] BYREF

  v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v25 = *(_DWORD *)(v12 + 176);
  result = SeLocateProcessImageName(v12);
  v14 = result;
  if ( result >= 0 )
  {
    memset(v26, 0, 664);
    if ( (a8 & 8) != 0 )
    {
      v26[0] = 6;
      LOWORD(v26[4]) = 138;
      v15 = 4907;
    }
    else if ( (a8 & 0x20) != 0 )
    {
      v26[0] = 3;
      LOWORD(v26[4]) = 140;
      v15 = 4911;
    }
    else
    {
      v26[0] = 3;
      LOWORD(v26[4]) = 140;
      if ( (a8 & 0x40) != 0 )
        v15 = 4913;
      else
        v15 = 4670;
    }
    v26[1] = v15;
    HIWORD(v26[4]) = 8;
    v26[6] = 4;
    v16 = *(unsigned __int8 *)(a6 + 1);
    v26[10] = a6;
    v26[15] = (int)a2;
    v26[7] = 4 * (v16 + 2);
    v26[11] = 1;
    v17 = *a2 + 8;
    v26[12] = v17;
    v18 = *a1;
    if ( *a1 )
    {
      v26[16] = 5;
      v26[17] = 8;
    }
    else
    {
      v26[16] = 5;
      v26[17] = 8;
      v18 = a1[2];
    }
    v19 = *(_DWORD *)(v18 + 24);
    v26[22] = v17;
    v26[25] = (int)a2;
    v26[18] = v19;
    v20 = *(_DWORD *)(v18 + 28);
    v26[30] = (int)a3;
    v26[19] = v20;
    v26[21] = 1;
    v26[26] = 1;
    v26[27] = *a3 + 8;
    if ( a4 )
    {
      v26[31] = 2;
      v21 = *a4;
      v26[35] = (int)a4;
      v26[32] = v21 + 8;
    }
    v26[36] = 11;
    v26[37] = 4;
    v26[38] = ObNormalizeHandleValue(a5);
    v26[41] = 24;
    v22 = SepSecurityDescriptorStrictLength(a7);
    v26[45] = a7;
    v26[43] = a8;
    v26[44] = 4;
    v26[42] = v22;
    v26[46] = 24;
    v23 = SepSecurityDescriptorStrictLength(a9);
    v26[49] = 4;
    v26[50] = a9;
    v26[51] = 11;
    v26[52] = 4;
    v26[47] = v23;
    v26[48] = a8;
    v26[60] = 0;
    v26[53] = v25;
    v26[56] = 2;
    v26[57] = MEMORY[0] + 8;
    v26[2] = 11;
    result = SepAdtLogAuditRecord((int)v26);
  }
  if ( v14 < 0 )
    result = SepAuditFailed();
  return result;
}
