// IopQueryInterfaceRecurseUp 
 
int __fastcall IopQueryInterfaceRecurseUp(int a1, int a2, unsigned int a3, __int16 a4, int a5, int a6)
{
  __int16 v6; // r5
  int v8; // r0
  int v9; // r6
  _DWORD *v10; // r4
  int v11; // r5

  v6 = a4;
  PpDevNodeLockTree(0, a2);
  v8 = IoGetDeviceAttachmentBaseRef(a1);
  v9 = v8;
  if ( v8 )
    v10 = *(_DWORD **)(*(_DWORD *)(v8 + 176) + 20);
  else
    v10 = 0;
  if ( v10 == (_DWORD *)IopRootDeviceNode )
  {
LABEL_8:
    v11 = -1073741637;
  }
  else
  {
    while ( v10 && v10[43] != 788 )
    {
      v11 = PnpQueryInterface(v10[4], a2, v6, a3, a5, a6);
      if ( v11 != -1073741637 )
        goto LABEL_9;
      v10 = (_DWORD *)v10[2];
      v6 = a4;
      if ( v10 == (_DWORD *)IopRootDeviceNode )
        goto LABEL_8;
    }
    v11 = -1073741130;
  }
LABEL_9:
  ObfDereferenceObject(v9);
  PpDevNodeUnlockTree(0);
  return v11;
}
