// PopBatteryInitialize 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopBatteryInitialize(int *a1)
{
  int v2; // r0
  int result; // r0
  char *v4; // r2
  char *v5; // r1
  char v6; // t1
  int *v7; // r0
  int **v8; // r4 OVERLAPPED
  int *v9; // r3
  int v10[10]; // [sp+28h] [bp-38h] BYREF
  char v11; // [sp+50h] [bp-10h] BYREF
  char v12; // [sp+54h] [bp-Ch] BYREF

  memset(v10, 0, 36);
  v2 = a1[7];
  v10[0] = a1[15];
  v10[1] = 0;
  PopPrepareIoctl(v2, 2703428, 0, (int)v10, 12, 36);
  result = IoSynchronousCallDriver(a1[6], a1[7]);
  if ( result >= 0 )
  {
    memmove((int)(a1 + 16), (int)v10, 0x24u);
    v4 = &v11;
    v5 = (char *)(a1 + 18);
    do
    {
      v6 = *v5++;
      *v4++ = v6;
    }
    while ( v4 != &v12 );
    v12 = 0;
    DbgPrintEx(
      146,
      2,
      (int)"\n"
           "Battery Information [%p]\n"
           "|-- Tag                 = %u\n"
           "|-- Capabilities        = 0x%08x\n"
           "|-- Technology          = %s\n"
           "|-- Chemistry           = %s\n"
           "|-- DesignedCapacity    = %u\n"
           "|-- FullChargedCapacity = %u\n"
           "|-- DefaultAlert1       = %u\n"
           "|-- DefaultAlert2       = %u\n"
           "|-- CriticalBias        = %u\n"
           "|-- CycleCount          = %u\n",
      (int)a1);
    a1[14] = 3;
    v7 = a1 + 8;
    v8 = (int **)dword_61ED80;
    v9 = &dword_61ED7C;
    *(_QWORD *)v7 = *(_QWORD *)(&v8 - 1);
    if ( *v8 != &dword_61ED7C )
      sub_81B17C();
    *v8 = v7;
    dword_61ED80 = (int)v7;
    byte_61ED70 = 1;
    ++dword_61ED6C;
    ++dword_61EDBC;
    result = 0;
  }
  return result;
}
