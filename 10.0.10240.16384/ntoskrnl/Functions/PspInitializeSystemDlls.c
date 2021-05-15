// PspInitializeSystemDlls 
 
int __spoils<R0,R2,R3,R12> PspInitializeSystemDlls()
{
  char ***v0; // r4
  int i; // r5
  int result; // r0
  int v3; // r8
  unsigned int v4; // r3
  int *v5; // r6
  unsigned int j; // r7
  int v7; // r2
  int *v8; // r3
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v0 = &NtdllExportInformation;
  v9[0] = 0;
  for ( i = 0; i < 2; ++i )
  {
    result = PsQuerySystemDllInfo(i);
    v3 = result;
    if ( result )
    {
      v4 = (unsigned int)v0[1];
      v5 = (int *)*v0;
      for ( j = 0; j < v4; v4 = (unsigned int)v0[1] )
      {
        result = LookupEntryPoint(*(_DWORD *)(v3 + 16), *v5, v9, v4);
        v7 = *(_DWORD *)(v3 + 12) - *(_DWORD *)(v3 + 16) + v9[0];
        v9[0] = v7;
        if ( result < 0 )
          sub_96E6A0();
        v8 = (int *)v5[1];
        ++j;
        v5 += 2;
        *v8 = v7;
      }
    }
    v0 += 2;
  }
  return result;
}
