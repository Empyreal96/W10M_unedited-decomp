// CmpTransWriteLog 
 
int __fastcall CmpTransWriteLog(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v9; // r1
  int v10; // r6
  int v11; // r1

  v5 = 0;
  LockRMLog(a1);
  v10 = CmpDoTransWriteLogRecord((int)a1, a2, a3);
  if ( v10 >= 0 )
  {
LABEL_10:
    CmpComputeLogFillLevel(a1[13], a1 + 18, a5, a1[10]);
    goto LABEL_11;
  }
  do
  {
    if ( v5 )
    {
      if ( v5 != 1 )
        break;
    }
    else
    {
      v5 = 1;
      if ( CmpLogCheckpoint(a1, v9, 1) >= 0 )
        goto LABEL_8;
    }
    v5 = 2;
    if ( CmpAddRemoveRMLogContainer(a1) < 0 )
      break;
    CmpLogCheckpoint(a1, v11, 1);
LABEL_8:
    v10 = CmpDoTransWriteLogRecord((int)a1, a2, a3);
  }
  while ( v10 < 0 );
  if ( v10 >= 0 )
    goto LABEL_10;
LABEL_11:
  UnlockRMLog(a1);
  return v10;
}
