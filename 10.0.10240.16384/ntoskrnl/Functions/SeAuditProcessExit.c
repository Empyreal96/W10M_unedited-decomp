// SeAuditProcessExit 
 
int __fastcall SeAuditProcessExit(int a1, int a2)
{
  int v4; // r6
  __int64 v5; // r4
  unsigned int v6; // r2
  int v7; // r3
  _QWORD v9[87]; // [sp+8h] [bp-2B8h] BYREF

  memset(v9, 0, 664);
  if ( SeLocateProcessImageName(a1) < 0 )
    return SepAuditFailed();
  v4 = PsReferencePrimaryToken(a1);
  v5 = *(_QWORD *)(v4 + 24);
  v6 = **(_DWORD **)(v4 + 148);
  v9[0] = 0x125100000005i64;
  LODWORD(v9[2]) = 524422;
  LODWORD(v9[3]) = 4;
  v7 = *(unsigned __int8 *)(v6 + 1);
  v9[5] = v6 | 0x100000000i64;
  v9[9] = v5;
  HIDWORD(v9[3]) = 4 * (v7 + 2);
  LODWORD(v9[6]) = 24;
  HIDWORD(v9[11]) = a2;
  HIDWORD(v9[17]) = 0;
  HIDWORD(v9[7]) = &SeSubsystemName;
  v9[8] = 0x800000005i64;
  HIDWORD(v9[10]) = 10;
  LODWORD(v9[11]) = 4;
  v9[13] = 0x40000000Bi64;
  LODWORD(v9[14]) = *(_DWORD *)(a1 + 176);
  HIDWORD(v9[15]) = 2;
  LODWORD(v9[16]) = MEMORY[0] + 8;
  LODWORD(v9[1]) = 6;
  SepAdtLogAuditRecord((int)v9);
  return ObfDereferenceObject(v4);
}
