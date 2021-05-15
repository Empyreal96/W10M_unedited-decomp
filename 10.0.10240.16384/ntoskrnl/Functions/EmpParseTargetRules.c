// EmpParseTargetRules 
 
int __fastcall EmpParseTargetRules(int a1)
{
  int v3; // r4
  int v4; // r5
  int v5; // r0
  _DWORD *v6; // r0
  __int64 v7; // r6
  int v8; // r8
  int v9; // r3
  int v10; // r7
  _DWORD *v11; // r0
  __int64 v12; // kr00_8
  _DWORD *v13; // r10
  int v14; // r10
  _BYTE *v15; // r0
  unsigned int v16; // r10
  int v17; // r8
  unsigned int v18; // r5
  int v19; // r0
  int v20; // r0
  int v21; // r8
  _BYTE *v22; // r0
  unsigned int v23; // r0
  int v24; // [sp+10h] [bp-48h] BYREF
  int v25; // [sp+14h] [bp-44h]
  int v26; // [sp+18h] [bp-40h]
  int v27; // [sp+1Ch] [bp-3Ch]
  unsigned int v28; // [sp+20h] [bp-38h]
  int v29; // [sp+24h] [bp-34h]
  char v30[48]; // [sp+28h] [bp-30h] BYREF

  v28 = EmpInfParseGetSectionLineCount(a1, (int)"TargetRuleDef");
  if ( !v28 )
    return sub_96BDDC();
  v3 = 0;
  while ( 1 )
  {
    v4 = 0;
    v5 = CmpGetKeyName(a1, (int)"TargetRuleDef", v3);
    if ( !v5 )
      goto LABEL_18;
    v4 = EmpInfParseGetGuidFromName(a1, (int)"RuleNameGuidDef", v5, v30);
    v27 = v4;
    if ( v4 < 0 )
      goto LABEL_18;
    v6 = EmpSearchRuleDatabase((unsigned int)v30);
    LODWORD(v7) = v6;
    if ( !v6 )
      goto LABEL_18;
    HIDWORD(v7) = 0;
    v8 = 0;
    v9 = v6[8] + v6[9];
    v24 = 0;
    if ( !v9 )
      goto LABEL_17;
    v10 = CmpGetSectionLineIndexValueCount(a1, (int)"TargetRuleDef", v3);
    v29 = v10;
    if ( v10 )
      break;
LABEL_18:
    if ( ++v3 >= v28 )
      return v4;
  }
  v11 = EmpSearchTargetRuleList(v7);
  v12 = *(_QWORD *)(v7 + 32);
  v13 = v11;
  if ( !v11 )
  {
    v14 = (v12 + HIDWORD(v12)) * v10;
    v25 = v14;
    v15 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v14, 1953058117);
    HIDWORD(v7) = v15;
    if ( !v15 )
      return -1073741670;
    memset(v15, 0, 4 * v14);
LABEL_12:
    v16 = v29;
    v26 = 0;
    if ( v29 )
    {
      v17 = v25;
      v18 = 0;
      do
      {
        v19 = CmpGetSectionLineIndex(a1, "TargetRuleDef", v3, v18);
        EmpParseTargetRuleStringIndexList(a1, v19, *(_DWORD *)(v7 + 32), *(_DWORD *)(v7 + 36), HIDWORD(v7), v17, &v24);
        ++v18;
      }
      while ( v18 < v16 );
      v4 = v27;
      v8 = v24;
    }
    if ( !v8 )
    {
      ExFreePoolWithTag(HIDWORD(v7));
      goto LABEL_18;
    }
LABEL_17:
    v20 = ExAllocatePoolWithTag(1, 20, 1953058117);
    *(_QWORD *)(v20 + 4) = v7;
    *(_DWORD *)(v20 + 12) = v8;
    *(_DWORD *)v20 = 0;
    *(_DWORD *)(v20 + 16) = EmpTargetRuleListHead;
    EmpTargetRuleListHead = v20 + 16;
    ++EmpNumberOfTargetRules;
    goto LABEL_18;
  }
  v21 = v11[3] + (HIDWORD(v12) + v12) * v10;
  v25 = v21;
  v22 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v21, 1953058117);
  HIDWORD(v7) = v22;
  if ( v22 )
  {
    memset(v22, 0, 4 * v21);
    memmove(SHIDWORD(v7), v13[2], 4 * v13[3]);
    v8 = v13[3];
    v23 = v13[2];
    v24 = v8;
    ExFreePoolWithTag(v23);
    goto LABEL_12;
  }
  return -1073741670;
}
