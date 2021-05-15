// IopInsertLegacyBusDeviceNode 
 
int __fastcall IopInsertLegacyBusDeviceNode(int result, unsigned int a2, unsigned int a3)
{
  int v3; // r4
  int v5; // r6
  unsigned int v6; // r1
  _DWORD *v7; // r2
  _DWORD *i; // r1
  unsigned int v9; // r3
  int v10; // r3
  unsigned int v11; // r1
  __int16 v12; // r3

  v3 = a2;
  v5 = result;
  if ( a2 <= 0x11 && a2 != 15 )
  {
    if ( a2 == 2 )
      v3 = 1;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
    v7 = (_DWORD *)((char *)&IopLegacyBusInformationTable + 8 * v3);
    for ( i = (_DWORD *)*v7; i != v7; i = (_DWORD *)*i )
    {
      v9 = *(i - 24);
      if ( v9 == a3 )
        goto LABEL_11;
      if ( v9 > a3 )
        break;
    }
    v10 = i[1];
    *(_DWORD *)(v5 + 400) = i;
    *(_DWORD *)(v5 + 404) = v10;
    *(_DWORD *)i[1] = v5 + 400;
    i[1] = v5 + 400;
LABEL_11:
    result = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
