// EmpParseRules 
 
int __fastcall EmpParseRules(int a1)
{
  int v1; // r8
  unsigned int v2; // r6
  int v3; // r10
  int v4; // r0
  _DWORD *v5; // r4
  int v6; // r5
  unsigned int v7; // r0
  char *v8; // r0
  char *v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r9
  _BYTE *v13; // r0
  unsigned int v14; // r7
  int v15; // r0
  _DWORD *v16; // r0
  _DWORD *v17; // r8
  _DWORD *v18; // r0
  unsigned int v19; // r7
  unsigned int i; // r5
  int v21; // r2
  _DWORD *v22; // r0
  unsigned int v23; // r0
  unsigned int j; // r5
  int v25; // r2
  _DWORD *v26; // r0
  unsigned int v27; // r0
  int v28; // [sp+0h] [bp-38h]
  unsigned int v29; // [sp+4h] [bp-34h]
  char v30[48]; // [sp+8h] [bp-30h] BYREF

  v28 = a1;
  v1 = a1;
  v2 = 0;
  v29 = EmpInfParseGetSectionLineCount(a1, "RuleDef");
  if ( v29 )
  {
    while ( 1 )
    {
      v3 = CmpGetKeyName(v1, "RuleDef", v2);
      if ( !v3 )
        return 0;
      v4 = ExAllocatePoolWithTag(1, 68, 1953058117);
      v5 = (_DWORD *)v4;
      if ( !v4 )
        return -1073741670;
      *(_DWORD *)(v4 + 16) = 1;
      *(_BYTE *)(v4 + 20) = 0;
      *(_DWORD *)(v4 + 44) = 0;
      *(_DWORD *)(v4 + 48) = 0;
      *(_DWORD *)(v4 + 52) = 0;
      *(_DWORD *)(v4 + 28) = 0;
      *(_DWORD *)(v4 + 56) = v4 + 56;
      *(_DWORD *)(v4 + 60) = v4 + 56;
      *(_DWORD *)(v4 + 40) = 0;
      *(_DWORD *)(v4 + 32) = 0;
      v6 = EmpInfParseGetGuidFromName(v1, "RuleNameGuidDef", v3, v4);
      v7 = (unsigned int)v5;
      if ( v6 < 0 )
        goto LABEL_26;
      if ( EmpSearchRuleDatabase((unsigned int)v5) )
        break;
      v8 = (char *)CmpGetSectionLineIndex(v1, "RuleDef", v2, 0);
      if ( !v8 )
        return sub_96BCA8();
      v5[8] = strtoul(v8, 0, 10);
      v10 = (char *)CmpGetSectionLineIndex(v1, "RuleDef", v2, 1);
      if ( !v10 )
        return sub_96BCA8();
      v5[9] = strtoul(v10, 0, 10);
      v11 = CmpGetSectionLineIndexValueCount(v1, "RuleDef", v2);
      v12 = v11;
      if ( v11 < 2 )
        goto LABEL_27;
      v5[10] = v11 - 2;
      if ( v11 != 2 )
      {
        v13 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * (v11 - 2), 1953058117);
        v5[11] = v13;
        if ( !v13 )
        {
          ExFreePoolWithTag((unsigned int)v5);
          return -1073741670;
        }
        memset(v13, 0, 4 * v5[10]);
        v14 = 2;
        if ( v12 > 2 )
        {
          while ( 1 )
          {
            v15 = CmpGetSectionLineIndex(v1, "RuleDef", v2, v14);
            v6 = EmpInfParseGetGuidFromName(v1, "EntryTypeGuidDef", v15, v30);
            if ( v6 < 0 )
              break;
            v16 = EmpSearchEntryDatabase((unsigned int)v30);
            v17 = v16;
            if ( !v16 )
              break;
            *(_DWORD *)(v5[11] + 4 * v14 - 8) = v16;
            if ( !EmpInfParseSearchDependencyList(v16 + 11, v5) )
            {
              v18 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1953058117);
              if ( !v18 )
              {
                v6 = -1073741670;
                v1 = v28;
                goto LABEL_23;
              }
              *v18 = v5;
              v18[1] = v17[11];
              v17[11] = v18 + 1;
            }
            ++v14;
            v1 = v28;
            if ( v14 >= v12 )
              goto LABEL_23;
          }
LABEL_29:
          v19 = v14 - 2;
          for ( i = 0; i < v19; ++i )
          {
            v21 = *(_DWORD *)(v5[11] + 4 * i);
            v22 = *(_DWORD **)(v21 + 44);
            if ( (_DWORD *)*(v22 - 1) == v5 )
            {
              if ( v22 )
                *(_DWORD *)(v21 + 44) = *v22;
              ExFreePoolWithTag((unsigned int)(v22 - 1));
            }
          }
          v23 = v5[11];
          if ( v23 )
            ExFreePoolWithTag(v23);
          ExFreePoolWithTag((unsigned int)v5);
          v1 = v28;
          ++v2;
          v6 = 0;
          goto LABEL_13;
        }
LABEL_23:
        if ( v6 < 0 )
          goto LABEL_29;
      }
      v6 = EmpParseRuleExpression(v1, v3, v5);
      if ( v6 < 0 )
      {
        for ( j = 0; j < v5[10]; ++j )
        {
          v25 = *(_DWORD *)(v5[11] + 4 * j);
          v26 = *(_DWORD **)(v25 + 44);
          if ( (_DWORD *)*(v26 - 1) == v5 )
          {
            if ( v26 )
              *(_DWORD *)(v25 + 44) = *v26;
            ExFreePoolWithTag((unsigned int)(v26 - 1));
          }
        }
        v27 = v5[11];
        if ( v27 )
          ExFreePoolWithTag(v27);
LABEL_27:
        ExFreePoolWithTag((unsigned int)v5);
        ++v2;
        v6 = 0;
        goto LABEL_13;
      }
      ++v2;
      v5[6] = EmpRuleListHead;
      EmpRuleListHead = (int)(v5 + 6);
      ++EmpNumberOfRules;
LABEL_13:
      if ( v2 >= v29 )
        return v6;
    }
    v7 = (unsigned int)v5;
LABEL_26:
    ExFreePoolWithTag(v7);
    ++v2;
    goto LABEL_13;
  }
  return 0;
}
