// CmpRollbackTransactionArray 
 
int __fastcall CmpRollbackTransactionArray(int a1, unsigned int a2, _BYTE *a3, unsigned int *a4)
{
  unsigned int *v4; // r4
  int v6; // r6
  int v7; // r7
  int *v8; // r9
  int v9; // r0
  int v10; // t1
  unsigned int v11; // r3
  unsigned int v15[10]; // [sp+10h] [bp-28h] BYREF

  v4 = a4;
  v6 = a1;
  v7 = 0;
  v15[0] = a2;
  if ( a3 )
    *a3 = 0;
  if ( a1 )
  {
    v8 = (int *)a2;
    do
    {
      v9 = TmRollbackEnlistment();
      if ( a3 && (v9 == -1072103403 || v9 == -1072103405 || v9 == -1072103402) )
        *a3 = 1;
      if ( v9 < 0 && v7 >= 0 && v9 != -1072103403 && v9 != -1072103405 && v9 != -1072103402 )
        v7 = v9;
      v10 = *v8++;
      ObfDereferenceObject(v10);
      --v6;
    }
    while ( v6 );
    v4 = a4;
    if ( a1 )
      ExFreePoolWithTag(v15[0]);
  }
  v11 = *v4 + 1;
  *v4 = v11;
  if ( v11 > 0xA )
  {
    v15[0] = -10000000;
    v15[1] = -1;
    KeDelayExecutionThread(0, 0, v15);
    *v4 = 0;
  }
  return v7;
}
