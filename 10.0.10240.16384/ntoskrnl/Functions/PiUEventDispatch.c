// PiUEventDispatch 
 
int __fastcall PiUEventDispatch(int a1, int a2)
{
  int v2; // r4
  int v3; // r5
  unsigned __int8 *v4; // r7
  int v5; // r3
  int v6; // r0
  int v8; // r0

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 24);
  v4 = *(unsigned __int8 **)(a2 + 96);
  if ( v3 < 0 )
    return v3;
  v5 = *v4;
  if ( !*v4 )
  {
    *(_DWORD *)(*((_DWORD *)v4 + 7) + 16) = 0;
LABEL_7:
    v6 = v2;
    *(_DWORD *)(v2 + 24) = 0;
LABEL_8:
    IofCompleteRequest(v6, 0);
    return v3;
  }
  if ( v5 == 2 )
  {
    v8 = *(_DWORD *)(*((_DWORD *)v4 + 7) + 16);
    if ( v8 )
    {
      PiUEventFreeClientRegistrationContext(v8, 1);
      *(_DWORD *)(*((_DWORD *)v4 + 7) + 16) = 0;
    }
    v3 = 0;
    goto LABEL_7;
  }
  v6 = a2;
  if ( v5 == 14 )
    return PiUEventHandleIoctl(a2);
  if ( v5 == 18 )
  {
    *(_DWORD *)(a2 + 24) = 0;
    goto LABEL_8;
  }
  return sub_7C2418(a2);
}
