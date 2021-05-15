// SeAuditHardLinkCreationWithTransaction 
 
int __fastcall SeAuditHardLinkCreationWithTransaction(unsigned __int16 *a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r3
  int v13; // r0
  int v14; // r3
  __int64 v15; // kr00_8
  int v16; // r3
  int v17; // r3
  int v19[2]; // [sp+0h] [bp-2D0h] BYREF
  int v20; // [sp+8h] [bp-2C8h]
  int v21; // [sp+Ch] [bp-2C4h]
  int v22; // [sp+10h] [bp-2C0h] BYREF
  int v23[165]; // [sp+14h] [bp-2BCh] BYREF
  _DWORD v24[10]; // [sp+2A8h] [bp-28h] BYREF

  v19[0] = 0;
  v19[1] = 0x80000000;
  v20 = 0;
  v21 = 0;
  memset(v23, 0, sizeof(v23));
  v24[0] = 0;
  v24[1] = 0;
  v24[2] = 0;
  v24[3] = 0;
  if ( !a4 )
    a4 = v24;
  v22 = 3;
  LOWORD(v23[3]) = 116;
  v23[0] = 4664;
  if ( a3 )
    v10 = 8;
  else
    v10 = 16;
  HIWORD(v23[3]) = v10;
  SeCaptureSubjectContext(v19, v8, v9, v10);
  v11 = v19[0];
  if ( v19[0] )
    v12 = v19[0];
  else
    v12 = v20;
  v13 = **(_DWORD **)(v12 + 148);
  if ( !v19[0] )
    v11 = v20;
  v23[5] = 4;
  v14 = *(unsigned __int8 *)(v13 + 1);
  v15 = *(_QWORD *)(v11 + 24);
  v23[9] = v13;
  v23[6] = 4 * (v14 + 2);
  v23[10] = 1;
  v23[11] = 24;
  *(_QWORD *)&v23[17] = v15;
  v23[14] = (int)&SeSubsystemName;
  v23[15] = 5;
  v23[16] = 8;
  v23[20] = 2;
  v16 = *a1;
  v23[24] = (int)a1;
  v23[29] = (int)a2;
  v23[21] = v16 + 8;
  v23[25] = 2;
  v17 = *a2;
  v23[34] = (int)a4;
  v23[26] = v17 + 8;
  v23[30] = 13;
  v23[31] = 16;
  v23[1] = 6;
  SepAdtLogAuditRecord((int)&v22);
  return SeReleaseSubjectContext((int)v19);
}
