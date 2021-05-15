// SeAuditHandleDuplication 
 
int __fastcall SeAuditHandleDuplication(int a1, int a2, int a3, int a4)
{
  int v8; // r5
  int v9; // r4
  int v10; // r4
  int v11; // r3
  unsigned int v12; // r0
  int v13; // r3
  unsigned int v14; // r0
  int v15; // r3
  int v17[2]; // [sp+0h] [bp-2C8h] BYREF
  int v18; // [sp+8h] [bp-2C0h]
  int v19[174]; // [sp+10h] [bp-2B8h] BYREF

  SeCaptureSubjectContext(v17, a2, a3, a4);
  v8 = v17[0];
  if ( v17[0] )
    v9 = v17[0];
  else
    v9 = v18;
  v10 = **(_DWORD **)(v9 + 148);
  memset(v19, 0, 664);
  v19[0] = 3;
  v19[4] = 524411;
  v19[1] = 4690;
  v19[6] = 4;
  v11 = *(unsigned __int8 *)(v10 + 1);
  v19[10] = v10;
  v19[7] = 4 * (v11 + 2);
  v19[11] = 1;
  v19[12] = 24;
  v19[15] = (int)&SeSubsystemName;
  v19[16] = 5;
  v19[17] = 8;
  if ( !v17[0] )
    v8 = v18;
  v19[18] = *(_DWORD *)(v8 + 24);
  v19[19] = *(_DWORD *)(v8 + 28);
  v19[21] = 11;
  v19[22] = 4;
  v12 = ObNormalizeHandleValue(a1);
  v19[26] = 11;
  v19[27] = 4;
  v13 = *(_DWORD *)(a3 + 176);
  v19[23] = v12;
  v19[28] = v13;
  v19[31] = 11;
  v19[32] = 4;
  v14 = ObNormalizeHandleValue(a2);
  v19[36] = 11;
  v19[37] = 4;
  v15 = *(_DWORD *)(a4 + 176);
  v19[33] = v14;
  v19[38] = v15;
  v19[2] = 7;
  SepAdtLogAuditRecord((int)v19);
  return SeReleaseSubjectContext((int)v17);
}
