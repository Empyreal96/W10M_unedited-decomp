// DbgkpWerWriteTriageDump 
 
int __fastcall DbgkpWerWriteTriageDump(_DWORD *a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r4
  const char *v6; // r2

  v5 = WerLiveKernelOpenDumpFile_0();
  if ( v5 < 0 )
  {
    v6 = "DBGK: DbgkWerWriteTriageDump: WerLiveKernelOpenDumpFile failed, status 0x%X\n";
LABEL_8:
    DbgPrintEx(5, 0, (int)v6, v5);
    return v5;
  }
  v5 = DbgkpWerUpdateTriageDumpHeader(a1, v2, v3, v4);
  if ( v5 >= 0 )
  {
    v5 = ZwWriteFile();
    if ( v5 < 0 )
    {
      v6 = "DBGK: Triage dump write failed with Status 0x%X\n";
      goto LABEL_8;
    }
    v5 = DbgkpWerWriteSecondaryData((int)a1);
    if ( v5 < 0 )
    {
      v6 = "DBGK: Writing secondary data failed with Status 0x%X\n";
      goto LABEL_8;
    }
  }
  return v5;
}
