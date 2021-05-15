// EtwpCaptureRegistryData 
 
int __fastcall EtwpCaptureRegistryData(int *a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r4
  int *v6; // r6
  int v7; // r5
  int v8; // r0
  int varg_r1; // [sp+24h] [bp+Ch]
  unsigned int varg_r2; // [sp+28h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a3;
  v6 = a1;
  v7 = 0;
  if ( a3 )
  {
    if ( a3 > 0x800 )
      v4 = 2048;
    v8 = ExAllocatePoolWithTag(1, v4, 829912133);
    v7 = v8;
    if ( v8 )
      memmove(v8, a2, v4);
    else
      LOWORD(v4) = 0;
  }
  *v6 = v7;
  return (unsigned __int16)v4;
}
