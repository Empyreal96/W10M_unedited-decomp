// EtwpClockSourceRunDown 
 
int __fastcall EtwpClockSourceRunDown(int result, int a2)
{
  int v2; // r4
  int v3; // r0
  int v4[4]; // [sp+8h] [bp-48h] BYREF
  char v5[4]; // [sp+18h] [bp-38h] BYREF
  int v6; // [sp+1Ch] [bp-34h]
  int v7; // [sp+20h] [bp-30h]
  int v8[6]; // [sp+38h] [bp-18h] BYREF

  v2 = result;
  if ( a2 )
  {
    off_617AE0(v5);
    v4[0] = v6;
    v4[1] = v7;
    v3 = KeGetDynamicTickDisableReason();
    v8[0] = (int)v4;
    v8[1] = 0;
    v8[2] = 12;
    v8[3] = 0;
    v4[2] = v3;
    result = EtwpLogKernelEvent(v8, v2, 1, 3930, 4200450);
  }
  return result;
}
