// SepAdtDeleteObjectAuditAlarm 
 
unsigned int __fastcall SepAdtDeleteObjectAuditAlarm(int a1, int a2, int *a3, int a4, _DWORD *a5, unsigned __int8 a6)
{
  __int16 *v6; // r6
  unsigned int result; // r0
  int v10; // r0
  unsigned __int16 *v11; // r4
  _DWORD *v12; // r7
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int *v16; // r3
  int v17; // r1
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  __int16 v23; // [sp+10h] [bp-2C8h] BYREF
  unsigned __int16 *v24; // [sp+14h] [bp-2C4h]
  int v25[166]; // [sp+18h] [bp-2C0h] BYREF
  _DWORD v26[10]; // [sp+2B0h] [bp-28h] BYREF

  v6 = (__int16 *)a1;
  v24 = 0;
  v26[0] = 0;
  v26[1] = 0;
  v26[2] = 0;
  v26[3] = 0;
  result = SepAdtAuditObjectAccessWithContext(a4, a1, 1, 0, 0, a6, &v23);
  if ( result )
  {
    v10 = SeLocateProcessImageName(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v11 = v24;
    if ( v10 < 0 )
    {
      result = SepAuditFailed();
    }
    else
    {
      v12 = a5;
      if ( !a5 )
        v12 = v26;
      memset(v25, 0, sizeof(v25));
      v25[0] = 3;
      LOWORD(v25[4]) = v23;
      v25[1] = 4660;
      HIWORD(v25[4]) = 8;
      if ( !v6 )
        v6 = &SeSubsystemName;
      v13 = *a3;
      v25[6] = 4;
      if ( v13 )
        v14 = v13;
      else
        v14 = a3[2];
      v25[7] = 4 * (*(unsigned __int8 *)(**(_DWORD **)(v14 + 148) + 1) + 2);
      if ( v13 )
        v15 = v13;
      else
        v15 = a3[2];
      v16 = *(int **)(v15 + 148);
      v25[15] = (int)v6;
      v25[10] = *v16;
      v25[11] = 1;
      v17 = (unsigned __int16)*v6 + 8;
      v25[16] = 5;
      v25[17] = 8;
      v25[12] = v17;
      if ( !v13 )
        v13 = a3[2];
      v18 = *(_DWORD *)(v13 + 24);
      v25[22] = v17;
      v25[18] = v18;
      v19 = *(_DWORD *)(v13 + 28);
      v25[25] = (int)v6;
      v25[19] = v19;
      v25[21] = 1;
      v25[26] = 11;
      v25[27] = 4;
      v25[28] = ObNormalizeHandleValue(a2);
      v20 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v25[31] = 11;
      v21 = *(_DWORD *)(v20 + 176);
      v25[32] = 4;
      v25[33] = v21;
      v25[36] = 2;
      v22 = *v11;
      v25[40] = (int)v11;
      v25[45] = (int)v12;
      v25[37] = v22 + 8;
      v25[41] = 13;
      v25[42] = 16;
      v25[2] = 8;
      result = SepAdtLogAuditRecord((int)v25);
    }
    if ( v11 )
      result = ExFreePoolWithTag((unsigned int)v11);
  }
  return result;
}
