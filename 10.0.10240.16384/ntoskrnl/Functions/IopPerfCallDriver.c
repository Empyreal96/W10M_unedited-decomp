// IopPerfCallDriver 
 
int __fastcall IopPerfCallDriver(int a1, int a2)
{
  int v4; // r0
  unsigned int v5; // r7
  unsigned int v6; // r7
  int v7; // r1
  int v8; // r3
  unsigned __int8 *v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r3
  unsigned __int8 *v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r0

  if ( (IopPerfStatus & 2) != 0 )
  {
    if ( IopIrpHasValidCombinationOfExtensionTypes(a2, 1) )
    {
      v4 = IopAllocateIrpExtension(a2, a2);
      if ( v4 )
        KeQuerySystemTime((_DWORD *)(v4 + 28));
    }
  }
  if ( (IopPerfStatus & 1) != 0 )
  {
    ObfReferenceObjectWithTag(a1);
    __dmb(0xBu);
    do
    {
      v5 = __ldrex(&IopPerfDriverUniqueMatchId);
      v6 = v5 + 1;
    }
    while ( __strex(v6, &IopPerfDriverUniqueMatchId) );
    __dmb(0xBu);
    IopPerfLogCallEvent(*(_DWORD *)(a1 + 8), a2, v6);
    v8 = (char)(*(_BYTE *)(a2 + 35) - 1);
    *(_BYTE *)(a2 + 35) = v8;
    if ( v8 <= 0 )
      KeBugCheckEx(53, a2, 0, 0, 0);
    v9 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
    *(_DWORD *)(a2 + 96) = v9;
    v10 = *v9;
    *((_DWORD *)v9 + 6) = a1;
    if ( v10 == 22 && ((v11 = v9[1], v11 == 2) || v11 == 3) )
      v12 = IopPoHandleIrp(a2, v7, 22, v11);
    else
      v12 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v10 + 56))(a1, a2);
    v13 = v12;
    IopPerfLogCallReturnEvent(a2, v6);
    ObfDereferenceObjectWithTag(a1);
  }
  else
  {
    v14 = (char)(*(_BYTE *)(a2 + 35) - 1);
    *(_BYTE *)(a2 + 35) = v14;
    if ( v14 <= 0 )
      KeBugCheckEx(53, a2, 0, 0, 0);
    v15 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
    *(_DWORD *)(a2 + 96) = v15;
    v16 = *v15;
    *((_DWORD *)v15 + 6) = a1;
    if ( v16 == 22 && ((v17 = v15[1], v17 == 2) || v17 == 3) )
      v18 = IopPoHandleIrp(a2, a2, 22, v17);
    else
      v18 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v16 + 56))(a1, a2);
    v13 = v18;
  }
  return v13;
}
