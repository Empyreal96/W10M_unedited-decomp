// IopAddBugcheckTriageWorkQueue 
 
int __fastcall IopAddBugcheckTriageWorkQueue(int a1, int a2, int a3)
{
  int v4; // r8
  int v5; // r5
  int v6; // r2
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r7
  int v10; // r1
  int v11; // r2

  v4 = 0;
  v5 = 0;
  if ( !IopIsAddressRangeValid(a1, 416, a3) )
    return -1073741823;
  IoAddTriageDumpDataBlock(a1, 416);
  v7 = *(_DWORD **)(a1 + 404);
  if ( v7 )
  {
    v8 = (_DWORD *)(a1 + 404);
    v9 = v8;
    while ( v7 != v8 && v4 < 10 )
    {
      ++v4;
      if ( !IopIsAddressRangeValid((int)v7, 8, v6) || (_DWORD *)v7[1] != v9 )
        return -1073741823;
      IopAddBugcheckTriageThread((int)(v7 - 78), v10, v11);
      v9 = v7;
      v7 = (_DWORD *)*v7;
      if ( !v7 )
        return v5;
    }
  }
  return v5;
}
