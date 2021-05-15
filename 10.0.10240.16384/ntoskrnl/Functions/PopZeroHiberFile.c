// PopZeroHiberFile 
 
int __fastcall PopZeroHiberFile(int a1, int a2)
{
  unsigned int v3; // r3
  unsigned int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r4
  int v7; // r0
  unsigned __int64 v8; // r4
  unsigned int v9; // kr00_4
  unsigned __int64 v11; // [sp+8h] [bp-48h] BYREF
  unsigned __int64 v12; // [sp+10h] [bp-40h] BYREF
  __int64 v13; // [sp+20h] [bp-30h]

  PopDiagTraceZeroHiberFile();
  if ( ZwQueryInformationFile() >= 0 )
  {
    v3 = 0;
    v4 = 0;
    v6 = HIDWORD(v13);
    v5 = v13;
    v11 = 0i64;
    do
    {
      v12 = __PAIR64__(v6, v5) - __PAIR64__(v4, v3);
      v7 = MmZeroPageWrite(a2, (int)&v11, (int)&v12, 0x10000);
      if ( v7 >= 0 )
        break;
      v8 = v11 & 0xFFFFFFFFFFFF0000ui64;
      if ( (PoDebug & 0x81) != 0 )
        DbgPrint(
          "PopZeroHiberFile: Write of size %lx at offset %I64x failed %08lx\n",
          0x10000,
          v11 & 0xFFFFFFFFFFFF0000ui64,
          v7);
      v9 = v8;
      v6 = HIDWORD(v13);
      v5 = v13;
      v4 = (__PAIR64__(HIDWORD(v8), v9) + 0x10000) >> 32;
      v3 = v9 + 0x10000;
      v11 = __PAIR64__(HIDWORD(v8), v9) + 0x10000;
    }
    while ( (__int64)(__PAIR64__(HIDWORD(v8), v9) + 0x10000) < v13 );
  }
  return PopDiagTraceZeroHiberFileEnd();
}
