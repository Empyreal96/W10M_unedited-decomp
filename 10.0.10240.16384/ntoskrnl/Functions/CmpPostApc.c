// CmpPostApc 
 
int __fastcall CmpPostApc(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // r8
  _DWORD *v6; // r4
  _DWORD *v7; // r1
  _DWORD *v8; // r1
  _DWORD *v9; // r1
  int v10; // r0
  int v11; // r5
  _DWORD *v12; // r1

  v5 = a4;
  v6 = *(_DWORD **)a5;
  v7 = *(_DWORD **)(*(_DWORD *)a5 + 32);
  if ( (_DWORD *)v7[14] == v7 + 14 )
  {
    DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v7);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
        __debugbreak();
    }
  }
  **(_DWORD **)(v6[8] + 56) = *v5;
  *(_DWORD *)(*(_DWORD *)(v6[8] + 56) + 4) = 0;
  v8 = (_DWORD *)v6[8];
  if ( (_DWORD *)v8[14] == v8 + 14 )
  {
    DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v8);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
        __debugbreak();
    }
  }
  *v5 = *(_DWORD *)(v6[8] + 56);
  v9 = (_DWORD *)v6[8];
  if ( (_DWORD *)v9[14] == v9 + 14 )
  {
    DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v9);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
        __debugbreak();
    }
  }
  v10 = *(_DWORD *)(v6[8] + 4);
  if ( v10 )
  {
    KeSetEvent(v10, 0, 0);
    ObfDereferenceObject(*(_DWORD *)(v6[8] + 4));
  }
  v11 = v6[2];
  v12 = (_DWORD *)v6[3];
  if ( *(_DWORD **)(v11 + 4) != v6 + 2 || (_DWORD *)*v12 != v6 + 2 )
    __fastfail(3u);
  *v12 = v11;
  *(_DWORD *)(v11 + 4) = v12;
  CmpFreeSubordinatePost(v6);
  return CmpFreePostBlock(v6);
}
