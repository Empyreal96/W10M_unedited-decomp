// MmPerfLogSessionRundown 
 
int __fastcall MmPerfLogSessionRundown(int a1, int a2)
{
  int v3; // r4
  int v4; // r3
  int v5; // r5
  _DWORD v7[2]; // [sp+8h] [bp-28h] BYREF
  int v8[8]; // [sp+10h] [bp-20h] BYREF

  if ( a2 )
    v3 = 589;
  else
    v3 = 588;
  v8[0] = (int)v7;
  v8[1] = 0;
  v8[2] = 8;
  v8[3] = 0;
  while ( 1 )
  {
    v5 = MmGetNextSession();
    if ( !v5 )
      break;
    v4 = *(_DWORD *)(*(_DWORD *)(v5 + 324) + 8);
    v7[0] = *(_DWORD *)(v5 + 324);
    v7[1] = v4;
    EtwpLogKernelEvent(v8, a1, 1, v3, 4200451);
  }
  return 0;
}
