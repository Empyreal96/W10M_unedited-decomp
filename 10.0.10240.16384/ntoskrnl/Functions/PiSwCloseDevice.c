// PiSwCloseDevice 
 
unsigned int *__fastcall PiSwCloseDevice(unsigned int *a1, unsigned int *a2, int a3)
{
  unsigned int *result; // r0
  int v4; // r4
  int v5; // r3
  unsigned int *vars8[2]; // [sp+10h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  if ( a1[12] )
  {
    PiSwQueuedCreateInfoFree(a1[12]);
    a3 = 0;
    vars8[0][12] = 0;
    a1 = vars8[0];
  }
  if ( a1[16] )
  {
    a1[1] |= 2u;
    result = (unsigned int *)PnpDeviceObjectFromDeviceInstance(vars8[0][15]);
    v4 = (int)result;
    if ( result )
    {
      IoInvalidateDeviceRelations((int)result, 5);
      result = (unsigned int *)ObfDereferenceObject(v4);
    }
  }
  else
  {
    v5 = a1[15];
    if ( v5 )
      PiSwBusRelationRemove((int)a1);
    RtlDeleteElementGenericTableAvl((int)&PiSwDeviceInstanceTable, (int)vars8, a3, v5);
    result = PiSwDeviceDereference(vars8[0]);
  }
  return result;
}
