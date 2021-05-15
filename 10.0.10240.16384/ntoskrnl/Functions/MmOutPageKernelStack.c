// MmOutPageKernelStack 
 
int __fastcall MmOutPageKernelStack(int result)
{
  int v1; // [sp+0h] [bp-A8h] BYREF
  char v2; // [sp+4h] [bp-A4h]
  char v3; // [sp+5h] [bp-A3h]
  int v4; // [sp+8h] [bp-A0h]
  int v5; // [sp+Ch] [bp-9Ch]
  int v6; // [sp+10h] [bp-98h]
  int v7; // [sp+14h] [bp-94h]

  if ( (MiFlags & 0x40) != 0 )
  {
    v5 = 0;
    v6 = 0;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = 33;
    v7 = 0;
    KeEnumerateKernelStackSegments(result, MiOutPageSingleKernelStack, &v1);
    result = MiFlushTbList(&v1);
  }
  return result;
}
