// IopLiveDumpMarkImportantDumpData 
 
int __fastcall IopLiveDumpMarkImportantDumpData(int (__fastcall *a1)(_DWORD, unsigned int, int, int), int (__fastcall *a2)(_DWORD, unsigned int, int, int))
{
  int v2; // r4
  int v3; // r0
  int *i; // r5
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int (__fastcall *v9[10])(_DWORD, unsigned int, int, int); // [sp+0h] [bp-28h] BYREF

  v9[2] = a1;
  v9[3] = a2;
  v9[0] = (int (__fastcall *)(_DWORD, unsigned int, int, int))IoSetDumpRange;
  v9[1] = 0;
  v9[4] = (int (__fastcall *)(_DWORD, unsigned int, int, int))1;
  v2 = 0;
  v3 = ExAddPrivateDataToCrashDump(v9);
  if ( v3 < 0 )
  {
    if ( v3 == -1073741789 )
      return 0;
    v2 = v3;
  }
  for ( i = (int *)PsActiveProcessHead; i != &PsActiveProcessHead; i = (int *)*i )
  {
    v5 = MmAddRangeToCrashDump(v9, (unsigned int)(i - 45), 888);
    if ( v5 < 0 )
    {
      if ( v5 == -1073741789 )
        return 0;
      v2 = v5;
    }
  }
  v6 = MmAddPrivateDataToCrashDump(v9, 16);
  if ( v6 < 0 )
  {
    if ( v6 == -1073741789 )
      return 0;
    v2 = v6;
  }
  v7 = MmAddPrivateDataToCrashDump(v9, 1);
  if ( v7 >= 0 )
    return v2;
  if ( v7 != -1073741789 )
    return v7;
  return 0;
}
