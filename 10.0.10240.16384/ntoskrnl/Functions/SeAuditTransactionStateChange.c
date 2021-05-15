// SeAuditTransactionStateChange 
 
int __fastcall SeAuditTransactionStateChange(int a1, _DWORD *a2, int a3)
{
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r7
  __int64 v12; // r8
  int v13; // r3
  int v14; // r3
  int v16[2]; // [sp+8h] [bp-2E0h] BYREF
  int v17; // [sp+10h] [bp-2D8h]
  int v18; // [sp+14h] [bp-2D4h]
  _WORD v19[4]; // [sp+18h] [bp-2D0h] BYREF
  int v20; // [sp+20h] [bp-2C8h] BYREF
  int v21[165]; // [sp+24h] [bp-2C4h] BYREF
  _DWORD v22[12]; // [sp+2B8h] [bp-30h] BYREF

  v16[0] = 0;
  v16[1] = 0x80000000;
  v17 = 0;
  v18 = 0;
  memset(v21, 0, sizeof(v21));
  v22[0] = 0;
  v22[1] = 0;
  v22[2] = 0;
  v22[3] = 0;
  if ( !a2 )
    a2 = v22;
  v20 = 3;
  LOWORD(v21[3]) = 116;
  v21[0] = 4985;
  if ( a3 == 6 )
    v8 = 16;
  else
    v8 = 8;
  HIWORD(v21[3]) = v8;
  SeCaptureSubjectContext(v16, v6, v7, v8);
  v9 = v16[0];
  if ( v16[0] )
    v10 = v16[0];
  else
    v10 = v17;
  v11 = **(_DWORD **)(v10 + 148);
  if ( !v16[0] )
    v9 = v17;
  v12 = *(_QWORD *)(v9 + 24);
  SeLocateProcessImageName(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  RtlInitUnicodeString((unsigned int)v19, L"?");
  v21[5] = 4;
  v13 = *(unsigned __int8 *)(v11 + 1);
  v21[9] = v11;
  *(_QWORD *)&v21[17] = v12;
  v21[6] = 4 * (v13 + 2);
  v21[10] = 1;
  v21[11] = 24;
  v21[24] = a1;
  v21[27] = a3;
  v21[14] = (int)&SeSubsystemName;
  v21[15] = 5;
  v21[16] = 8;
  v21[20] = 13;
  v21[21] = 16;
  v21[25] = 3;
  v21[26] = 4;
  v21[30] = 13;
  v21[31] = 16;
  v21[34] = (int)a2;
  v21[35] = 11;
  v21[36] = 4;
  v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v21[44] = (int)v19;
  v21[37] = *(_DWORD *)(v14 + 176);
  v21[40] = 2;
  v21[41] = v19[0] + 8;
  v21[1] = 8;
  SepAdtLogAuditRecord((int)&v20);
  return SeReleaseSubjectContext((int)v16);
}
