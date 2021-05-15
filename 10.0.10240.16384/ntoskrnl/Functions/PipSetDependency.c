// PipSetDependency 
 
int __fastcall PipSetDependency(int a1, int a2)
{
  int v4; // r0
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r5

  v4 = PipQueryBindingResolution(a1);
  v5 = v4;
  if ( v4 )
  {
    ++*(_DWORD *)(v4 + 44);
  }
  else
  {
    v5 = PipCreateDependencyNode(a1);
    if ( !v5 )
      return -1073741670;
  }
  v6 = PipQueryBindingResolution(a2);
  v7 = v6;
  if ( v6 )
  {
    ++*(_DWORD *)(v6 + 44);
LABEL_5:
    v8 = PipAddDependencyEdgeBetweenNodes(v5, v7, a2);
    goto LABEL_6;
  }
  v7 = PipCreateDependencyNode(a2);
  if ( v7 )
    goto LABEL_5;
  v8 = -1073741670;
LABEL_6:
  PipDereferenceDependencyNode(v5);
  if ( v7 )
    PipDereferenceDependencyNode(v7);
  return v8;
}
