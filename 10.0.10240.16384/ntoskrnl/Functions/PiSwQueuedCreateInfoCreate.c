// PiSwQueuedCreateInfoCreate 
 
int __fastcall PiSwQueuedCreateInfoCreate(int **a1, int a2)
{
  int *v4; // r0
  int v5; // r4
  int v6; // r0

  v4 = (int *)ExAllocatePoolWithTag(1, 40, 1466986064);
  *a1 = v4;
  if ( !v4 )
  {
    v5 = -1073741670;
    goto LABEL_10;
  }
  memset(v4, 0, 40);
  v5 = PnpAllocatePWSTR(*(unsigned __int16 **)(a2 + 4), 0xC8u, 1466986064, *a1);
  if ( v5 >= 0 )
  {
    v5 = PiSwPnPInfoInit(*a1 + 1, a2);
    if ( v5 >= 0 )
    {
      if ( *(_DWORD *)(a2 + 48) )
      {
        (*a1)[7] = ExAllocatePoolWithTag(1, *(_DWORD *)(a2 + 44), 1466986064);
        v6 = (*a1)[7];
        if ( !v6 )
        {
          v5 = -1073741670;
          goto LABEL_11;
        }
        memmove(v6, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 44));
      }
      v5 = PnpCopyDevPropertyArray(*(_DWORD *)(a2 + 52), *(_DWORD *)(a2 + 56), (int)*a1, *a1 + 9, *a1 + 8);
LABEL_10:
      if ( v5 >= 0 )
        return v5;
      goto LABEL_11;
    }
  }
LABEL_11:
  if ( *a1 )
  {
    PiSwQueuedCreateInfoFree(*a1);
    *a1 = 0;
  }
  return v5;
}
