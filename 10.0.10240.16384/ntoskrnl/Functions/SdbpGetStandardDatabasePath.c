// SdbpGetStandardDatabasePath 
 
signed int __fastcall SdbpGetStandardDatabasePath(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  signed int result; // r0
  unsigned int v8; // r2
  __int16 *v9; // r5
  unsigned int v10; // r4
  int v11; // [sp+10h] [bp-228h] BYREF
  unsigned __int16 v12[272]; // [sp+18h] [bp-220h] BYREF

  v12[0] = 0;
  v6 = a2 != -2145386496 && a2 != -2147221504 && a2 != -2147352576;
  SdbGetAppPatchDirEx(a1, v12, a3, v6);
  if ( a2 >= 0 )
    return 0;
  v8 = a2 & 0xF02F0000;
  if ( (a2 & 0xF02F0000) == -2147352576 )
  {
    v9 = L"msimain.sdb";
  }
  else
  {
    switch ( v8 )
    {
      case 0x80030000:
        v9 = L"sysmain.sdb";
        break;
      case 0x80040000:
        v9 = L"drvmain.sdb";
        break;
      case 0x80200000:
        v9 = L"acres.dll";
        break;
      default:
        AslLogCallPrintf(1, (int)"SdbpGetStandardDatabasePath", 983, "Cannot get the path for database type 0x%lx", a2);
        return 0;
    }
  }
  if ( a4 )
  {
    if ( RtlStringCchPrintfExW(a4, 260, 0, &v11, 0, L"%s\\%s") >= 0 )
    {
      result = 260 - v11;
      goto LABEL_21;
    }
    return 0;
  }
  result = -1;
LABEL_21:
  if ( result < 0 )
  {
    if ( a4 )
      AslLogCallPrintf(1, (int)"SdbpGetStandardDatabasePath", 1006, "Path is too long");
    v10 = wcslen(v12);
    result = wcslen((unsigned __int16 *)v9) + v10 + 2;
  }
  return result;
}
