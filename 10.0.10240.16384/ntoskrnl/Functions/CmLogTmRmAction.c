// CmLogTmRmAction 
 
int __fastcall CmLogTmRmAction(int a1, int a2, int a3)
{
  int result; // r0
  int v5; // r4
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  char v10[8]; // [sp+8h] [bp-48h] BYREF
  char v11[8]; // [sp+10h] [bp-40h] BYREF
  int v12[14]; // [sp+18h] [bp-38h] BYREF

  if ( !*(_DWORD *)(a1 + 56) )
    return 0;
  v12[1] = 40;
  v12[2] = a3;
  v5 = a2 + 40;
  v12[3] = 0;
  v6 = *(_DWORD *)(a2 + 40);
  v7 = *(_DWORD *)(a2 + 44);
  v8 = *(_DWORD *)(v5 + 8);
  v9 = *(_DWORD *)(v5 + 12);
  v12[4] = v6;
  v12[5] = v7;
  v12[6] = v8;
  v12[7] = v9;
  v12[0] = HvBufferCheckSum(v12, 40);
  result = CmpTransWriteLog(a1, v12, 40, 2, v10);
  if ( result >= 0 )
    result = ClfsFlushToLsn(*(_DWORD *)(a1 + 56), v10, v11);
  return result;
}
