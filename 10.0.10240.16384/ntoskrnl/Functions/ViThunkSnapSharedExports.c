// ViThunkSnapSharedExports 
 
BOOL __fastcall ViThunkSnapSharedExports(int a1, int a2, int a3, unsigned int *a4, unsigned int a5, int a6)
{
  unsigned int v6; // r5
  BOOL v7; // r6
  unsigned int i; // r8
  int v11; // r5
  int v12; // r0
  int v14; // [sp+0h] [bp-30h] BYREF
  int v15; // [sp+4h] [bp-2Ch]
  int v16; // [sp+8h] [bp-28h]
  int v17; // [sp+Ch] [bp-24h]

  v6 = 0;
  v7 = 0;
  v15 = a3;
  v16 = a2;
  v17 = a1;
  v14 = 0;
  for ( i = 0; i < a5; v14 = v6 )
  {
    if ( v6 >= *a4 || !RtlFindNextForwardRunClear((int)a4, v6, (int)&v14) )
      break;
    v11 = v14;
    v12 = ViThunkSnapSharedExportByName(v17, v16 + v14 * v15, a6);
    v7 = v7 || v12;
    v6 = v11 + 1;
    ++i;
    a6 += 8;
  }
  return v7;
}
