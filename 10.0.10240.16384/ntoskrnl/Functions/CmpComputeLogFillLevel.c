// CmpComputeLogFillLevel 
 
int __fastcall CmpComputeLogFillLevel(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v7; // r6
  int v11; // r0
  unsigned int v12; // r4
  unsigned __int64 v13; // r2
  unsigned __int64 v15; // [sp+8h] [bp-B0h] BYREF
  unsigned int v16; // [sp+10h] [bp-A8h]
  int *v17; // [sp+14h] [bp-A4h]
  int v18; // [sp+18h] [bp-A0h] BYREF
  int v19; // [sp+1Ch] [bp-9Ch] BYREF
  __int64 v20[19]; // [sp+20h] [bp-98h] BYREF

  v17 = a6;
  v15 = 0i64;
  v7 = -1073741267;
  v16 = (1374389535 * (unsigned __int64)(unsigned int)(a4 * a5)) >> 32;
  if ( !ClfsLsnInvalid(a2) && !ClfsLsnInvalid(a3) && !ClfsLsnEqual(a2, a3) )
    v7 = ClfsLsnDifference(a2, a3, a4, 4096, &v15);
  v19 = 120;
  v11 = ExAllocatePoolWithTag(1, 120, 538987843);
  v12 = v11;
  if ( v11 )
  {
    ClfsGetLogFileInformation(a1, v11, &v19);
    ExFreePoolWithTag(v12);
  }
  if ( v7 >= 0 )
  {
    v13 = v15;
  }
  else
  {
    v18 = 120;
    v7 = ClfsGetLogFileInformation(a1, v20, &v18);
    if ( v7 < 0 )
      return v7;
    v13 = v20[0] - v20[1];
  }
  if ( !(v16 >> 5) )
    __brkdiv0();
  *v17 = _rt_udiv64(v16 >> 5, v13);
  return v7;
}
