// PopPluginComponentIdleState 
 
int __fastcall PopPluginComponentIdleState(int a1, int a2, int a3, _BYTE *a4)
{
  int v7; // r6
  unsigned int *v8; // r7
  int v9; // r5
  int v10; // r0

  if ( a4 )
    memset(a4, 0, 32);
  v7 = *(_DWORD *)(a1 + 32);
  v8 = (unsigned int *)(v7 + 168 * a2);
  v9 = 0;
  if ( !*(_BYTE *)(v7 + 76) || PopPluginNotifyIdleState(*(_DWORD *)(v7 + 24), v8[34], v8[68], 1) )
  {
    v10 = PopPepProcessEvent(v7, v8 + 32, 1, 6u, a3, (int)a4);
    v9 = v10;
    if ( !a4 && v10 )
      sub_54B244();
  }
  return v9;
}
