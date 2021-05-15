// PopFxDestroyDeviceDpm 
 
int __fastcall PopFxDestroyDeviceDpm(int a1, _DWORD *a2)
{
  int v4; // r0
  int v5; // r0
  int result; // r0
  unsigned int i; // r6
  int v8; // r7
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1

  v4 = a2[14];
  if ( v4 )
    ObfDereferenceObjectWithTag(v4);
  v5 = a2[13];
  if ( v5 )
    ObfDereferenceObjectWithTag(v5);
  if ( a1 )
    ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 16));
  result = a2[2];
  if ( result )
    result = pIoFreeIrp(result);
  if ( a2[98] )
  {
    for ( i = 0; i < a2[97]; ++i )
    {
      v8 = *(_DWORD *)(a2[98] + 4 * i);
      v9 = *(_DWORD *)(v8 + 184);
      if ( v9 )
      {
        ExFreePoolWithTag(v9);
        *(_DWORD *)(v8 + 184) = 0;
      }
    }
    result = ExFreePoolWithTag(a2[98]);
    a2[98] = 0;
  }
  a2[8] = 0;
  a2[9] = 0;
  a2[10] = 0;
  if ( (*(_DWORD *)(a1 + 168) & 0x4000) == 0 )
    return PopFxDestroyDeviceCommon((int)a2);
  __dmb(0xBu);
  v10 = a2 + 34;
  do
  {
    v11 = __ldrex(v10);
    v12 = v11 - 1;
  }
  while ( __strex(v12, v10) );
  __dmb(0xBu);
  if ( !v12 )
    result = KeSetEvent((int)(a2 + 35), 0, 0);
  *(_DWORD *)(a1 + 168) &= 0xFFFFBFFF;
  return result;
}
