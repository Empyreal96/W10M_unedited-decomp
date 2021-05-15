// PiGetRelatedDevice 
 
int __fastcall PiGetRelatedDevice(int a1, int a2, unsigned int *a3, int a4)
{
  int v8; // r5
  int v9; // r0
  int v10; // r7
  int v11; // r4
  int v12; // r2
  int v14; // r4
  unsigned int v15; // r6

  v8 = 0;
  PpDevNodeLockTree(0, a2);
  v9 = PnpDeviceObjectFromDeviceInstance(a1);
  v10 = v9;
  if ( !v9 )
    goto LABEL_13;
  v11 = *(_DWORD *)(*(_DWORD *)(v9 + 176) + 20);
  if ( !v11 )
    goto LABEL_13;
  v12 = *(_DWORD *)(v11 + 172);
  if ( v12 == 788 || v12 == 787 )
    goto LABEL_13;
  if ( a4 != 1 )
    return sub_7EEBA0();
  v14 = *(_DWORD *)(v11 + 8);
  if ( v14 )
  {
    v15 = *(unsigned __int16 *)(v14 + 20);
    if ( *a3 <= v15 )
    {
      v8 = -1073741789;
      *a3 = v15 + 2;
    }
    else
    {
      memmove(a2, *(_DWORD *)(v14 + 24), *(unsigned __int16 *)(v14 + 20));
      *(_WORD *)(v15 + a2) = 0;
      *a3 = v15;
    }
  }
  else
  {
LABEL_13:
    v8 = -1073741810;
  }
  PpDevNodeUnlockTree(0);
  if ( v10 )
    ObfDereferenceObject(v10);
  return v8;
}
