// IopInitializeBootLogging 
 
_BYTE *__fastcall IopInitializeBootLogging(_BYTE *result, int a2)
{
  _BYTE *v3; // r6
  int v4; // r3
  _BYTE *v5; // r4
  int v6; // r2
  int v7; // r6
  char *v8; // r0
  _DWORD *v9; // r1
  unsigned int v10; // r3
  unsigned int v11; // r3
  int v12; // r2
  unsigned int v13; // r3
  unsigned __int16 v14; // r0
  void *v15; // r0
  unsigned int v16; // r3
  int *i; // r4
  int v18[2]; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 v19; // [sp+10h] [bp-20h] BYREF
  __int16 v20; // [sp+12h] [bp-1Eh]
  int v21; // [sp+14h] [bp-1Ch]

  v3 = result;
  if ( !off_920070 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      v4 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
      result = (_BYTE *)ExAllocatePoolWithTagPriority(512, 0x60u, 538996553, v4);
    }
    else
    {
      result = (_BYTE *)ExAllocatePoolWithTag(512, 96, 538996553);
    }
    v5 = result;
    off_920070 = result;
    if ( result )
    {
      memset(result, 0, 96);
      ExInitializeResourceLite((int)(v5 + 32));
      ExAcquireResourceExclusiveLite((int)off_920070 + 32, 1, v6, (int)off_920070);
      v7 = *((_DWORD *)v3 + 4);
      if ( RtlFindMessage(*(_DWORD *)(v7 + 24), 11, 0, 0xB5u, v18) >= 0 )
      {
        v21 = v18[0] + 4;
        v8 = strlen(v18[0] + 4);
        v19 = (unsigned __int16)v8;
        v20 = (_WORD)v8 + 1;
        RtlAnsiStringToUnicodeString((unsigned __int16 *)off_920070, &v19, 1, (int)(v8 + 1));
        v9 = off_920070;
        v10 = *(unsigned __int16 *)off_920070;
        if ( v10 > 4 )
        {
          v11 = (unsigned __int16)(v10 - 4);
          *(_WORD *)off_920070 = v11;
          *(_WORD *)(v9[1] + 2 * (v11 >> 1)) = 0;
        }
      }
      if ( RtlFindMessage(*(_DWORD *)(v7 + 24), 11, 0, 0xB6u, v18) < 0 )
      {
        v15 = off_920070;
      }
      else
      {
        v21 = v18[0] + 4;
        v14 = (unsigned __int16)strlen(v18[0] + 4);
        v20 = v14 + 1;
        v19 = v14;
        RtlAnsiStringToUnicodeString((unsigned __int16 *)off_920070 + 4, &v19, 1, (int)off_920070);
        v15 = off_920070;
        v13 = *((unsigned __int16 *)off_920070 + 4);
        if ( v13 > 4 )
        {
          v16 = (unsigned __int16)(v13 - 4);
          *((_WORD *)off_920070 + 4) = v16;
          v12 = v16 >> 1;
          v13 = *((_DWORD *)v15 + 3);
          *(_WORD *)(v13 + 2 * v12) = 0;
        }
      }
      RtlCreateUnicodeStringFromAsciiz((unsigned __int16 *)v15 + 12, a2 + 1, v12, v13);
      ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
      for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
        IopBootLog();
      ExReleaseResourceLite((int)&PsLoadedModuleResource);
      result = (_BYTE *)ExReleaseResourceLite((int)off_920070 + 32);
    }
  }
  return result;
}
