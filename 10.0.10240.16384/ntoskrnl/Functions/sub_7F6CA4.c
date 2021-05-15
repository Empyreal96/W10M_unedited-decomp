// sub_7F6CA4 
 
void sub_7F6CA4()
{
  _DWORD *v0; // r0
  int v1; // r0
  int v2; // r3
  unsigned int v3; // r6
  unsigned int v4; // r4
  int v5; // r5

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  if ( (v3 & 0xFC000000) != 0 )
  {
    if ( AlpcpSecondaryMessageTables )
      v5 = *(_DWORD *)(AlpcpSecondaryMessageTables + 4 * (v3 >> 26));
    else
      v5 = 0;
  }
  else
  {
    v5 = AlpcMessageTable;
  }
  __mrc(15, 0, 13, 0, 3);
  v0 = ExMapHandleToPointerEx(v5, v3);
  v1 = ExDestroyHandle(v5, v3 & 0x3FFFFFF, v0);
  v2 = (__int16)(*(_WORD *)(v4 + 308) + 1);
  *(_WORD *)(v4 + 308) = v2;
  if ( !v2 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v1);
  JUMPOUT(0x71B436);
}
