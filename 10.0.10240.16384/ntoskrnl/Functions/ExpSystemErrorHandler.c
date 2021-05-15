// ExpSystemErrorHandler 
 
int __fastcall ExpSystemErrorHandler(int a1, int a2, int a3, int a4, char a5)
{
  unsigned int v7; // r6
  int v8; // r9
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned int i; // r5
  int *v13; // r6
  const char *v14; // r4
  int v15; // r0
  int v16; // lr
  int v17; // r2
  int v18; // r2
  const char *v19; // r9
  unsigned int v20; // r0
  int v21; // r0
  char *v22; // r8
  char *v23; // r10
  char *v24; // r0
  char *v25; // r5
  char *j; // r0
  const char *v27; // r8
  unsigned int v28; // r0
  unsigned int v29; // r0
  int v30; // r0
  int v31; // r5
  _WORD v34[4]; // [sp+20h] [bp-180h] BYREF
  int v35; // [sp+28h] [bp-178h]
  const char *v36; // [sp+2Ch] [bp-174h] BYREF
  _WORD v37[2]; // [sp+30h] [bp-170h] BYREF
  int v38; // [sp+34h] [bp-16Ch]
  __int16 v39; // [sp+38h] [bp-168h] BYREF
  __int16 v40; // [sp+3Ah] [bp-166h]
  const char *v41; // [sp+3Ch] [bp-164h]
  int v42; // [sp+40h] [bp-160h] BYREF
  int v43; // [sp+44h] [bp-15Ch]
  int v44[6]; // [sp+48h] [bp-158h] BYREF
  _BYTE v45[32]; // [sp+60h] [bp-140h] BYREF
  _DWORD _80[75]; // [sp+80h] [bp-120h] BYREF
  int varg_r1; // [sp+1ACh] [bp+Ch]
  int varg_r2; // [sp+1B0h] [bp+10h]
  int varg_r3; // [sp+1B4h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v7 = a2;
  varg_r1 = a2;
  v8 = a1;
  _80[74] = a1;
  v36 = (const char *)a4;
  RtlCaptureContext(*(_DWORD **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xA98), a2, a3, a4);
  KiSaveProcessorControlState((_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1440), v9, v10, v11);
  if ( v7 > 5 )
  {
    v7 = 5;
    varg_r1 = 5;
  }
  v45[0] = 0;
  memset(v44, 0, 20);
  memmove((int)v44, a4, 4 * v7);
  v43 = 0;
  for ( i = 0; i < v7; ++i )
  {
    if ( ((1 << i) & a3) != 0 )
    {
      strcat_s(v45, 32, " %s");
      v35 = RtlUnicodeStringToAnsiString(&v42, *(_DWORD *)(a4 + 4 * i), 1);
      if ( v35 < 0 )
        v44[i] = (int)L"???";
      else
        v44[i] = v43;
    }
    else
    {
      strcat_s(v45, 32, " %x");
    }
  }
  strcat_s(v45, 32, "\n");
  v13 = (int *)v45;
  v14 = "Unknown Hard Error";
  v15 = PsQuerySystemDllInfo(0);
  if ( v15 )
  {
    v16 = *(_DWORD *)(v15 + 12);
    v17 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v17 == PsInitialSystemProcess )
      v16 = *(_DWORD *)(v15 + 16);
    if ( NlsMbCodePageTag )
      v18 = 1033;
    else
      v18 = 0;
    if ( RtlFindMessage(v16, 11, v18, v8, &v36) < 0 )
    {
      v13 = (int *)"Unknown Hard Error";
      goto LABEL_43;
    }
    v19 = v36;
    if ( (*((_WORD *)v36 + 1) & 1) != 0 )
    {
      RtlInitUnicodeString((unsigned int)v34, (unsigned __int16 *)v36 + 2);
      if ( NlsMbCodePageTag )
        LOWORD(v20) = RtlxUnicodeStringToOemSize(v34);
      else
        v20 = ((unsigned int)v34[0] + 2) >> 1;
      v37[0] = v20;
      v21 = ExAllocatePoolWithTag(512, (unsigned __int16)v20 + 16, 544371269);
      v22 = (char *)v21;
      if ( v21 )
      {
        v37[1] = v37[0] + 16;
        v38 = v21;
        if ( RtlUnicodeStringToAnsiString(v37, v34, 0) >= 0 )
          goto LABEL_30;
        ExFreePoolWithTag((unsigned int)v22);
      }
    }
    else
    {
      v23 = strlen((unsigned int)(v36 + 4));
      v24 = (char *)ExAllocatePoolWithTag(512, (int)(v23 + 16), 544371269);
      v22 = v24;
      if ( v24 )
      {
        strcpy_s(v24, (int)(v23 + 16), (char *)v19 + 4);
        goto LABEL_30;
      }
    }
    v13 = (int *)"Unknown Hard Error";
    v22 = "Unknown Hard Error";
LABEL_30:
    if ( v22 == "Unknown Hard Error" )
    {
LABEL_40:
      if ( i )
      {
LABEL_42:
        v8 = a1;
        goto LABEL_43;
      }
    }
    else
    {
      v25 = v22;
      for ( j = strlen((unsigned int)v22); j && *v25 >= 32; --j )
        ++v25;
      *v25 = 0;
      v13 = (int *)(v25 + 1);
      for ( i = (unsigned int)(j - 1); i; --i )
      {
        if ( !*(_BYTE *)v13 || *(char *)v13 > 32 )
          goto LABEL_40;
        v13 = (int *)((char *)v13 + 1);
      }
    }
    v13 = &dword_6A12F0;
    goto LABEL_42;
  }
