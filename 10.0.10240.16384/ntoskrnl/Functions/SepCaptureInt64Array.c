// SepCaptureInt64Array 
 
int __fastcall SepCaptureInt64Array(unsigned int a1, unsigned int a2, int a3, int *a4)
{
  int v6; // r4
  unsigned int v7; // r8
  int v8; // r0
  int v9; // r5
  int var20[14]; // [sp+0h] [bp-20h] BYREF

  var20[10] = a1;
  var20[11] = a2;
  var20[12] = a3;
  var20[1] = (int)a4;
  var20[13] = (int)a4;
  var20[0] = 0;
  v6 = RtlULongLongToULong(8 * a2, a2 >> 29, var20);
  if ( v6 >= 0 )
  {
    v7 = var20[0];
    v8 = ExAllocatePoolWithTag(1, var20[0], 1950442835);
    v9 = v8;
    var20[0] = v8;
    if ( v8 )
    {
      if ( v7 )
      {
        if ( (a1 & 7) != 0 )
          ExRaiseDatatypeMisalignment(v8);
        if ( v7 + a1 > MmUserProbeAddress || v7 + a1 < a1 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      memmove(v8, a1, v7);
      *a4 = v9;
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
