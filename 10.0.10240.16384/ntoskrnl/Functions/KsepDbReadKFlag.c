// KsepDbReadKFlag 
 
int __fastcall KsepDbReadKFlag(int a1, int a2, int a3)
{
  int v4; // r6
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r0
  __int64 v12; // r0

  v4 = -1073741823;
  if ( a2 )
  {
    v7 = SdbFindFirstTag(a1, a2, 24577);
    if ( v7 )
    {
      v10 = SdbGetStringTagPtr(a1, v7, v8, v9);
      if ( v10 )
      {
        *(_DWORD *)a3 = v10;
        v11 = SdbFindFirstTag(a1, a2, 20485);
        if ( v11 )
        {
          *(_DWORD *)(a3 + 4) = 11;
          v12 = SdbReadQWORDTag(a1, v11, 0, 0);
          *(_DWORD *)(a3 + 12) = a3 + 24;
          *(_DWORD *)(a3 + 8) = 8;
          *(_QWORD *)(a3 + 24) = v12;
          v4 = 0;
        }
      }
    }
  }
  return v4;
}
