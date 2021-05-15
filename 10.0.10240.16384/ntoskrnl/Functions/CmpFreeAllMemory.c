// CmpFreeAllMemory 
 
void __fastcall __spoils<R2,R3,R12> CmpFreeAllMemory(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r4
  _DWORD *v6; // r9
  int v7; // r8
  int v8; // r3
  int v9; // r6
  int i; // r5
  _DWORD *v11; // r2
  _DWORD *j; // r1
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = 0;
  v5 = 0;
  CmpRunDownDelayDerefKCBEngine(0);
  v6 = (_DWORD *)CmpGetNextActiveHive(0);
  if ( v6 )
  {
    do
    {
      v7 = v6[462];
      v8 = 0;
      v9 = v6[461];
      v13[0] = 0;
      if ( v7 > 0 )
      {
        do
        {
          for ( i = *(_DWORD *)(v9 + 8); i; i = *(_DWORD *)(i + 4) )
          {
            if ( !v5 )
              v5 = 1;
            CmpDumpKeyBodyList(i - 12, v13, 0);
          }
          v9 += 12;
          --v7;
        }
        while ( v7 );
        v8 = v13[0];
      }
      v11 = (_DWORD *)v6[450];
      v4 += v8;
      v5 = 0;
      while ( v11 )
      {
        for ( j = (_DWORD *)v11[2]; j != v11 + 2; j = (_DWORD *)*j )
        {
          if ( j[6] && !v5 )
            v5 = 1;
        }
        v11 = (_DWORD *)*v11;
      }
      CmpDestroySecurityCache(v6);
      HvFreeHive((int)v6, 1);
      CmpDereferenceHive(v6);
      v6 = (_DWORD *)CmpGetNextActiveHive((int)v6);
    }
    while ( v6 );
    if ( v4 )
      KeBugCheckEx(81, 15, 1, v4, 0);
  }
  ExFreePoolWithTag(CmpNameCacheTable);
  if ( CmpLockTable )
    ExFreePoolWithTag(CmpLockTable);
}
