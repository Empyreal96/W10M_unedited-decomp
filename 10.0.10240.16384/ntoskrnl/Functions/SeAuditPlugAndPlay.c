// SeAuditPlugAndPlay 
 
int __fastcall SeAuditPlugAndPlay(unsigned __int16 *a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  int v8; // r1
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int v12; // r0
  int v13; // r3
  __int64 v14; // kr00_8
  int v15; // r3
  int v16; // r3
  int v18[2]; // [sp+0h] [bp-2C0h] BYREF
  int v19; // [sp+8h] [bp-2B8h]
  int v20; // [sp+Ch] [bp-2B4h]
  int v21; // [sp+10h] [bp-2B0h] BYREF
  int v22[165]; // [sp+14h] [bp-2ACh] BYREF

  v18[0] = 0;
  v18[1] = 0x80000000;
  v19 = 0;
  v20 = 0;
  memset(v22, 0, sizeof(v22));
  v21 = 5;
  v22[3] = 524425;
  v22[0] = 6416;
  SeCaptureSubjectContext(v18, v8, v9, 8);
  v10 = v18[0];
  if ( v18[0] )
    v11 = v18[0];
  else
    v11 = v19;
  v12 = **(_DWORD **)(v11 + 148);
  if ( !v18[0] )
    v10 = v19;
  v22[5] = 4;
  v13 = *(unsigned __int8 *)(v12 + 1);
  v14 = *(_QWORD *)(v10 + 24);
  v22[9] = v12;
  v22[6] = 4 * (v13 + 2);
  v22[10] = 1;
  v22[11] = 24;
  *(_QWORD *)&v22[17] = v14;
  v22[14] = (int)&SeSubsystemName;
  v22[15] = 5;
  v22[16] = 8;
  v22[20] = 13;
  v22[21] = 16;
  v22[24] = a4;
  v22[25] = 34;
  v15 = *a1;
  v22[29] = (int)a1;
  v22[34] = (int)a2;
  v22[26] = v15 + 8;
  v22[30] = 34;
  v16 = *a2;
  v22[39] = (int)a3;
  v22[31] = v16 + 8;
  v22[35] = 34;
  v22[36] = *a3 + 8;
  v22[1] = 7;
  SepAdtLogAuditRecord((int)&v21);
  return SeReleaseSubjectContext((int)v18);
}
