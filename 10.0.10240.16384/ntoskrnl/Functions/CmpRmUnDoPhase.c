// CmpRmUnDoPhase 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpRmUnDoPhase(int a1)
{
  int v2; // r0
  int v3; // r2
  _DWORD *v4; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  int v10; // r2
  int v11; // r3
  char v13[4]; // [sp+8h] [bp-38h] BYREF
  int v14; // [sp+Ch] [bp-34h] BYREF
  int v15[12]; // [sp+10h] [bp-30h] BYREF

LABEL_1:
  v15[0] = 0;
  while ( 1 )
  {
    v2 = CmListGetNextElement(a1 + 8, v15, 0);
    v4 = (_DWORD *)v2;
    if ( !v2 )
      return 0;
    v5 = *(_DWORD *)(v2 + 64);
    if ( (v5 & 2) != 0 )
    {
      CmpTransMgrRollback(v2, &v14, v3, v5);
      CmpTransMgrFreeVolatileData((int)v4, 8, v10, v11);
      *(_QWORD *)&v8 = *(_QWORD *)v4;
      if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v9 != v4 )
        __fastfail(3u);
LABEL_14:
      *v9 = v8;
      *(_DWORD *)(v8 + 4) = v9;
      ExFreePoolWithTag((unsigned int)v4);
      goto LABEL_1;
    }
    v15[2] = 24;
    v15[3] = 0;
    v15[5] = 512;
    v15[4] = 0;
    v15[6] = 0;
    v15[7] = 0;
    if ( ZwOpenTransaction() < 0 )
    {
      if ( CmpTransMgrPrepare(a1, (int)v4, &v14, v13) < 0 || CmpTransMgrCommit(a1, (int)v4, &v14) < 0 )
      {
        v4[16] |= 2u;
        goto LABEL_1;
      }
      CmpTransMgrFreeVolatileData((int)v4, 4, v6, v7);
      *(_QWORD *)&v8 = *(_QWORD *)v4;
      if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v9 != v4 )
        __fastfail(3u);
      goto LABEL_14;
    }
    ZwClose();
  }
}
