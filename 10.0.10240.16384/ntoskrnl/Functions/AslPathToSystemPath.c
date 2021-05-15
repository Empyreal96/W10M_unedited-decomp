// AslPathToSystemPath 
 
int __fastcall AslPathToSystemPath(unsigned int *a1, int a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r3
  unsigned __int16 v10[268]; // [sp+8h] [bp-218h] BYREF

  memset(v10, 0, 520);
  *a1 = 0;
  v5 = RtlStringCchCopyW(v10, 0x104u, (int)L"\\SystemRoot");
  if ( v5 >= 0 )
  {
    v6 = RtlStringCchCatW(v10, 0x104u, a2, v4);
    if ( v6 >= 0 )
    {
      v5 = AslStringDuplicate(a1, v10, v7, v8);
      if ( v5 >= 0 )
        v5 = 0;
      else
        AslLogCallPrintf(1, (int)"AslPathToSystemPath", 952, "Failed to allocate path string [%x]", v5);
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslPathToSystemPath", 945, "Failed to cat string [%x]", v6);
      v5 = -1073741811;
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslPathToSystemPath", 928, "Failed to copy string [%x]", v5);
  }
  return v5;
}
