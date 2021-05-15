// MiAweViewInserter 
 
int __fastcall MiAweViewInserter(int a1, _DWORD *a2, int a3)
{
  unsigned int v4; // r5
  int v5; // r7
  _DWORD *v6; // r4
  int v7; // r2
  unsigned int v8; // r6
  _DWORD *v9; // r3
  int v10; // r2
  int result; // r0
  __int16 v12; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(a1 + 328);
  --*(_WORD *)(v4 + 310);
  ExAcquireAutoExpandPushLockExclusive(v5 + 4, 0, a3);
  v6 = *(_DWORD **)(v5 + 16);
  v7 = 0;
  v8 = *(_DWORD *)(a2[3] + 12);
  if ( v6 )
  {
    while ( 1 )
    {
      if ( MiPhysicalViewCompareVpn(v8, (int)v6) < 0 )
      {
        v9 = (_DWORD *)*v6;
        if ( !*v6 )
        {
          v7 = 0;
          break;
        }
      }
      else
      {
        v9 = (_DWORD *)v6[1];
        if ( !v9 )
        {
          v7 = 1;
          break;
        }
      }
      v6 = v9;
    }
  }
  RtlAvlInsertNodeEx(v5 + 16, (int)v6, v7, a2);
  result = ExReleaseAutoExpandPushLockExclusive((int *)(v5 + 4), 0, v10);
  v12 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v12;
  if ( !v12 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
