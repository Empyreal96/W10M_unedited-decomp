// DrvDbReleaseDatabaseNodeBaseKey 
 
int __fastcall DrvDbReleaseDatabaseNodeBaseKey(int a1, int a2, int a3, int a4)
{
  int v6; // r5
  unsigned int v7; // r4
  int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r3
  int result; // r0

  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(__int16 *)(v7 + 0x134) - 1;
  *(_WORD *)(v7 + 308) = v8;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a2 + 72), 1, v8, a4);
  if ( (*(_DWORD *)(a2 + 28) & 2) == 0 )
  {
    v6 = ZwClose();
    if ( v6 >= 0 )
      v6 = DrvDbUnloadDatabaseNode(a1, a2);
  }
  v9 = ExReleaseResourceLite(*(_DWORD *)(a2 + 72));
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
  *(_WORD *)(v10 + 308) = v11;
  if ( v11 )
    result = v6;
  else
    result = sub_7E2D10(v9);
  return result;
}
