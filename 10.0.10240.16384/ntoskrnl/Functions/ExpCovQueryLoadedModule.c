// ExpCovQueryLoadedModule 
 
int __fastcall ExpCovQueryLoadedModule(int a1, int a2, unsigned int a3, int a4, unsigned int *a5, _DWORD *a6)
{
  int v7; // r6
  int v10; // r4
  unsigned int v11; // r7
  unsigned int v12; // r8
  __int64 v13; // r2
  const char *v14; // r2
  unsigned int v15; // r1
  int v16; // r1
  int v17; // r0
  int v20; // [sp+8h] [bp-28h] BYREF
  int v21; // [sp+Ch] [bp-24h]

  v7 = *(_DWORD *)(a1 + 72);
  v21 = 0;
  v20 = 0;
  v10 = ExpCovReadFriendlyName(v7, a1 + 36, &v20);
  if ( v10 >= 0 )
  {
    if ( a2 )
      v11 = *(_DWORD *)(a1 + 68);
    else
      v11 = *(_DWORD *)(a1 + 68) - *(_DWORD *)(v7 + 28);
    v12 = (unsigned __int16)v20;
    if ( v11 >= 0xFFFFFFE8 || (LODWORD(v13) = (unsigned __int16)v20 + v11 + 24, (unsigned int)v13 < 0x18) )
      LODWORD(v13) = -1;
    *a6 = v13;
    if ( (_DWORD)v13 == -1 )
    {
      v14 = "COV: Overflow when calculating RequiredLengthForCurrentModule for %wZ\n";
LABEL_10:
      DbgPrintEx(126, 2, (int)v14, a1 + 36);
      v10 = -1073741675;
      goto LABEL_17;
    }
    v15 = *a5 + v13;
    if ( v15 < *a5 )
    {
      v14 = "COV: Overflow when calculating total required length for %wZ\n";
      goto LABEL_10;
    }
    *a5 = v15;
    if ( a3 >= v15 )
    {
      HIDWORD(v13) = 1;
      *(_QWORD *)a4 = v13;
      *(_DWORD *)(a4 + 16) = v11;
      memmove(a4 + 20, *(_DWORD *)(a1 + 72), v11);
      v16 = v21;
      *(_WORD *)(a4 + 10) = HIWORD(v20);
      v17 = v11 + a4 + 24;
      *(_DWORD *)(a4 + 12) = v17;
      *(_WORD *)(a4 + 8) = v12;
      memmove(v17, v16, v12);
      if ( a2 )
        memset((_BYTE *)(*(_DWORD *)(v7 + 32) + v7), 0, *(_DWORD *)(v7 + 28));
    }
    else
    {
      v10 = -1073741820;
    }
  }
LABEL_17:
  if ( v21 )
    RtlFreeAnsiString(&v20);
  return v10;
}
