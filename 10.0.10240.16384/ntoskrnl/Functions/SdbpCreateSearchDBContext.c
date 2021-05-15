// SdbpCreateSearchDBContext 
 
int __fastcall SdbpCreateSearchDBContext(_DWORD *a1, unsigned __int16 *a2)
{
  int v4; // r8
  unsigned __int16 *v5; // r5
  _BYTE *v6; // r0
  unsigned int v7; // r9
  _WORD *v8; // r0
  _WORD *v9; // r6
  int v11; // r0
  unsigned __int16 *v12; // r0
  int v13; // r3
  int v14; // r0
  _WORD *v15; // r0
  int v16; // [sp+0h] [bp-440h]
  __int16 v17; // [sp+10h] [bp-430h] BYREF
  char v18[518]; // [sp+12h] [bp-42Eh] BYREF
  __int16 v19; // [sp+218h] [bp-228h] BYREF
  char v20[518]; // [sp+21Ah] [bp-226h] BYREF

  v19 = 0;
  v4 = 0;
  memset(v20, 0, sizeof(v20));
  v17 = 0;
  v5 = 0;
  v6 = memset(v18, 0, sizeof(v18));
  if ( a2 )
  {
    v7 = wcslen(a2);
    v8 = (_WORD *)AslAlloc(v7, 2 * (v7 + 1));
    v9 = v8;
    if ( !v8 )
      return sub_7CCF84();
    v11 = AslPathSplit(a2, v8, v7 + 1, &v17, v16, &v19);
    if ( v11 < 0 )
    {
      AslLogCallPrintf(1, "SdbpCreateSearchDBContext", 185, "Unable to parse executable path for \"%ws\"", a2);
    }
    else
    {
      v12 = (unsigned __int16 *)AslAlloc(v11, 520);
      v5 = v12;
      if ( v12 )
      {
        if ( RtlStringCchCopyW(v12, 0x104u, (int)&v17) >= 0 && RtlStringCchCatW(v5, 0x104u, (int)&v19, v13) >= 0 )
          goto LABEL_8;
      }
      else
      {
        AslLogCallPrintf(1, "SdbpCreateSearchDBContext", 191, "Unable to allocate memory for full name");
      }
    }
    ExFreePoolWithTag((unsigned int)v9);
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v5);
    return v4;
  }
  v9 = (_WORD *)AslAlloc(v6, 4);
  v14 = RtlStringCchCopyW(v9, 2u, (int)L".");
  v5 = (unsigned __int16 *)AslAlloc(v14, 2);
  *v5 = 0;
  v15 = (_WORD *)AslAlloc(v5, 2);
  *v15 = 0;
  a1[3] = v15;
LABEL_8:
  a1[1] = a2;
  a1[6] = 0;
  a1[7] = 0;
  a1[4] = v9;
  a1[5] = v5;
  a1[8] = 0;
  a1[9] = 0;
  a1[11] = 0;
  return 1;
}
