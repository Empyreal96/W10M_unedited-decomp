// IoQueryFileDosDeviceName 
 
int __fastcall IoQueryFileDosDeviceName(_DWORD *a1, int *a2)
{
  unsigned int v4; // r4
  int v5; // r1
  int v6; // r5
  int v7; // r4
  unsigned int v9[8]; // [sp+10h] [bp-20h] BYREF

  v4 = 200;
  v9[0] = 200;
  v6 = ExAllocatePoolWithTag(1, 200, 1849978697);
  if ( !v6 )
    return -1073741670;
  while ( 1 )
  {
    v7 = IopQueryNameInternal(a1, v5, 1, v6, v4, v9, 0);
    if ( !v7 )
      break;
    ExFreePoolWithTag(v6);
    if ( v7 != -2147483643 )
      return v7;
    v4 = v9[0];
    v6 = ExAllocatePoolWithTag(1, v9[0], 1849978697);
    if ( !v6 )
      return -1073741670;
  }
  *a2 = v6;
  return v7;
}
