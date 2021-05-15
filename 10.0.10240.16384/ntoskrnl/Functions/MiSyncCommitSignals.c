// MiSyncCommitSignals 
 
int __fastcall MiSyncCommitSignals(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r0
  int v10; // r0
  unsigned int v11; // r3
  int v12; // r0
  bool v13; // cf
  int v14; // r3
  _DWORD v15[2]; // [sp+0h] [bp-18h] BYREF
  int v16; // [sp+8h] [bp-10h]
  int v17; // [sp+Ch] [bp-Ch]

  v15[0] = a1;
  v15[1] = a2;
  v16 = a3;
  v17 = a4;
  if ( !a2 )
    return sub_54E804();
  LOBYTE(v16) = 17;
  v7 = a1[961];
  if ( v7 >= a1[804] )
  {
    v11 = a1[805];
    v12 = a1[54];
    v13 = v7 >= v11;
    v14 = *(_DWORD *)(v12 + 4);
    if ( v13 )
    {
      if ( !v14 )
        KeSetEvent(v12, 0, 0);
      if ( a1[1029] == a1[801] )
        KeSetEvent(a1[55], 0, 0);
    }
    else if ( v14 == 1 )
    {
      KeResetEvent(v12);
      KeResetEvent(a1[55]);
    }
    v10 = a1[53];
    if ( *(_DWORD *)(v10 + 4) != 1 )
      goto LABEL_7;
  }
  else
  {
    v8 = a1[53];
    if ( !*(_DWORD *)(v8 + 4) )
      KeSetEvent(v8, 0, 0);
    v9 = a1[54];
    if ( *(_DWORD *)(v9 + 4) != 1 )
      goto LABEL_7;
    KeResetEvent(v9);
    v10 = a1[55];
  }
  KeResetEvent(v10);
LABEL_7:
  if ( !a2 )
    KeReleaseInStackQueuedSpinLock((int)v15);
  return v15[0];
}
