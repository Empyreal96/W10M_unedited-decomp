// PopPluginComponentActive 
 
int __fastcall PopPluginComponentActive(int a1, int a2, int a3, _BYTE *a4)
{
  int v8; // r5
  __int64 v9; // kr00_8
  int v10; // r2
  int v11; // r3
  int result; // r0
  _DWORD v13[2]; // [sp+8h] [bp-28h] BYREF
  char v14; // [sp+10h] [bp-20h]
  int v15; // [sp+14h] [bp-1Ch]
  char v16; // [sp+18h] [bp-18h]

  if ( a4 )
    memset(a4, 0, 32);
  v8 = *(_DWORD *)(a1 + 32);
  if ( *(_BYTE *)(v8 + 76) )
  {
    v9 = *(_QWORD *)(*(_DWORD *)(v8 + 24) + 36);
    v13[0] = *(_DWORD *)(*(_DWORD *)(v8 + 24) + 40);
    v13[1] = a2;
    v14 = a3;
    v15 = 0;
    v16 = 0;
    if ( (*(int (__fastcall **)(int, _DWORD *))(v9 + 64))(7, v13) )
    {
      if ( v16 )
        sub_5401DC();
    }
  }
  if ( a3 )
  {
    v10 = 6;
    v11 = 2;
  }
  else
  {
    v10 = 3;
    v11 = 6;
  }
  result = PopPepProcessEvent(v8, v8 + 168 * a2 + 128, v10, v11);
  if ( !a4 )
  {
    if ( result )
      JUMPOUT(0x5401EA);
  }
  return result;
}
