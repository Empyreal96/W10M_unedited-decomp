// CmpLockIXLockIntent 
 
BOOL __fastcall CmpLockIXLockIntent(int *a1, int a2)
{
  int v3; // r6
  int v5; // r3
  int v7; // r6
  int *v8; // r0
  int v9; // r7
  int v10; // r9
  int *v11; // r8
  int v12; // t1
  int v13; // r0
  int v14; // r6
  int v15; // r3

  v3 = *a1;
  if ( !*a1 )
  {
    v5 = 1;
    a1[1] = a2;
LABEL_17:
    *a1 = v5;
    *(_DWORD *)(a2 + 8) = a1;
    return 1;
  }
  if ( v3 >= 0 )
  {
    if ( v3 == 1 )
    {
      v7 = a1[1];
      if ( CmEqualTrans(*(_DWORD *)(v7 + 28), *(_DWORD *)(a2 + 28)) )
        return 1;
      v8 = (int *)ExAllocatePoolWithTag(1, 8, 2018069827);
      if ( !v8 )
        return 0;
      a1[1] = (int)v8;
      *v8 = v7;
      *(_DWORD *)(a1[1] + 4) = a2;
    }
    else
    {
      v9 = 0;
      if ( v3 )
      {
        v10 = *(_DWORD *)(a2 + 28);
        v11 = (int *)a1[1];
        do
        {
          v12 = *v11++;
          if ( CmEqualTrans(*(_DWORD *)(v12 + 28), v10) )
            return 1;
        }
        while ( ++v9 < (unsigned int)v3 );
      }
      v13 = ExAllocatePoolWithTag(1, 4 * (v3 + 1), 2018069827);
      v14 = v13;
      if ( !v13 )
        return 0;
      memmove(v13, a1[1], 4 * *a1);
      ExFreePoolWithTag(a1[1]);
      v15 = *a1;
      a1[1] = v14;
      *(_DWORD *)(v14 + 4 * v15) = a2;
    }
    v5 = *a1 + 1;
    goto LABEL_17;
  }
  return CmEqualTrans(*(_DWORD *)(a1[1] + 28), *(_DWORD *)(a2 + 28)) != 0;
}
