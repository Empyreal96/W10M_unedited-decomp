// SeAuditProcessCreation 
 
_DWORD *__fastcall SeAuditProcessCreation(_DWORD *result, int a2)
{
  int v2; // r3
  unsigned int v3; // r7
  char *v4; // r5
  int v5; // r8
  int v6; // r9
  int v7; // r3
  int v8; // r4
  int v9; // r6
  int v10; // r4
  _DWORD *v11; // r0
  int v12; // r4
  int v13; // r3
  int v14; // r10
  unsigned int v15; // r2
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  __int64 v20; // kr00_8
  unsigned int v21; // r7
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r0
  unsigned int v27; // [sp+Ch] [bp-34Ch] BYREF
  unsigned __int16 *v28; // [sp+10h] [bp-348h]
  int v29; // [sp+14h] [bp-344h]
  int v30; // [sp+18h] [bp-340h]
  char *v31; // [sp+1Ch] [bp-33Ch]
  unsigned int v32; // [sp+20h] [bp-338h]
  int v33; // [sp+24h] [bp-334h] BYREF
  unsigned int v34; // [sp+28h] [bp-330h]
  char v35[8]; // [sp+30h] [bp-328h] BYREF
  char *v36; // [sp+38h] [bp-320h]
  int v37; // [sp+3Ch] [bp-31Ch]
  int v38; // [sp+40h] [bp-318h]
  _DWORD v39[2]; // [sp+48h] [bp-310h] BYREF
  int v40; // [sp+50h] [bp-308h]
  _QWORD v41[83]; // [sp+58h] [bp-300h] BYREF
  char v42[104]; // [sp+2F0h] [bp-68h] BYREF

  v33 = 0;
  v29 = 0;
  v30 = 0;
  v31 = v42;
  v2 = result[95];
  v3 = 0;
  v4 = 0;
  v36 = (char *)a2;
  v5 = (int)result;
  v28 = 0;
  v6 = 0;
  if ( !v2 )
    return result;
  v7 = result[44];
  v8 = result[78];
  v37 = v8;
  v38 = v7;
  v9 = SeLocateProcessImageName((int)result);
  if ( v9 < 0 )
    goto LABEL_30;
  if ( PsLookupProcessByProcessId(v8, &v33) < 0 )
  {
    v6 = 1845;
  }
  else
  {
    v10 = v33;
    if ( !*(_DWORD *)(v33 + 380) )
      return (_DWORD *)sub_7DCD98();
    SeLocateProcessImageName(v33);
    v3 = (unsigned int)v28;
    ObfDereferenceObjectWithTag(v10);
  }
  v11 = (_DWORD *)PsReferencePrimaryToken(v5);
  v12 = (int)v11;
  if ( !v11 )
  {
    v9 = -1073741700;
    goto LABEL_30;
  }
  v13 = *(_DWORD *)(v11[48] + 24);
  if ( (v13 & 4) != 0 )
  {
    v14 = 3;
  }
  else if ( (v13 & 2) != 0 )
  {
    v14 = 2;
  }
  else
  {
    v14 = 1;
  }
  v15 = v11[46];
  v34 = v11[6];
  v32 = v11[7];
  if ( v15 >= v11[31] )
    v31 = (char *)SeNullSid;
  else
    v9 = RtlCopySid(0x44u, (int)v42, *(_DWORD *)(v11[37] + 8 * v15));
  if ( v9 < 0 )
  {
    result = (_DWORD *)ObfDereferenceObject(v12);
    goto LABEL_23;
  }
  ObfDereferenceObject(v12);
  v18 = (unsigned __int8)SepRmAuditProcessCommandLine;
  __dmb(0xBu);
  if ( v18 )
  {
    v19 = (int)v36;
    if ( v36 )
    {
      v4 = v36;
      goto LABEL_16;
    }
    v9 = PsQueryProcessCommandLine(v5, 0, 0, 0, &v27);
    if ( v9 == -1073741820 )
    {
      v26 = ExAllocatePoolWithTag(1, v27, 1279485267);
      v4 = (char *)v26;
      if ( v26 )
      {
        v9 = PsQueryProcessCommandLine(v5, v26, v27, 0, &v27);
        if ( v9 >= 0 )
        {
          v19 = 1;
          v29 = 1;
          goto LABEL_16;
        }
        ExFreePoolWithTag((unsigned int)v4);
      }
    }
  }
  RtlInitUnicodeString((unsigned int)v35, (unsigned __int16 *)&dword_8CE900);
  v4 = v35;
LABEL_16:
  SeCaptureSubjectContext(v39, v16, v17, v19);
  memset(v41, 0, sizeof(v41));
  v41[0] = 0x125000000005i64;
  LODWORD(v41[2]) = 524421;
  v20 = *(_QWORD *)(v40 + 24);
  v21 = **(_DWORD **)(v40 + 148);
  if ( v20 != __PAIR64__(v32, v34) )
    v30 = 1;
  LODWORD(v41[3]) = 4;
  v22 = *(unsigned __int8 *)(v21 + 1);
  v41[9] = v20;
  HIDWORD(v41[3]) = 4 * (v22 + 2);
  v41[5] = v21 | 0x100000000i64;
  LODWORD(v41[6]) = 24;
  v41[15] = 0x1500000000i64;
  HIDWORD(v41[22]) = v4;
  HIDWORD(v41[7]) = &SeSubsystemName;
  v41[8] = 0x800000005i64;
  HIDWORD(v41[10]) = 11;
  LODWORD(v41[11]) = 4;
  HIDWORD(v41[11]) = v38;
  LODWORD(v41[13]) = 2;
  HIDWORD(v41[13]) = MEMORY[0] + 8;
  LODWORD(v41[16]) = 4;
  HIDWORD(v41[16]) = v14 + 1935;
  v41[18] = 0x40000000Bi64;
  LODWORD(v41[19]) = v37;
  HIDWORD(v41[20]) = 34;
  LODWORD(v41[21]) = *(unsigned __int16 *)v4 + 8;
  if ( v30 )
  {
    v41[23] = 0x800000023i64;
    v41[24] = __PAIR64__(v32, v34);
  }
  else
  {
    LODWORD(v41[23]) = 6;
  }
  v3 = (unsigned int)v28;
  if ( v6 )
  {
    HIDWORD(v41[25]) = 21;
    v24 = 4;
    HIDWORD(v41[26]) = v6;
  }
  else
  {
    HIDWORD(v41[25]) = 2;
    v23 = *v28;
    HIDWORD(v41[27]) = v28;
    v24 = v23 + 8;
  }
  LODWORD(v41[26]) = v24;
  LODWORD(v41[28]) = 4;
  v25 = (unsigned __int8)v31[1];
  LODWORD(v41[30]) = v31;
  HIDWORD(v41[28]) = 4 * (v25 + 2);
  LODWORD(v41[1]) = 11;
  SepAdtLogAuditRecord((int)v41);
  result = (_DWORD *)SeReleaseSubjectContext((int)v39);
LABEL_23:
  if ( v9 < 0 )
LABEL_30:
    result = (_DWORD *)SepAuditFailed(v9);
  if ( v3 )
    result = (_DWORD *)ExFreePoolWithTag(v3);
  if ( v29 )
  {
    if ( v4 )
      result = (_DWORD *)ExFreePoolWithTag((unsigned int)v4);
  }
  return result;
}
