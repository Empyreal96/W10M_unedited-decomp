// DrvDbOpenDriverDatabaseRegKey 
 
int __fastcall DrvDbOpenDriverDatabaseRegKey(int **a1, unsigned __int16 *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v9; // r3
  int v10; // r0
  int v11; // r5
  unsigned __int16 *v13; // r4
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned __int16 *v20; // [sp+10h] [bp-20h] BYREF

  v20 = 0;
  if ( !wcsicmp((int)a2, L"*") )
  {
    v13 = (unsigned __int16 *)a1[5];
    goto LABEL_6;
  }
  v10 = DrvDbFindDatabaseNode((int)a1, a2, &v20, v9);
  v11 = v10;
  if ( v10 == -1073741772 )
    return sub_819234();
  if ( v10 >= 0 )
  {
    v13 = v20;
LABEL_6:
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(__int16 *)(v14 + 0x134) - 1;
    *(_WORD *)(v14 + 308) = v15;
    ExAcquireResourceExclusiveLite(*((_DWORD *)v13 + 18), 1, v14, v15);
    if ( (*((_DWORD *)v13 + 7) & 1) != 0 || (v11 = DrvDbLoadDatabaseNode(a1, (int *)v13), v11 >= 0) )
    {
      if ( *a1 )
        v16 = **a1;
      else
        v16 = 0;
      v11 = SysCtxRegOpenKey(v16, *((_DWORD *)v13 + 11), 0, 0, a3);
      if ( (*((_DWORD *)v13 + 7) & 1) == 0 )
        DrvDbUnloadDatabaseNode((int)a1, v13);
      if ( v11 >= 0 && a6 )
        *a6 = 2;
    }
    goto LABEL_14;
  }
  v13 = v20;
LABEL_14:
  if ( v13 )
  {
    v17 = ExReleaseResourceLite(*((_DWORD *)v13 + 18));
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
  }
  return v11;
}
