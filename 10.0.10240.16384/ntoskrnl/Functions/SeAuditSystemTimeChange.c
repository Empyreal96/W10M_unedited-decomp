// SeAuditSystemTimeChange 
 
int __fastcall SeAuditSystemTimeChange(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r3
  int v7; // r7
  int v8; // r8
  int v9; // r3
  int v10; // r3
  int v12[2]; // [sp+8h] [bp-2C0h] BYREF
  int v13; // [sp+10h] [bp-2B8h]
  int var2B0[173]; // [sp+18h] [bp-2B0h] BYREF
  int varg_r0; // [sp+2D0h] [bp+8h]
  int varg_r1; // [sp+2D4h] [bp+Ch]
  int varg_r2; // [sp+2D8h] [bp+10h]
  int varg_r3; // [sp+2DCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  SeCaptureSubjectContext(v12, a2, a3, 0);
  v4 = v12[0];
  v5 = v13;
  v6 = v12[0];
  if ( !v12[0] )
    v6 = v13;
  v7 = **(_DWORD **)(v6 + 148);
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  memset(var2B0, 0, 664);
  if ( SeLocateProcessImageName(v8) < 0 )
  {
    SepAuditFailed();
  }
  else
  {
    var2B0[0] = 1;
    var2B0[1] = 4616;
    var2B0[4] = 524388;
    var2B0[6] = 4;
    v9 = *(unsigned __int8 *)(v7 + 1);
    var2B0[10] = v7;
    var2B0[7] = 4 * (v9 + 2);
    var2B0[11] = 1;
    var2B0[12] = 24;
    var2B0[15] = (int)&SeSubsystemName;
    var2B0[16] = 5;
    var2B0[17] = 8;
    if ( v4 )
    {
      var2B0[18] = *(_DWORD *)(v4 + 24);
      v10 = *(_DWORD *)(v4 + 28);
    }
    else
    {
      var2B0[18] = *(_DWORD *)(v5 + 24);
      v10 = *(_DWORD *)(v5 + 28);
    }
    var2B0[19] = v10;
    var2B0[21] = 12;
    var2B0[22] = 8;
    var2B0[40] = 0;
    var2B0[23] = varg_r0;
    var2B0[24] = varg_r1;
    var2B0[26] = 12;
    var2B0[27] = 8;
    var2B0[28] = varg_r2;
    var2B0[29] = varg_r3;
    var2B0[31] = 11;
    var2B0[32] = 4;
    var2B0[33] = *(_DWORD *)(v8 + 176);
    var2B0[36] = 2;
    var2B0[37] = MEMORY[0] + 8;
    var2B0[2] = 7;
    SepAdtLogAuditRecord((int)var2B0);
  }
  return SeReleaseSubjectContext((int)v12);
}
