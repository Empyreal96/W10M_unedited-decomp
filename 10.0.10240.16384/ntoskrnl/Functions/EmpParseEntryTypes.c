// EmpParseEntryTypes 
 
int __fastcall EmpParseEntryTypes(int a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r7
  unsigned int v4; // r0
  int v5; // r3
  _BYTE *v6; // r0
  _DWORD *v7; // r6
  int v8; // r4
  unsigned __int16 v10[2]; // [sp+0h] [bp-80h] BYREF
  char *v11; // [sp+4h] [bp-7Ch]
  unsigned __int16 v12[4]; // [sp+8h] [bp-78h] BYREF
  char v13; // [sp+10h] [bp-70h] BYREF

  v11 = &v13;
  v10[1] = 78;
  v2 = 0;
  v3 = EmpInfParseGetSectionLineCount(a1, "EntryTypeGuidDef");
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = CmpGetSectionLineIndex(a1, "EntryTypeGuidDef", v2, 0);
      if ( !v4 )
        break;
      RtlInitAnsiString((unsigned int)v12, v4);
      if ( RtlAnsiStringToUnicodeString(v10, v12, 0, v5) < 0 )
        JUMPOUT(0x96BAF4);
      v6 = (_BYTE *)ExAllocatePoolWithTag(1, 48, 1953058117);
      v7 = v6;
      if ( !v6 )
        return -1073741670;
      v8 = RtlGUIDFromString(v10, v6);
      if ( v8 < 0 )
        JUMPOUT(0x96BAEE);
      if ( EmpSearchEntryDatabase((unsigned int)v7) )
        return sub_96BAEC();
      v7[7] = v7 + 7;
      v7[8] = v7 + 7;
      v7[11] = 0;
      v7[9] = v7 + 9;
      v7[10] = v7 + 9;
      v7[4] = 0;
      v7[6] = v7 + 7;
      ++v2;
      v7[5] = EmpEntryListHead;
      EmpEntryListHead = (int)(v7 + 5);
      ++EmpNumberOfEntryTypes;
      if ( v2 >= v3 )
        return v8;
    }
  }
  return 0;
}
