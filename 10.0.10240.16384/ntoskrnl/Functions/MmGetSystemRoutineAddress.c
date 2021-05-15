// MmGetSystemRoutineAddress 
 
int __fastcall MmGetSystemRoutineAddress(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]

  v6 = a3;
  v7 = a4;
  if ( RtlUnicodeStringToAnsiString(&v6, a1, 1) < 0 )
    return sub_7C3DC0();
  v4 = RtlFindExportedRoutineByName(PsNtosImageBase, v7);
  if ( !v4 )
    v4 = RtlFindExportedRoutineByName(PsHalImageBase, v7);
  RtlFreeAnsiString(&v6);
  return v4;
}