LABEL_43:
  v35 = RtlStringCbPrintfA((int)_80, 0x100u, (int)"\nSTOP: %lx %s\n", v8);
  if ( v35 < 0 )
    RtlStringCbPrintfA((int)_80, 0x100u, (int)"\nHardError %lx\n", v8);
  MmLockPagableSectionByHandle(ExPageLockHandle);
  v27 = "Unknown Hard Error";
  v36 = "Unknown Hard Error";
  RtlInitAnsiString((unsigned int)v37, (unsigned int)_80);
  if ( RtlAnsiStringToUnicodeString(v34, v37, 1) >= 0 )
  {
    if ( NlsMbOemCodePageTag )
      LOWORD(v28) = RtlxUnicodeStringToOemSize(v34);
    else
      v28 = ((unsigned int)v34[0] + 2) >> 1;
    v39 = v28;
    v40 = v28;
    v14 = (const char *)ExAllocatePoolWithTag(512, (unsigned __int16)v28, 544371269);
    v41 = v14;
    if ( v14 )
      RtlUnicodeStringToOemString(&v39, v34, 0);
  }
  v35 = RtlStringCbPrintfA((int)_80, 0x100u, (int)v13, v44[0]);
  if ( v35 < 0 )
    RtlStringCbPrintfA((int)_80, 0x100u, (int)"Exception Processing Message %lx Parameters %Ix %Ix %Ix %Ix", v8);
  RtlInitAnsiString((unsigned int)v37, (unsigned int)_80);
  if ( RtlAnsiStringToUnicodeString(v34, v37, 1) >= 0 )
  {
    if ( NlsMbOemCodePageTag )
      LOWORD(v29) = RtlxUnicodeStringToOemSize(v34);
    else
      v29 = ((unsigned int)v34[0] + 2) >> 1;
    v39 = v29;
    v40 = v29;
    v27 = (const char *)ExAllocatePoolWithTag(512, (unsigned __int16)v29, 544371269);
    v41 = v27;
    if ( v27 )
      RtlUnicodeStringToOemString(&v39, v34, 0);
  }
  v30 = PsGetCurrentServerSilo();
  v31 = v30;
  if ( !v30 )
  {
    if ( a5 )
      PoShutdownBugCheck(1, 76, v8, v44, v14, v27);
    KeBugCheckEx(76, v8, (int)v44, (int)v14, (int)v27);
  }
  PsTerminateServerSilo(v30, v8);
  return PspDereferenceSiloObject(v31);
}
