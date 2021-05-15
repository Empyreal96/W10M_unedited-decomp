// PopFxQueryCurrentComponentPerfState 
 
int __fastcall PopFxQueryCurrentComponentPerfState(int a1, int a2, int a3, int a4, _DWORD *a5, char *a6)
{
  int v6; // r5
  char v7; // r7
  int v8; // r6
  int v9; // r2
  __int64 v10; // r0
  char *v11; // r3
  char v12; // r2
  int v15; // [sp+8h] [bp-18h]

  v15 = a3;
  v6 = *(_DWORD *)(a2 + 184);
  v7 = a4;
  v8 = *(_DWORD *)(v6 + 88) + 32 * a3;
  if ( !*(_BYTE *)(v6 + 49) || !*(_DWORD *)(a1 + 36) )
  {
    *a5 = *(_DWORD *)(v8 + 8);
    a5[1] = *(_DWORD *)(v8 + 12);
    v11 = a6;
    if ( !a6 )
      return a3;
    v12 = 0;
    goto LABEL_13;
  }
  PopPluginQueryCurrentComponentPerfState();
  v9 = *(_DWORD *)(*(_DWORD *)v8 + 20);
  *a5 = v15;
  if ( v9 )
    a5[1] = a4;
  else
    a5[1] = 0;
  if ( *(_QWORD *)a5 != *(_QWORD *)(v8 + 8) )
  {
    LODWORD(v10) = KeQueryInterruptTime();
    *(_QWORD *)(v8 + 16) = v10;
    *(_BYTE *)(v8 + 24) = v7;
    *(_DWORD *)(v8 + 8) = *a5;
    *(_DWORD *)(v8 + 12) = a5[1];
    v11 = a6;
    if ( !a6 )
      return a3;
    v12 = 1;
LABEL_13:
    *v11 = v12;
    return a3;
  }
  if ( a6 )
    *a6 = 0;
  return a3;
}
