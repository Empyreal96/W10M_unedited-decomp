// sub_52A734 
 
void sub_52A734()
{
  unsigned __int16 *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r8
  int v4; // r5
  __int64 v5; // kr00_8
  int v6; // r0
  __int16 v7; // r3
  int v8; // r3
  int v9; // r2
  int v10; // r4
  __int64 v11[88]; // [sp+10h] [bp-2C0h] BYREF

  if ( v2 )
    v4 = v2;
  else
    v4 = SeLocalSystemSid;
  memset(v11, 0, 664);
  v5 = *(_QWORD *)v1;
  v6 = 2;
  LOWORD(v11[2]) = v3;
  v11[0] = v5;
  v7 = *(_WORD *)(v1 + 18);
  v11[5] = (unsigned int)v4 | 0x100000000i64;
  LODWORD(v11[1]) = 2;
  WORD1(v11[2]) = v7;
  LODWORD(v11[3]) = 4;
  HIDWORD(v11[3]) = 4 * (*(unsigned __int8 *)(v4 + 1) + 2);
  LODWORD(v11[6]) = 24;
  HIDWORD(v11[7]) = &SeSubsystemName;
  if ( v3 == 122 )
  {
    HIDWORD(v11[2]) |= 6u;
    LODWORD(v11[8]) = 1;
    v8 = *v0;
    LODWORD(v11[10]) = v0;
    v6 = 3;
    LODWORD(v11[1]) = 3;
    HIDWORD(v11[8]) = v8 + 8;
  }
  else
  {
    v9 = HIDWORD(v11[2]) | 8;
    HIDWORD(v11[2]) |= 8u;
    if ( HIDWORD(v5) < 0x5FF )
      HIDWORD(v11[2]) = v9 | 2;
  }
  v10 = *(_DWORD *)(v1 + 8);
  memmove((int)&v11[3] + 20 * v6, v1 + 24, 20 * v10);
  LODWORD(v11[1]) += v10;
  SepAdtLogAuditRecord((int)v11);
  JUMPOUT(0x46A2AE);
}
