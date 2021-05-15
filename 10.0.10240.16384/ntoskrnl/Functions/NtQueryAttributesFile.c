// NtQueryAttributesFile 
 
int __fastcall NtQueryAttributesFile(int a1, unsigned int a2)
{
  unsigned __int64 *v4; // r3
  unsigned __int64 v5; // kr00_8
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int v8; // r4
  char v10; // [sp+10h] [bp-178h]
  int v11; // [sp+18h] [bp-170h] BYREF
  int v12[28]; // [sp+20h] [bp-168h] BYREF
  int v13; // [sp+90h] [bp-F8h] BYREF
  int v14; // [sp+C8h] [bp-C0h] BYREF

  v11 = a2;
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v10 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 36) = *(_BYTE *)(a2 + 36);
  }
  memset(v12, 0, sizeof(v12));
  v12[0] = 7340040;
  HIWORD(v12[11]) = 7;
  v12[15] = 1;
  v12[10] = 2113536;
  v12[16] = a2;
  v12[17] = (int)&v13;
  BYTE1(v12[20]) = 1;
  v12[21] = (int)&v14;
  v12[6] = a1;
  v12[22] = 32;
  if ( IoCountOperations == 1 )
  {
    v4 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
    do
      v5 = __ldrexd(v4);
    while ( __strexd(v5 + 1, v4) );
    v6 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
  }
  v8 = ObOpenObjectByName(a1, (int)IoFileObjectType, v10, 0, 128, (int)v12, &v11);
  if ( v12[25] && FsRtlpCleanupEcps() )
    v12[25] = 0;
  if ( v12[4] == -1096154543 )
    return v12[2];
  if ( v8 >= 0 )
  {
    ObCloseHandle(v11);
    v8 = -1073741788;
  }
  return v8;
}
