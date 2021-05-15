// ExpQueryMemoryTopologyInformation 
 
int __fastcall ExpQueryMemoryTopologyInformation(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r4
  unsigned int v11; // [sp+0h] [bp-20h] BYREF
  int v12[7]; // [sp+4h] [bp-1Ch] BYREF

  v12[0] = (int)a3;
  v12[1] = a4;
  v7 = MmGetNodeChannelRanges(&v11, v12);
  if ( v7 >= 0 )
  {
    v8 = v12[0];
    *a3 = v12[0];
    if ( v8 <= a2 )
    {
      v9 = v11;
      memmove(a1, v11, v8);
      v7 = 0;
      goto LABEL_6;
    }
    v7 = -1073741789;
  }
  v9 = v11;
LABEL_6:
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v7;
}
