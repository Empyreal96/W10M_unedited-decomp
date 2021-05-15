// KiDumpParameterImages 
 
int __fastcall KiDumpParameterImages(int result, _DWORD *a2, int a3, int (__fastcall *a4)(int, char *, int))
{
  int v4; // r5
  int v6; // r6
  int v8; // r9
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r4
  const char *v14; // r3
  char v15[4]; // [sp+10h] [bp-B0h] BYREF
  int v16; // [sp+14h] [bp-ACh]
  int v17; // [sp+18h] [bp-A8h] BYREF
  char v18[160]; // [sp+20h] [bp-A0h] BYREF

  v4 = result;
  v6 = a3;
  v8 = 1;
  if ( result )
    *(_BYTE *)result = 0;
  if ( a3 )
  {
    while ( 1 )
    {
      v9 = *a2;
      v16 = 0;
      if ( KiPcToFileHeader(v9, &v17, 1, v15) )
        break;
      result = MmLocateUnloadedDriver(*a2);
      v12 = result;
      if ( result )
        goto LABEL_11;
LABEL_19:
      ++a2;
      if ( !--v6 )
        return result;
    }
    v13 = v17;
    result = MiIsAddressValid(*(_DWORD *)(v17 + 24), 0, v10, v11);
    if ( result == 1 )
    {
      result = RtlImageNtHeader(*(_DWORD *)(v13 + 24));
      if ( result )
        v16 = *(_DWORD *)(result + 8);
    }
    v12 = v13 + 44;
LABEL_11:
    if ( a4 )
      result = a4(v12, v18, 128);
    if ( v4 )
    {
      if ( v8 )
        v14 = "\r\n*";
      else
        v14 = "*";
      result = RtlStringCbPrintfA(v4, 0x80u, (int)"%s**  %12s - Address %p base at %p, DateStamp %08lx\r\n", (int)v14);
    }
    v8 = 0;
    KiBugCheckDriver = v12;
    goto LABEL_19;
  }
  return result;
}
