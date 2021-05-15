// SepAdtCloseObjectAuditAlarm 
 
unsigned int __fastcall SepAdtCloseObjectAuditAlarm(int a1, int a2, int *a3, int a4, unsigned __int8 a5)
{
  __int16 *v5; // r6
  unsigned int result; // r0
  int v9; // r0
  int v10; // r7
  int v11; // r0
  unsigned __int16 *v12; // r4
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int *v16; // r3
  int v17; // r1
  int v18; // r3
  int v19; // r3
  unsigned int v20; // r0
  int v21; // r3
  __int16 v22; // [sp+10h] [bp-2B8h] BYREF
  unsigned __int16 *v23; // [sp+14h] [bp-2B4h]
  int v24[172]; // [sp+18h] [bp-2B0h] BYREF

  v5 = (__int16 *)a1;
  v23 = 0;
  result = SepAdtAuditObjectAccessWithContext(a4, a1, 1, 0, (int)a3, a5, &v22);
  if ( result )
  {
    result = SepAdtAuditThisEventWithContext(0x7Bu, 1, 0, a3);
    if ( result )
    {
      v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v10 = *(_DWORD *)(v9 + 176);
      v11 = SeLocateProcessImageName(v9);
      v12 = v23;
      if ( v11 < 0 )
      {
        result = SepAuditFailed();
      }
      else
      {
        memset(v24, 0, 664);
        v24[0] = 3;
        LOWORD(v24[4]) = v22;
        v24[1] = 4658;
        HIWORD(v24[4]) = 8;
        if ( !v5 )
          v5 = &SeSubsystemName;
        v13 = *a3;
        v24[6] = 4;
        if ( v13 )
          v14 = v13;
        else
          v14 = a3[2];
        v24[7] = 4 * (*(unsigned __int8 *)(**(_DWORD **)(v14 + 148) + 1) + 2);
        if ( v13 )
          v15 = v13;
        else
          v15 = a3[2];
        v16 = *(int **)(v15 + 148);
        v24[15] = (int)v5;
        v24[10] = *v16;
        v24[11] = 1;
        v17 = (unsigned __int16)*v5 + 8;
        v24[16] = 5;
        v24[17] = 8;
        v24[12] = v17;
        if ( !v13 )
          v13 = a3[2];
        v18 = *(_DWORD *)(v13 + 24);
        v24[22] = v17;
        v24[18] = v18;
        v19 = *(_DWORD *)(v13 + 28);
        v24[25] = (int)v5;
        v24[19] = v19;
        v24[21] = 1;
        v24[26] = 11;
        v24[27] = 4;
        v20 = ObNormalizeHandleValue(a2);
        v24[31] = 11;
        v24[32] = 4;
        v24[33] = v10;
        v24[36] = 2;
        v21 = *v12;
        v24[28] = v20;
        v24[40] = (int)v12;
        v24[37] = v21 + 8;
        v24[2] = 7;
        result = SepAdtLogAuditRecord((int)v24);
      }
      if ( v12 )
        result = ExFreePoolWithTag((unsigned int)v12);
    }
  }
  return result;
}
