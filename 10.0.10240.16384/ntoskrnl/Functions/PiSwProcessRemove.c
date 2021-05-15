// PiSwProcessRemove 
 
int __fastcall PiSwProcessRemove(int result, int a2)
{
  int *v2; // r4
  int v4; // r3
  int v5; // [sp+0h] [bp-10h]

  v2 = *(int **)(result + 40);
  v5 = *v2;
  v4 = v2[1];
  if ( (v4 & 0x20) == 0 )
  {
    if ( (v4 & 1) != 0 )
    {
      v2[1] = v4 & 0xFFFFFFFE;
      result = PiSwDeviceInterfacesUpdateState(v5, 0);
    }
    if ( !a2 )
      result = sub_7EBB0C(result);
  }
  return result;
}
