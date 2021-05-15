// SdbGetAppPatchDirEx 
 
int __fastcall SdbGetAppPatchDirEx(int a1, _WORD *a2, int a3, int a4)
{
  int v5; // r2
  const __int16 *v6; // r1
  int result; // r0
  unsigned int v8; // r4
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a4;
  v9[0] = 0;
  if ( a4 && a1 && ((v5 = *(unsigned __int16 *)(a1 + 420), v5 == 34404) || v5 == 512 || v5 == 43620) )
    v6 = L"\\AppPatch\\AppPatch64";
  else
    v6 = L"\\AppPatch";
  result = AslPathToSystemPath(v9, v6);
  v8 = v9[0];
  if ( result >= 0 && v9[0] )
    result = RtlStringCchCopyW(a2, 0x104u, v9[0]);
  else
    *a2 = 0;
  if ( v8 )
    result = ExFreePoolWithTag(v8);
  return result;
}
