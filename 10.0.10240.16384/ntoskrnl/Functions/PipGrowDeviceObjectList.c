// PipGrowDeviceObjectList 
 
int __fastcall PipGrowDeviceObjectList(unsigned int **a1)
{
  unsigned int *v2; // r4
  _DWORD *v3; // r3
  int result; // r0
  unsigned int i; // r5
  _DWORD *v6; // [sp+8h] [bp-20h] BYREF
  int v7; // [sp+Ch] [bp-1Ch] BYREF
  int v8; // [sp+10h] [bp-18h] BYREF
  unsigned int v9[5]; // [sp+14h] [bp-14h] BYREF

  v2 = *a1;
  v8 = 0;
  v9[0] = 0;
  v6 = 0;
  v7 = 0;
  v3 = PiAllocateDeviceObjectList(v2[3], 2 * v2[1]);
  v6 = v3;
  if ( v3 )
  {
    for ( i = 0; i < *v2; ++i )
    {
      PipDeviceObjectListElementAt(v2, i, v9, &v8, &v7);
      PipDeviceObjectListAdd((int)&v6, v9[0], v8, v7);
    }
    PipFreeDeviceObjectList((unsigned int)v2);
    v3 = v6;
    result = 0;
  }
  else
  {
    result = -1073741670;
  }
  *a1 = v3;
  return result;
}
