// RawQueryInformation 
 
int __fastcall RawQueryInformation(int a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // r2
  int v7; // r4
  int v8; // r2
  _DWORD *v9; // r1
  int v10; // r2

  v4 = *(_DWORD *)(a1 + 148);
  if ( v4 && a3[7] == v4 || ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1) )
  {
    if ( a3[3] == 14 )
    {
      if ( a3[2] >= 8u )
      {
        v8 = a3[7];
        v9 = (_DWORD *)a2[3];
        *v9 = *(_DWORD *)(v8 + 56);
        v9[1] = *(_DWORD *)(v8 + 60);
        a3[2] -= 8;
        a2[7] = 8;
        v7 = 0;
      }
      else
      {
        a2[7] = 0;
        v7 = -2147483643;
      }
    }
    else
    {
      v7 = -1073741808;
    }
    v10 = *(_DWORD *)(a1 + 148);
    if ( !v10 || a3[7] != v10 )
      ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
  }
  else
  {
    v7 = -1073741202;
  }
  a2[6] = v7;
  IofCompleteRequest((int)a2, 1);
  return v7;
}
