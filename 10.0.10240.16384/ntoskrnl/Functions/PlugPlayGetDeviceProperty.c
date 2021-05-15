// PlugPlayGetDeviceProperty 
 
int __fastcall PlugPlayGetDeviceProperty(int *a1, int a2, int a3, unsigned int a4, int *a5, int a6)
{
  int v10; // r0
  int v11; // r4
  int v12; // r3
  int v14[5]; // [sp+0h] [bp-28h] BYREF

  if ( !a1 || !a5 || a6 )
    return -1073741811;
  memset(v14, 0, sizeof(v14));
  v14[0] = *a1;
  v14[1] = a1[1];
  v14[2] = a2;
  v14[3] = a3;
  v14[4] = a4;
  v10 = ZwPlugPlayControl();
  v11 = v10;
  if ( v10 < 0 )
  {
    if ( v10 != -1073741789 )
    {
      v12 = 0;
      goto LABEL_6;
    }
    goto LABEL_9;
  }
  v12 = v14[4];
  if ( a4 > v14[4] )
  {
    memset((_BYTE *)(v14[4] + a3), 0, a4 - v14[4]);
LABEL_9:
    v12 = v14[4];
  }
LABEL_6:
  *a5 = v12;
  return v11;
}
