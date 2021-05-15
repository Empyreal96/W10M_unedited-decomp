// EmpParseCallbacks 
 
int __fastcall EmpParseCallbacks(int a1)
{
  unsigned int v2; // r5
  int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r9
  int v6; // r0
  _DWORD *v7; // r6
  int v8; // r4
  char *v10; // r0
  char *v11; // r0
  unsigned int v12; // r10
  _DWORD *v13; // r7
  int v14; // r0
  _DWORD *v15; // r0
  unsigned int v16; // [sp+0h] [bp-38h]
  char v17[48]; // [sp+8h] [bp-30h] BYREF

  v2 = 0;
  v16 = EmpInfParseGetSectionLineCount(a1, "CallbackDef");
  if ( v16 )
  {
    while ( 1 )
    {
      v3 = CmpGetKeyName(a1, "CallbackDef", v2);
      if ( !v3 )
        return 0;
      v4 = CmpGetSectionLineIndexValueCount(a1, "CallbackDef", v2);
      v5 = v4;
      if ( v4 < 2 )
        JUMPOUT(0x96BB08);
      v6 = ExAllocatePoolWithTag(1, 4 * (v4 + 10), 1953058117);
      v7 = (_DWORD *)v6;
      if ( !v6 )
        return -1073741670;
      v8 = EmpInfParseGetGuidFromName(a1, "CallbackGuidDef", v3, v6);
      if ( v8 < 0 )
        JUMPOUT(0x96BB02);
      if ( EmpSearchCallbackDatabase((unsigned int)v7) )
        return sub_96BB00();
      v7[11] = v5 - 2;
      v10 = (char *)CmpGetSectionLineIndex(a1, "CallbackDef", v2, 0);
      if ( !v10 )
        return sub_96BB00();
      v7[9] = strtoul(v10, 0, 10);
      v11 = (char *)CmpGetSectionLineIndex(a1, "CallbackDef", v2, 1);
      if ( !v11 )
        return sub_96BB00();
      v12 = 2;
      v7[10] = strtoul(v11, 0, 10);
      if ( v5 > 2 )
        break;
LABEL_11:
      if ( v8 < 0 )
        goto LABEL_21;
      v7[8] = 0;
      v7[4] = 0;
      v7[5] = 0;
      v7[6] = 0;
      ++v2;
      v7[7] = EmpCallbackListHead;
      EmpCallbackListHead = (int)(v7 + 7);
      ++EmpNumberOfCallbacks;
LABEL_13:
      if ( v2 >= v16 )
        return v8;
    }
    v13 = v7 + 2;
    while ( 1 )
    {
      v14 = CmpGetSectionLineIndex(a1, "CallbackDef", v2, v12);
      v8 = EmpInfParseGetGuidFromName(a1, "EntryTypeGuidDef", v14, v17);
      if ( v8 < 0 )
        break;
      v15 = EmpSearchEntryDatabase((unsigned int)v17);
      if ( !v15 )
      {
        v8 = -1073741275;
        goto LABEL_11;
      }
      v13[10] = v15;
      ++v12;
      ++v13;
      if ( v12 >= v5 )
        goto LABEL_11;
    }
LABEL_21:
    ExFreePoolWithTag((unsigned int)v7);
    ++v2;
    v8 = 0;
    goto LABEL_13;
  }
  return 0;
}
