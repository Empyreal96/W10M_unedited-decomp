// IopCsqCancelRoutine 
 
int __fastcall IopCsqCancelRoutine(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int *v6; // r5
  int v7; // r3
  int v8; // r4
  void (__fastcall *v9)(int, _DWORD *); // r3
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  result = KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  v6 = *(int **)(a2 + 76);
  v7 = *v6;
  if ( *v6 == 1 )
  {
    v8 = v6[2];
  }
  else
  {
    if ( v7 != 2 && v7 != 3 )
      return result;
    v8 = *(_DWORD *)(a2 + 76);
  }
  v9 = *(void (__fastcall **)(int, _DWORD *))(v8 + 16);
  *(_DWORD *)(v8 + 28) = 0;
  v9(v8, v10);
  (*(void (__fastcall **)(int, int))(v8 + 8))(v8, a2);
  if ( v6 != (int *)v8 )
  {
    v6[1] = 0;
    *(_DWORD *)(a2 + 76) = 0;
  }
  (*(void (__fastcall **)(int, _DWORD))(v8 + 20))(v8, LOBYTE(v10[0]));
  return (*(int (__fastcall **)(int, int))(v8 + 24))(v8, a2);
}
