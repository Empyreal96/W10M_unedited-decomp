// EmpParseStrings 
 
int __fastcall EmpParseStrings(int a1)
{
  int v1; // r8
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r5
  _BYTE *v6; // r0
  unsigned int v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r8
  char *v10; // r0
  int v11; // r0
  int v12; // r7
  int v13; // r4
  char *v14; // r0
  int v16; // [sp+4h] [bp-24h]

  v1 = a1;
  v2 = 0;
  v3 = EmpInfParseGetSectionLineCount(a1, "Strings");
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( EmpStringTable )
    return sub_96BD78();
  v6 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v3, 1953058117);
  EmpStringTable = (int)v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 4 * v4);
  v7 = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      v8 = CmpGetSectionLineIndex(v1, "Strings", v7, 0);
      v9 = v8;
      if ( v8 )
      {
        v10 = strlen(v8);
        v11 = ExAllocatePoolWithTag(1, (int)(v10 + 1), 1953058117);
        v12 = EmpNumberOfStrings;
        v13 = v11;
        v16 = EmpStringTable;
        *(_DWORD *)(EmpStringTable + 4 * EmpNumberOfStrings) = v11;
        if ( !v11 )
          return -1073741670;
        v14 = strlen(v9);
        v2 = RtlStringCchCopyA(v13, (unsigned int)(v14 + 1));
        if ( v2 < 0 )
        {
          ExFreePoolWithTag(*(_DWORD *)(v16 + 4 * v12));
          v2 = 0;
        }
        else
        {
          EmpNumberOfStrings = v12 + 1;
        }
        ++v7;
      }
      if ( v7 >= v4 )
        break;
      v1 = a1;
    }
  }
  return v2;
}
