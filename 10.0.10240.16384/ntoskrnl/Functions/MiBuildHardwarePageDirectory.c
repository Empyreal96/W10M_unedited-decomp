// MiBuildHardwarePageDirectory 
 
int __fastcall MiBuildHardwarePageDirectory(int result, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v3; // r8
  int *v4; // r6
  _DWORD *v5; // r4
  __int16 v6; // r2
  int v7; // t1

  v2 = 1024;
  v3 = a2;
  v4 = (int *)result;
  v5 = a2;
  do
  {
    v7 = *v4++;
    v6 = v7;
    if ( (v7 & 2) != 0 )
    {
      if ( (v6 & 0x400) != 0 )
        result = MiArmWriteLargePageHardwarePde(v3, v5);
      else
        result = MiArmWriteSimpleHardwarePde(v3, v5);
    }
    else
    {
      *v5 = 0;
      v5[1] = 0;
      v5[2] = 0;
      v5[3] = 0;
    }
    v5 += 4;
    --v2;
  }
  while ( v2 );
  return result;
}
