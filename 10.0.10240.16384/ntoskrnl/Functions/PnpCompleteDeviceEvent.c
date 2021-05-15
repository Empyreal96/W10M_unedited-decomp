// PnpCompleteDeviceEvent 
 
int __fastcall PnpCompleteDeviceEvent(unsigned int a1, int a2, int a3, unsigned int a4)
{
  unsigned int *v6; // r6
  unsigned int v7; // r2
  int result; // r0
  int v9; // r3
  _DWORD *v10; // r2
  void (__fastcall *v11)(_DWORD); // r3
  int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int v22[6]; // [sp+0h] [bp-18h] BYREF

  v22[2] = a4;
  v22[0] = -1000000;
  v22[1] = -1;
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 36);
  do
    v7 = __ldrex(v6);
  while ( __strex(1u, v6) );
  __dmb(0xBu);
  if ( v7 )
    return sub_7C93C4();
  if ( *(_DWORD *)(a1 + 44) )
  {
    __dmb(0xBu);
    v15 = (unsigned int *)(*(_DWORD *)(a1 + 44) + 36);
    do
      v16 = __ldrex(v15);
    while ( __strex(1u, v15) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !v16 )
        break;
      KeDelayExecutionThread(0, 0, v22);
      __dmb(0xBu);
      v20 = (unsigned int *)(*(_DWORD *)(a1 + 44) + 36);
      do
        v16 = __ldrex(v20);
      while ( __strex(1u, v20) );
    }
  }
  if ( *(_BYTE *)(a1 + 40) || (v9 = *(_DWORD *)(a1 + 44)) != 0 && *(_BYTE *)(v9 + 40) )
  {
    v21 = *(_DWORD *)(a1 + 24);
    if ( v21 )
      ExFreePoolWithTag(v21);
  }
  else
  {
    if ( *(_DWORD *)(a1 + 12) )
    {
      **(_DWORD **)(a1 + 84) = a2;
      KeSetEvent(*(_DWORD *)(a1 + 12), 0, 0);
    }
    else
    {
      v10 = *(_DWORD **)(a1 + 84);
      if ( v10 && *(_DWORD *)(a1 + 80) == 1 )
        *v10 = a2;
    }
    v11 = *(void (__fastcall **)(_DWORD))(a1 + 16);
    if ( v11 )
      v11(*(_DWORD *)(a1 + 20));
  }
  v12 = *(_DWORD *)(a1 + 96);
  if ( v12 )
    ObfDereferenceObject(v12);
  if ( *(_DWORD *)(a1 + 44) )
  {
    __dmb(0xBu);
    v17 = (unsigned int *)(*(_DWORD *)(a1 + 44) + 32);
    do
    {
      v18 = __ldrex(v17);
      v19 = v18 - 1;
    }
    while ( __strex(v19, v17) );
    __dmb(0xBu);
    if ( !v19 )
      ExFreePoolWithTag(*(_DWORD *)(a1 + 44));
  }
  __dmb(0xBu);
  v13 = (unsigned int *)(a1 + 32);
  do
  {
    v14 = __ldrex(v13);
    result = v14 - 1;
  }
  while ( __strex(result, v13) );
  __dmb(0xBu);
  if ( !result )
    result = ExFreePoolWithTag(a1);
  return result;
}
