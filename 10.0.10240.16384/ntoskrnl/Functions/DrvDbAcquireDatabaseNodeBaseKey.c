// DrvDbAcquireDatabaseNodeBaseKey 
 
int __fastcall DrvDbAcquireDatabaseNodeBaseKey(int **a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v8; // r6
  unsigned int v9; // r5
  int v10; // r3
  _DWORD *v11; // r4
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  int v16; // r1
  int *v17; // r0
  int v18; // r0
  int v19; // r1
  int *v20; // r0

  *a4 = 0;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceExclusiveLite(a2[18], 1, a3, 0);
  v10 = a2[7];
  if ( (v10 & 4) != 0 )
  {
    v8 = -1073740697;
  }
  else if ( (v10 & 2) != 0 )
  {
    v11 = &a2[a3];
    if ( v11[12] )
      goto LABEL_4;
    v8 = DrvDbLoadDatabaseNode(a1, a2);
    if ( v8 >= 0 )
    {
      v19 = a2[11];
      v20 = *a1;
      if ( !a3 )
        return sub_7E2C5C(v20, v19);
      v8 = PnpCtxRegCreateKey(
             v20,
             v19,
             (unsigned __int16 *)dword_40B4A0[a3],
             (int)dword_40B4A0,
             0x2000000,
             0,
             (int)&a2[a3 + 12],
             0);
      if ( v8 >= 0 )
LABEL_4:
        *a4 = v11[12];
    }
  }
  else
  {
    v8 = DrvDbLoadDatabaseNode(a1, a2);
    if ( v8 >= 0 )
    {
      v16 = a2[11];
      v17 = *a1;
      if ( a3 )
        v18 = PnpCtxRegCreateTree(v17, v16, dword_40B4A0[a3], 0, 0x2000000, 0);
      else
        v18 = PnpCtxRegOpenKey(v17, v16, 0, 0);
      v8 = v18;
    }
  }
  v12 = ExReleaseResourceLite(a2[18]);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( v8 == -1073741275 || v8 == -1073741772 )
    v8 = -1073740947;
  return v8;
}
