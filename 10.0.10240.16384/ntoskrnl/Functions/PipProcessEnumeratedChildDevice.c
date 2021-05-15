// PipProcessEnumeratedChildDevice 
 
_DWORD *__fastcall PipProcessEnumeratedChildDevice(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v7; // r5
  int v9; // r0
  int v10; // r5
  int v11; // r7
  _DWORD *v12; // [sp+0h] [bp-20h]
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v12 = a1;
  v13[0] = a3;
  v13[1] = a4;
  v4 = *(_DWORD *)(a2 + 176);
  if ( (*(_DWORD *)(v4 + 16) & 2) != 0 )
    sub_7CB3F8();
  v7 = *(_DWORD *)(v4 + 20);
  v13[0] = v7;
  if ( v7 )
  {
    PipSetDevNodeFlags(v7, 16);
    if ( *(_DWORD *)(v7 + 372) == 4 )
      PpProfileCancelTransitioningDock(v7);
    goto LABEL_6;
  }
  v9 = PipAllocateDeviceNode(a2, v13);
  v10 = v13[0];
  v11 = v9;
  if ( !v13[0] )
  {
LABEL_6:
    ObfDereferenceObject(a2);
    return v12;
  }
  PipSetDevNodeFlags(v13[0], 16);
  *(_DWORD *)(a2 + 28) |= 0x1000u;
  PpDevNodeInsertIntoTree(a1, v10);
  if ( v11 == -1073740946 )
    PipSetDevNodeProblem(v10, 49, -1073740946);
  return v12;
}
