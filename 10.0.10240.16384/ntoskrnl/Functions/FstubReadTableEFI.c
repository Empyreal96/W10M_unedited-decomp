// FstubReadTableEFI 
 
int __fastcall FstubReadTableEFI(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v6; // r9
  int v7; // r10
  int v8; // r4
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  int v12; // r4
  int v14; // [sp+8h] [bp-28h]
  int v15; // [sp+Ch] [bp-24h]

  if ( a3 )
    *a3 = 0;
  v6 = a2[21];
  v7 = a2[20];
  v8 = a1[1];
  v14 = v8 + v6 * v7 - 1;
  v15 = v8 - 1;
  v9 = ExAllocatePoolWithTag(512, v14 & ~(v8 - 1));
  v10 = v9;
  if ( !v9 )
    return -1073741670;
  v11 = a1[1];
  if ( !v11 )
    __brkdiv0();
  v12 = FstubReadSectors(*a1, v11, a2[18], a2[19], (v14 & (unsigned int)~v15) / v11, v9);
  if ( v12 >= 0 )
  {
    if ( a2[22] == RtlComputeCrc32(0, v10, v6 * v7) )
    {
      if ( a3 )
      {
        *a3 = v10;
        v10 = 0;
      }
    }
    else
    {
      v12 = -1073741774;
    }
  }
  if ( v10 )
    return sub_550554();
  return v12;
}
