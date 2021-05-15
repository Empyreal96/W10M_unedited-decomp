// CmpPostApcRunDown 
 
int __fastcall CmpPostApcRunDown(int a1)
{
  int v2; // r8
  _DWORD *v3; // r4
  _DWORD *v4; // r1
  _DWORD *v5; // r1
  int v6; // r0
  int v7; // r0
  _DWORD *v8; // r1

  v2 = KfRaiseIrql(1);
  v3 = *(_DWORD **)(a1 + 40);
  v4 = (_DWORD *)v3[8];
  if ( (_DWORD *)v4[14] == v4 + 14 )
  {
    DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v4);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
        __debugbreak();
    }
  }
  **(_DWORD **)(v3[8] + 56) = 267;
  *(_DWORD *)(*(_DWORD *)(v3[8] + 56) + 4) = 0;
  v5 = (_DWORD *)v3[8];
  if ( (_DWORD *)v5[14] == v5 + 14 )
  {
    DbgPrint("IoStatusBlock pointing onto itself AsyncUser = %p\n", v5);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
        __debugbreak();
    }
  }
  v6 = *(_DWORD *)(v3[8] + 4);
  if ( v6 )
  {
    KeSetEvent(v6, 0, 0);
    ObfDereferenceObject(*(_DWORD *)(v3[8] + 4));
  }
  v7 = v3[2];
  v8 = (_DWORD *)v3[3];
  if ( *(_DWORD **)(v7 + 4) != v3 + 2 || (_DWORD *)*v8 != v3 + 2 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  CmpFreeSubordinatePost((unsigned int)v3);
  CmpFreePostBlock(v3);
  return KfLowerIrql(v2);
}
