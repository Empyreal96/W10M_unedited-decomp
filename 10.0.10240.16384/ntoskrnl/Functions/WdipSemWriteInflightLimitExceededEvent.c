// WdipSemWriteInflightLimitExceededEvent 
 
int __fastcall WdipSemWriteInflightLimitExceededEvent(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  unsigned int v7; // r1
  char *v8; // r2
  int v9; // t1
  char v10; // [sp+38h] [bp-7E0h] BYREF
  int varg_r0; // [sp+820h] [bp+8h]
  int varg_r1; // [sp+824h] [bp+Ch]
  int varg_r2; // [sp+828h] [bp+10h]
  int varg_r3; // [sp+82Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (int *)a4;
  if ( !a1 )
    return -1073741811;
  if ( !a3 )
    return -1073741811;
  if ( !a4 )
    return -1073741811;
  v7 = *(_DWORD *)(a4 + 500);
  if ( v7 > 0x7D )
    return -1073741811;
  if ( v7 )
  {
    v8 = &v10;
    do
    {
      v9 = *v4++;
      *(_DWORD *)v8 = v9;
      *((_DWORD *)v8 + 1) = 0;
      *((_DWORD *)v8 + 2) = 24;
      *((_DWORD *)v8 + 3) = 0;
      v8 += 16;
      --v7;
    }
    while ( v7 );
  }
  return WdipSemWriteEvent(WdipSemRegHandle, dword_61CB14, (int)WDI_SEM_EVENT_SCENARIO_INFLIGHT_MAX, a3);
}
