// IopCreateArcNames 
 
int __fastcall IopCreateArcNames(int a1)
{
  int v2; // r3
  int v3; // r3
  char *v4; // r0
  char *v5; // r5
  int result; // r0
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r0
  unsigned __int16 v10[4]; // [sp-4h] [bp-98h] BYREF
  char v11[144]; // [sp+4h] [bp-90h] BYREF

  RtlStringCchPrintfA(v11, 0x80u, (int)"\\ArcName\\%s", *(_DWORD *)(a1 + 108));
  RtlInitAnsiString((unsigned int)v10, (unsigned int)v11);
  RtlAnsiStringToUnicodeString((unsigned __int16 *)&IoArcHalDeviceName, v10, 1, v2);
  RtlStringCchPrintfA(v11, 0x80u, (int)"\\ArcName\\%s", *(_DWORD *)(a1 + 104));
  RtlInitAnsiString((unsigned int)v10, (unsigned int)v11);
  RtlAnsiStringToUnicodeString((unsigned __int16 *)&IoArcBootDeviceName, v10, 1, v3);
  v4 = strlen(*(_DWORD *)(a1 + 104));
  v5 = v4;
  if ( !ViVerifierDriverAddedThunkListHead )
    return sub_96921C();
  if ( (MmVerifierData & 0x10) != 0 )
    v8 = 40;
  else
    v8 = 32;
  v9 = ExAllocatePoolWithTagPriority(1, (unsigned int)(v4 + 1), 538996553, v8);
  IoLoaderArcBootDeviceName = v9;
  if ( v9 )
    memmove(v9, *(_DWORD *)(a1 + 104), (unsigned int)(v5 + 1));
  v7 = RtlInitAnsiString((unsigned int)v10, *(_DWORD *)(a1 + 108));
  result = IopCreateArcNamesDisk(v7);
  if ( result >= 0 )
    result = IopCreateArcNamesCd(a1);
  return result;
}
